#include "stdafx.h"
#include "enemyManager.h"
#include "stage.h"

HRESULT enemyManager::init()
{

	setting_Unit(100, WINSIZEY - 100, "РЏДж");


	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (!_vEnemy.empty()) _vEnemy[i]->update(_stage->getStageImage());
	}

}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); i++) _vEnemy[i]->render();

}

void enemyManager::setting_Unit(int _x, int _y, const char * _imageName)
{
	Enemy_Basic* create_Enemy;

	create_Enemy = new Enemy_Basic;

	create_Enemy->init(_x, _y, _imageName);

	_vEnemy.push_back(create_Enemy);

}
