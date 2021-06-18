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
	IMAGEMANAGER->addFrameImage("ĳ���͹���", "characterMove.bmp", 492, 132, 12, 2, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addImage("���", "background.bmp", 1200, 900, true, RGB(255, 0, 255));
	_player = IMAGEMANAGER->findImage("ĳ���͹���");
	_test = 0;
	_direction = false;
	_state = 0;
	_playerX = 400.0f;
	_playerY = 800.0f;
	_probeY = _playerY;
	_playerZ = 0.f;
	_gravity = 0.1f;
	_isMove = false;
	_isJump = false;
	_jumpPower = 0.f;
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

	_test++;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_direction = true;
		_player->setFrameY(1);
		_isMove = true;
		_playerX -= 3.0f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_direction = false;
		_player->setFrameY(0);
		_isMove = true;
		_playerX += 3.0f;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_playerY -= 3.0f;
		
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(), _playerX, _playerY);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_playerY += 3.0f;
		}
		_isMove = true;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_playerY += 3.0f;
		_isMove = true;
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(), _playerX, _playerY);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);
	
		if (!(r == 255 && g == 0 && b == 255))
		{
			_playerY -= 3.0f;
		}
	
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_jumpPower = 6.0f;
		_isJump = true;
	}
	if (_isJump)
	{
		_playerZ += _jumpPower;
		_jumpPower -= _gravity;
		if (_playerY - _playerZ > _playerY)
		{
			_playerZ = 0.f;
			_isJump = false;
		}

	}

	_probeY = _playerY;
	if (_isMove)
	{
		if (_test % 5 == 4)
		{
			_player->setFrameX(_player->getFrameX() + 1);
			if (_player->getFrameX() == 11)
				_player->setFrameX(1);
		}
		
	}
	else
		_player->setFrameX(0);
	
}


void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	// ���� �ǵ�������
	//================���� �� ���̿� �� �׸��ô�==========================
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	IMAGEMANAGER->findImage("���")->render(getMemDC(),0,0);
	_player->frameRender(getMemDC(), _playerX-_player->getWidth()*0.5, _playerY - _player->getFrameHeight() - _playerZ);

	TIMEMANAGER->render(getMemDC());
	//==================================================
	//���⵵ �ǵ�������
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
