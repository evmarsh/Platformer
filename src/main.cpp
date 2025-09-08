#include <iostream>
#include "raylib.h"
#include "Player.h"

bool checkCollision (float x1, float x2, float y1, float y2, float w1, float w2, float h1, float h2) {
	if (x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2) {
		return true;
	}

	return false;
}

int main() {
	const int screenWidth = 1024;
	const int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "Example");

	Player p({300, 0});
	p.SetIsFalling(true);

	Vector2 platform_size = {1024, 50};
	Vector2 platform_pos = {0, 700};

	int framesCounter = 0;

	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		const float max_frame_time = 0.1f;
		if (dt > max_frame_time) {
			dt = max_frame_time;
		} 

		if (IsKeyDown(KEY_RIGHT)) {
			if (p._sprite.name != "run") {
				p.SwapAnimations("run");
			}
			p.Move(dt);
		}
		if (IsKeyDown(KEY_LEFT)) {
			if (p._sprite.name != "run") {
				p.SwapAnimations("run");
			}
			p.Move(-dt);
		}
		if (IsKeyDown(KEY_UP) && !p.IsJumping()) { p.SetIsJumping(true); p.SetYSpeed(-p.GetJumpStrength()); }

		framesCounter++;

		p.AdvanceFrame(&framesCounter);

		if (p.IsJumping() && !p.IsFalling()) {
			p.Jump(dt);
		}

		if (p.IsFalling()) {
			p.Fall(dt);
		}

		BeginDrawing();
			ClearBackground(BLACK);

			DrawRectangleV(platform_pos, platform_size, GRAY);
			p.Draw();
		EndDrawing();

		if (checkCollision(p.GetPos().x, platform_pos.x, p.GetPos().y, platform_pos.y, p.GetSize().x, platform_size.x, p.GetSize().y, platform_size.y)) {
			p.SetIsFalling(false);
			p.SetIsJumping(false);
			p.SetYSpeed(0.0f);
			p.SetPos({p.GetPos().x, platform_pos.y - platform_size.y+12});
		}
	}

	p.DestroyTextures();

	CloseWindow();

	return 0;
}
