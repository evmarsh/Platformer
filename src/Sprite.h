#include <string>

typedef struct Sprite {
	std::string name;
	int numFrames;
	int currentFrame;
	int frameSpeed;
	int frameWidth;
	int frameHeight;
	Texture2D texture;
	Rectangle srcRec;
	Rectangle destRec;
	Vector2 origin;
} Sprite;
