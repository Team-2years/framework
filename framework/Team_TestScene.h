#pragma once
#include "gameNode.h"
#include "stage.h"
#include "enemyManager.h"



class Team_TestScene :
	public gameNode
{
private:


	stage* _stage;
	enemyManager* _em;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void addImageList();

};

