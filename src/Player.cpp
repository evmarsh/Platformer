#include "Player.h"

//TODO: 
//	- Want to come back and redo x movement so it has acceleration. Make it more like Mario movement

Player::Player()
: _pos ({300, 300}),
  _size ({50, 50}),
  _is_falling (false),
  _is_jumping (false),
  _hp (3),
  _speed (400.0f),
  _y_speed (0.0f),
  _jump_strength (800.0f),
  _fall_speed (0.0f),
  _max_fall_speed (5000.0f),
  _x_acc (100.0f),
  _gravity (2000.0f)
{ }

Player::Player (Vector2 pos, int numFrames, std::string sprite_name, std::string location)
: _pos (pos),
  _size ({50, 50}),
  _is_falling (false),
  _is_jumping (false),
  _hp (3),
  _speed (400.0f),
  _y_speed (0.0f),
  _jump_strength (800.0f),
  _fall_speed (0.0f),
  _max_fall_speed (5000.0f),
  _max_x_speed (1000.0f),
  _x_acc (100.0f),
  _gravity (2000.0f)
{ 
	Sprite _sprite;
	_sprite.name = sprite_name;
	_sprite.numFrames = numFrames;
	_sprite.currentFrame = 0;
	_sprite.frameSpeed = 8;
	_sprite.texture = LoadTexture(location.c_str());
	_sprite.frameRec = { 0.0f, 0.0f, (float)_sprite.texture.width/_sprite.numFrames, (float)_sprite.texture.height };
}

Player::~Player() {
	UnloadTexture(_sprite.texture);
}

void Player::Move (float dt) {
	_pos.x += _speed * dt;
}

void Player::Jump (float dt) {
	_y_speed += _gravity * dt;
	_pos.y += _y_speed * dt;
}

void Player::AdvanceFrame(int* framesCounter) {
	if (*framesCounter >= (60/_sprite.frameSpeed)) {
		*framesCounter = 0;
		_sprite.currentFrame++;

		if (_sprite.currentFrame > 5) _sprite.currentFrame = 0;
		
		_sprite.frameRec.x = (float)_sprite.currentFrame*(float)_sprite.texture.width/8;
	}
}

void Player::Draw() {
	DrawTexture(_sprite.texture, 15, 40, WHITE);
}

void Player::DrawTexRec() {
	DrawTextureRec(_sprite.texture, _sprite.frameRec, _pos, WHITE);
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
