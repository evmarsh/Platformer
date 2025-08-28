#include <iostream>
#include "raylib.h"

int main() {
	const int screenWidth = 800;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Example");

	Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
	Vector2 rectSize = { 20, 20 };

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
		if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
		if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
		if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("First Window", screenHeight / 2, screenWidth / 2, 20, LIGHTGRAY);
			DrawRectangleV(ballPosition, rectSize, MAROON);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}
