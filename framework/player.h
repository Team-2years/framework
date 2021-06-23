#pragma once
#include "gameNode.h"
#include "idleState.h"
class player : public gameNode
{
private:
	bool _direction;
	image* _player;
	state* _state;
	bool _isMove;
	float _x, _y, _z;
	float _gravity;
	float _jumpPower;
	bool _isJump;
	int _time;
	bool _cantMove;
	int _frameX;
	int _frameY;
	float _speed;
	int _moveCommandInput;
	int _attackCommandInput;
	int _comboCount;
public:

	HRESULT init();
	void release();
	void update();
	void render();
	void setX(float x) { _x = x; };
	void setY(float y) { _y = y; };
	void setZ(float z) { _z = z; };
	void setImage(image * image) { _player = image; };
	void setFrameX(int x) { _frameX = x; };
	void setFrameY(int y) { _frameY = y; };
	void setJumpPower(float power) { _jumpPower = power; };
	void setTime(int time) { _time = time; };
	void setSpeed(int speed) { _speed = speed; };
	void setMoveCommandInput(int input) { _moveCommandInput = input; };
	float getX() { return _x; };
	float getY() { return _y; };
	float getZ() { return _z; };
	int getTime() { return _time; };
	int getFrameX() { return _frameX; };
	int getFrameY() { return _frameY; };
	float getSpeed() { return _speed; };
	int getMoveCommandInput() { return _moveCommandInput; };
	image* getImage() { return _player; };
	void inputHandle();
};

