#pragma once
#include "stdafx.h"
#include "gameNode.h"


class enemyManager;

class stage :
	public gameNode
{
private:

	image* _stageImage;

	enemyManager* _EnemyManager;

public:


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setEnemyManagerAddressLink(enemyManager* EnemyManager)
	{
		_EnemyManager = EnemyManager;
	}

	image* getStageImage() { return _stageImage; }

};

