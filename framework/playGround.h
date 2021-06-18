#pragma once
#include "gameNode.h"




class playGround : public gameNode
{
private:
	char* _str;
	int _test;
	bool _direction;
	image* _player;
	int _state;
	bool _isMove;
	float _playerX, _playerY;
	float _playerZ;
	float _gravity;
	float _jumpPower;
	bool _isJump;
	int _probeY;
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

