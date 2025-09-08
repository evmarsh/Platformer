#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Sprite.h"
#include <string>
#include <vector>

class Player {
	public:
		Sprite* _sprite;
		std::vector<Sprite*> _animations;

		Player();
		Player(Vector2 pos);
		~Player();
		void DestroyTextures();
		void LoadAnimations();
		void SwapAnimations(std::string animation_name);
		Sprite* FindAnimation(std::string animation_name);
		void Move(float dt);
		void Jump(float dt);
		void AdvanceFrame(int* framesCounter);
		void Draw();
		bool IsFalling();
		bool IsJumping();
		void Fall(float dt);
		void SetIsFalling(bool value);
		void SetIsJumping(bool value);
		void SetYSpeed(float speed);
		float GetJumpStrength();
		Vector2 GetPos();
		void SetPos(Vector2 pos);
		Vector2 GetSize();
		
	private:
		Vector2 _pos;
		Vector2 _size;
		bool _is_falling;
		bool _is_jumping;
		int _hp;
		float _speed;
		float _y_speed;
		float _jump_strength;
		float _fall_speed;
		float _max_fall_speed;
		float _max_x_speed;
		float _x_acc;
		float _gravity;
};

#endif
