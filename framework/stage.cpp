#include "stdafx.h"
#include "stage.h"
#include "enemyManager.h"

HRESULT stage::init()
{

	_stageImage = new image;

	_stageImage = IMAGEMANAGER->findImage("ÇÊµå");

	return S_OK;
}

void stage::release()
{
}

void stage::update()
{
}

void stage::render()
{
	_stageImage->render(getMemDC(), 0, 0);

}
