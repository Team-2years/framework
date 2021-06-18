#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 하세요 제발
HRESULT playGround::init()
{
	gameNode::init(true);
	
	//NAGER->addImage("배경", "background.bmp", 1200, 900, true, RGB(255, 0, 255));
	// = new player;
	//->init();


	SCENEMANAGER->addScene("테스트_형준", new Team_TestScene);

	SCENEMANAGER->changeScene("테스트_형준");

	return S_OK;
}

//메모리 해제는 여기다 하세요 제발
void playGround::release()
{
	gameNode::release();


	

}


void playGround::update()
{
	gameNode::update();

	//_player->update();


	SCENEMANAGER->update();
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================
	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//IMAGEMANAGER->findImage("배경")->render(getMemDC(),0,0);
	//_player->render();
	
	
	SCENEMANAGER->render();
	
	TIMEMANAGER->render(getMemDC());



	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
