#include "Player.h"

Player::Player()
: _pos ({300, 300}),
  _size ({50, 50}),
  _is_falling (false),
  _is_jumping (false),
  _hp (3),
  _speed (400.0f),
  _y_speed (0.0f),
  _jump_strength (600.0f),
  _fall_speed (0.0f),
  _max_fall_speed (5000.0f),
  _gravity (980.0f)
{ }

Player::Player (Vector2 pos)
: _pos (pos),
  _size ({50, 50}),
  _is_falling (false),
  _is_jumping (false),
  _hp (3),
  _speed (400.0f),
  _y_speed (0.0f),
  _jump_strength (600.0f),
  _fall_speed (0.0f),
  _max_fall_speed (5000.0f),
  _gravity (980.0f)
{ }

void Player::Move (float dt) {
	_pos.x += _speed * dt;
}

void Player::Jump (float dt) {
	_y_speed += _gravity * dt;
	_pos.y += _y_speed * dt;
}

void Player::Draw() {
	DrawRectangleV(_pos, _size, MAROON);
}

void Player::Fall (float dt) {
	if (_fall_speed < _max_fall_speed) {
		_fall_speed += _gravity * dt;
	}

	_pos.y += _fall_speed * dt;
}

bool Player::IsJumping() {
	return _is_jumping;
}

bool Player::IsFalling() {
	return _is_falling;
}

void Player::SetIsFalling (bool value) {
	_is_falling = value;
}

void Player::SetIsJumping (bool value) {
	_is_jumping = value;
}

void Player::SetYSpeed (float speed) {
	_y_speed = speed;
}

float Player::GetJumpStrength() {
	return _jump_strength;
}

Vector2 Player::GetPos() {
	return _pos;
}

void Player::SetPos (Vector2 pos) {
	_pos = pos;
}

Vector2 Player::GetSize() {
	return _size;
}
