#include "stdafx.h"
#include "playGround.h"


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
	
	//NAGER->addImage("���", "background.bmp", 1200, 900, true, RGB(255, 0, 255));
	// = new player;
	//->init();


	SCENEMANAGER->addScene("�׽�Ʈ_����", new Team_TestScene);

	SCENEMANAGER->changeScene("�׽�Ʈ_����");

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

	//_player->update();


	SCENEMANAGER->update();
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//IMAGEMANAGER->findImage("���")->render(getMemDC(),0,0);
	//_player->render();
	
	
	SCENEMANAGER->render();
	
	TIMEMANAGER->render(getMemDC());



	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
