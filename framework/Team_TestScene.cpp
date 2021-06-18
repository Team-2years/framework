#include "stdafx.h"
#include "Team_TestScene.h"

HRESULT Team_TestScene::init()
{
	addImageList();

	_stage = new stage;
	_stage->init();

	_em = new enemyManager;
	_em->init();

	_stage->setEnemyManagerAddressLink(_em);
	_em->setAddressLinkStage(_stage);


	return S_OK;
}

void Team_TestScene::release()
{
}

void Team_TestScene::update()
{


	_stage->update();
	_em->update();
}

void Team_TestScene::render()
{
	_stage->render();
	_em->render();


}

void Team_TestScene::addImageList()
{
	IMAGEMANAGER->addImage("ÇÊµå", "Image/Field.bmp", 1200, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("À¯´Ö", "Image/Unit.bmp", 492, 132, 12, 2, true, RGB(255, 0, 255));

}
