#pragma once
#include "gameNode.h"
#include "player.h"

#include "Team_TestScene.h"



class playGround : public gameNode
{
private:
	char* _str;
	int _test;
	player * _player;
public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	
};

