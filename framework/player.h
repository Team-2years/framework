#pragma once
#include "gameNode.h"
class player : public gameNode
{
private:

	bool _direction;
	image* _player;
	int _state;
	bool _isMove;
	float _x, _y,_z;
	float _gravity;
	float _jumpPower;
	bool _isJump;
	int _time;
	bool _cantMove;
	int _frameY;
public:

	HRESULT init();
	void release();
	void update();
	void render();
	void setX(float x) { _x = x; };
	void setY(float y) { _y = y; };
	void setZ(float z) { _z = z; };
	void setJumpPower(float power) { _jumpPower = power; };
	float getX() { return _x; };
	float getY() { return _y; };
	float getZ() { return _z; };
};

