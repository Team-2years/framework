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

//�ʱ�ȭ�� ����� �ϼ��� ����
HRESULT playGround::init()
{
	gameNode::init(true);
	SCENEMANAGER->addScene("�׽�Ʈ��", new TestScene);
	SCENEMANAGER->changeScene("�׽�Ʈ��");
	return S_OK;
}

//�޸� ������ ����� �ϼ��� ����
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
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	
	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());
	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
