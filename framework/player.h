#pragma once
#include "gameNode.h"
class player : public gameNode
{
private:

	bool _direction;
	image* _player;
	int _state;
	bool _isMove;
	float _playerX, _playerY;
	float _playerZ;
	float _gravity;
	float _jumpPower;
	bool _isJump;
	int _time;
public:

	HRESULT init();
	void release();
	void update();
	void render();
};

