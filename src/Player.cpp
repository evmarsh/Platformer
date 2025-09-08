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

Player::Player (Vector2 pos)
: _pos (pos),
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
	_sprite.name = "idle";
	_sprite.numFrames = 7;
	_sprite.currentFrame = 0;
	_sprite.frameSpeed = 8;
	_sprite.texture = LoadTexture("resources/Sprites/with_outline/IDLE.png");
	_sprite.frameWidth = _sprite.texture.width / _sprite.numFrames;
	_sprite.frameHeight = _sprite.texture.height;
	_sprite.srcRec = { 0.0f, 0.0f, (float)_sprite.frameWidth, (float)_sprite.frameHeight };
	_sprite.destRec = { _pos.x, _pos.y, _sprite.frameWidth*2.0f, _sprite.frameHeight*2.0f };
	_sprite.origin = { (float)_sprite.frameWidth, (float)_sprite.frameHeight };

	_animations.push_back(_sprite);

	_size = { (float)_sprite.frameWidth, (float)_sprite.frameHeight };

	LoadAnimations();
}

Player::~Player() {
}

void Player::DestroyTextures() {
	UnloadTexture(_sprite.texture);
}

void Player::LoadAnimations() {
	// Load run animation
	Sprite run;
	run.name = "run";
	run.numFrames = 8;
	run.currentFrame = 0;
	run.frameSpeed = 8;
	run.texture = LoadTexture("resources/Sprites/with_outline/RUN.png");
	run.frameWidth = run.texture.width / run.numFrames;
	run.frameHeight = run.texture.height;
	run.srcRec = { 0.0f, 0.0f, (float)run.frameWidth, (float)run.frameHeight };
	run.destRec = { _pos.x, _pos.y, run.frameWidth*2.0f, run.frameHeight*2.0f };
	run.origin = { (float)run.frameWidth, (float)run.frameHeight };

	_animations.push_back(run);
}

void Player::Move (float dt) {
	_pos.x += _speed * dt;
}

void Player::Jump (float dt) {
	_y_speed += _gravity * dt;
	_pos.y += _y_speed * dt;
}

void Player::AdvanceFrame (int* framesCounter) {
	if (*framesCounter >= (60/_sprite.frameSpeed)) {
		*framesCounter = 0;
		_sprite.currentFrame++;

		if (_sprite.currentFrame > _sprite.numFrames-1) _sprite.currentFrame = 0;
		
		_sprite.srcRec.x = (float)_sprite.currentFrame*(float)_sprite.texture.width/_sprite.numFrames;
	}
}

void Player::SwapAnimations (std::string animation_name) {
	Sprite& animation = FindAnimation(animation_name);
	if (animation.name != _sprite.name) {
		_sprite.currentFrame = 0;

		_sprite = animation;
	}
}

Sprite& Player::FindAnimation (std::string animation_name) {
	for (auto it = _animations.begin(); it != _animations.end(); ++it) {
		if ((*it).name == animation_name) {
			return *it;
		}
	}

	return _sprite;
}

void Player::Draw() {
	_sprite.destRec.x = _pos.x;
	_sprite.destRec.y = _pos.y;
	DrawTexturePro(_sprite.texture, _sprite.srcRec, _sprite.destRec, _sprite.origin, 0.0f, WHITE);
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
