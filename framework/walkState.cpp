#include "stdafx.h"
#include "walkState.h"
#include "player.h"

state * walkState::inputHandle(player * player)
{
	return nullptr;
}

void walkState::enter(player * player)
{
	_player = player;
	_player->setImage(IMAGEMANAGER->findImage("캐릭터무브"));


}

void walkState::update(player * player)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_player->setX(_player->getX() - 3.0f);
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), _x - _player->getFrameWidth()*0.5, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_x += 3.0f;
		}
	}
	if (!_cantMove && KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isMove = false;
	}
	if (!_cantMove && KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_direction = false;
		_frameY = 1;
		_isMove = true;
		_x += 3.0f;
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), _x + _player->getFrameWidth()*0.5, _y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_x -= 3.0f;
		}
	}
	if (!_cantMove && KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isMove = false;
	}
	if (!_cantMove && KEYMANAGER->isStayKeyDown(VK_UP))
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
	if (!_cantMove && KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isMove = false;
	}
	if (!_cantMove && KEYMANAGER->isStayKeyDown(VK_DOWN))
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
	if (!_cantMove && KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isMove = false;
	}
}

void walkState::exit(player * player)
{

}
