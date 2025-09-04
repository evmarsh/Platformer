#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
	public:
		Player();
		Player(Vector2 pos);
		void Move(float dt);
		void Jump(float dt);
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
		float _gravity;
};

#endif
