#pragma once
#include "gameNode.h"
#include "Enemy_Basic.h"


class stage;

class enemyManager :
	public gameNode
{
private:

	typedef vector<Enemy_Basic*> vEnemyVector;
	typedef vector<Enemy_Basic*>::iterator iter_vEnemyVector;

private:

	vEnemyVector _vEnemy;


	stage* _stage;

public:

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	void setting_Unit(int _x, int _y, const char* _imageName);


	void setAddressLinkStage(stage* stage)
	{
		_stage = stage;
	}

};

