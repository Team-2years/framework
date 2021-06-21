#pragma once
#include "gameNode.h"
#include "player.h"

class TestScene :
	public gameNode
{
private:
	image* _background;
	player* _player;
	tag_Player* _tagPlayer;
public:
	TestScene() {}
	~TestScene() {}

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void pixelCollision();
};

