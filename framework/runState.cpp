#include "stdafx.h"
#include "runState.h"
#include "idleState.h"
#include "attackState.h"
#include "player.h"

state * runState::inputHandle(player * player)
{
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		player->setSpeed(0.0f);
		return new idleState;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		player->setSpeed(0.0f);
		return new idleState;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		player->setSpeed(0.0f);
		return new idleState;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		player->setSpeed(0.0f);
		return new idleState;
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		return new attackState;
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
		player->setX(player->getX() - player->getSpeed());
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX() - player->getImage()->getFrameWidth()*0.5, player->getY());
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
		player->setX(player->getX() + player->getSpeed());
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX() - player->getImage()->getFrameWidth()*0.5, player->getY());
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
		player->setY(player->getY() - player->getSpeed());

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX() - player->getImage()->getFrameWidth()*0.5, player->getY());
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
		player->setY(player->getY() + player->getSpeed());
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("배경")->getMemDC(), player->getX() - player->getImage()->getFrameWidth()*0.5, player->getY());
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
