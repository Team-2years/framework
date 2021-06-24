#include "stdafx.h"
#include "jumpState.h"
#include "player.h"
#include "idleState.h"

state * jumpState::inputHandle(player * player)
{
	if (player->getPlayer().y - player->getPlayer().z > player->getPlayer().y)
	{
		player->setZ(0.f);
		player->setJumpPower(0.f);
		player->setSpeed(0.f);
		return new idleState;
	}

	return nullptr;
}

void jumpState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("ĳ��������"));

	player->setFrameX(0);
	player->setTime(0);
	player->setJumpPower(17.0f);
}

void jumpState::update(player * player)
{
	player->setZ(player->getPlayer().z + player->getPlayer().jumpPower);
	player->setJumpPower(player->getPlayer().jumpPower - player->getPlayer().gravity);

	if (player->getPlayer().jumpPower < -3.f)
		player->setFrameX(2);
	else if (player->getPlayer().jumpPower < 1)
		player->setFrameX(1);
	else
		player->setFrameX(0);
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (player->getPlayer().frameY == 1)
			player->setFrameY(0);
		player->setX(player->getPlayer().x + player->getPlayer().speed);
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(),
			player->getPlayer().x,
			player->getPlayer().y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setX(player->getPlayer().x - player->getPlayer().speed);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (player->getPlayer().frameY == 0)
			player->setFrameY(1);
		player->setX(player->getPlayer().x - player->getPlayer().speed);
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(),
			player->getPlayer().x,
			player->getPlayer().y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setX(player->getPlayer().x + player->getPlayer().speed);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		player->setY(player->getPlayer().y - player->getPlayer().speed);

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(),
			player->getPlayer().x,
			player->getPlayer().y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setY(player->getPlayer().y + player->getPlayer().speed);
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		player->setY(player->getPlayer().y + player->getPlayer().speed);

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("���")->getMemDC(),
			player->getPlayer().x,
			player->getPlayer().y);
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			player->setY(player->getPlayer().y - player->getPlayer().speed);
		}
	}
}

void jumpState::exit(player * player)
{
}