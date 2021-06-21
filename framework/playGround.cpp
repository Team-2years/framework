#include "stdafx.h"
#include "playGround.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;


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
	SCENEMANAGER->addScene("테스트씬", new TestScene);
	SCENEMANAGER->changeScene("테스트씬");
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
	SCENEMANAGER->update();
	
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// 위에 건들지마라
	//================제발 이 사이에 좀 그립시다==========================
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	
	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	//==================================================
	//여기도 건들지마라
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
