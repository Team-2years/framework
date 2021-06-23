#include "stdafx.h"
#include "runState.h"
#include "idleState.h"
#include "skillState.h"
#include "player.h"

state * runState::inputHandle(player * player)
{
	if (!_leftMove && !_rightMove && !_upMove && !_downMove)
	{
		player->setSpeed(0.0f);
		return new idleState;
	}
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		player->setSpeed(0.0f);
		return new skillState;
	}
	return nullptr;
}

void runState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("캐릭터달리기"));
	player->setFrameX(0);
	player->setTime(0);
}

void runState::update(player * player)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_leftMove = true;

	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_leftMove = false;
	}
	if (_leftMove)
	{
		if (player->getFrameY() == 0)
			player->setFrameY(1);
		player->setX(player->getX() - player->getSpeed());
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX(), player->getY());
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setX(player->getX() + player->getSpeed());
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rightMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_rightMove = false;
	}
	if (_rightMove)
	{
		if (player->getFrameY() == 1)
			player->setFrameY(0);
		player->setX(player->getX() + player->getSpeed());
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX(), player->getY());
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setX(player->getX() - player->getSpeed());
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_upMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_upMove = false;
	}
	if (_upMove)
	{
		player->setY(player->getY() - player->getSpeed());

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX(), player->getY());
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setY(player->getY() + player->getSpeed());
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_downMove = true;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_downMove = false;
	}
	if (_downMove)
	{
		player->setY(player->getY() + player->getSpeed());
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX(), player->getY());
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setY(player->getY() - player->getSpeed());
		}
	}
	if (player->getTime() % 3 == 2)
	{
		player->setFrameX(player->getFrameX() + 1);
		if (player->getFrameX() > player->getImage()->getMaxFrameX())
			player->setFrameX(0);
	}
}

void runState::exit(player * player)
{
}
