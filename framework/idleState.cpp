#include "stdafx.h"
#include "idleState.h"
#include "walkState.h"
#include "attackState.h"
#include "runState.h"
#include "player.h"

state * idleState::inputHandle(player * player)
{
	if (player->getMoveCommandInput() == 0 && KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		player->setFrameY(1);
		player->setSpeed(3.0f);
		player->setMoveCommandInput(20);
		return new walkState;
	}
	if (player->getMoveCommandInput() == 0 && KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		player->setFrameY(0);
		player->setSpeed(3.0f);
		player->setMoveCommandInput(20);
		return new walkState;
	}
	if (player->getMoveCommandInput() > 0 && KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		player->setFrameY(1);
		player->setSpeed(5.0f);
		return new runState;
	}
	if (player->getMoveCommandInput() > 0 && KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		player->setFrameY(0);
		player->setSpeed(5.0f);
		return new runState;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		player->setSpeed(3.0f);
		return new walkState;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		player->setSpeed(3.0f);
		return new walkState;
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		return new attackState;
	}
	return nullptr;
}

void idleState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("캐릭터기본"));
	player->setFrameX(0);
	player->setTime(0);
}

void idleState::update(player * player)
{
	if (player->getFrameY() == 0)
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
	if (player->getFrameY() == 1)
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
	if (player->getTime() % 5 == 4)
	{
		player->setFrameX(player->getFrameX() + 1);
		if (player->getFrameX() >= player->getImage()->getMaxFrameX())
			player->setFrameX(0);
	}
	if (player->getTime() % 5 == 0 && player->getSpeed() > 0.f)
	{
		player->setSpeed(player->getSpeed() - 0.004f);
	}
}

void idleState::exit(player * player)
{

}
