#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	IMAGEMANAGER->addFrameImage("캐릭터무브", "characterMove.bmp", 492, 134, 12, 2, true, RGB(255, 0, 255), true);
	_player = IMAGEMANAGER->findImage("캐릭터무브");
	_player->setFrameX(0);
	_player->setFrameY(0);
	_direction = false;
	_state = 0;
	_x = 400.0f;
	_y = 800.0f;
	_z = 0.f;
	_gravity = 0.25f;
	_isMove = false;
	_isJump = false;
	_jumpPower = 0.f;
	_time = 0;
	return S_OK;
}

void player::release()
{

}

void player::update()
{
	_time++;
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_direction = true;
		_player->setFrameY(0);
		_isMove = true;
		_x -= 3.0f;
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), _x-_player->getFrameWidth()*0.5, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_x += 3.0f;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_direction = false;
		_player->setFrameY(1);
		_isMove = true;
		_x += 3.0f;
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), _x+_player->getFrameWidth()*0.5, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_x -= 3.0f;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 3.0f;

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), _x, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y += 3.0f;
		}
		_isMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isMove = false;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 3.0f;
		_isMove = true;
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), _x, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y -= 3.0f;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isMove = false;
	}
	if (!_isJump && KEYMANAGER->isStayKeyDown('D'))
	{
		_jumpPower = 7.0f;
		_z += _jumpPower;
		_jumpPower -= _gravity;
		_isJump = true;
	}
	if (_isJump)
	{
		_z += _jumpPower;
		_jumpPower -= _gravity;
		if (_y - _z > _y)
		{
			_z = 0.f;
			_jumpPower = 0.f;
			_isJump = false;
		}
	}
	if (_isMove)
	{
		if (_time % 5 == 4)
		{
			_player->setFrameX(_player->getFrameX() + 1);
			if (_player->getFrameX() == 11)
				_player->setFrameX(1);
		}
	}
	else
		_player->setFrameX(0);
}

void player::render()
{
	EllipseMakeCenter(getMemDC(), _x, _y, 60, 30);
	_player->frameRender(getMemDC(),
		_x - _player->getFrameWidth() * 0.5,
		_y - _player->getFrameHeight() - _z);
}
