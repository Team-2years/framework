#include "stdafx.h"
#include "comboState.h"
#include "player.h"
#include "idleState.h"
#include "strongAttackState.h"

state * comboState::inputHandle(player * player)
{
	if (player->getFrameX() >= player->getImage()->getMaxFrameX())
	{
		return new idleState;
	}
	if (player->getComboCount() == 2 && player->getTime() > 24 && player->getTime() < 30 && KEYMANAGER->isOnceKeyDown('S'))
	{
		return new strongAttackState;
	}
	return nullptr;
}

void comboState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("Ä³¸¯ÅÍÄÞº¸1"));
	player->setFrameX(0);
	player->setTime(0);
	player->setComboCount(0);
}

void comboState::update(player * player)
{
	if (player->getTime() % 4 == 1)
	{
		player->setFrameX(player->getFrameX() + 1);
	}
	switch (player->getComboCount())
	{
	case 0:
		if (player->getTime() > 7 && player->getTime() < 25 && KEYMANAGER->isOnceKeyDown('A'))
		{
			player->setImage(IMAGEMANAGER->findImage("Ä³¸¯ÅÍÄÞº¸2"));
			player->setFrameX(0);
			player->setTime(0);
			player->setComboCount(1);
		}
		break; 
	case 1:
		if (player->getTime() > 11 && player->getTime() < 29 && KEYMANAGER->isOnceKeyDown('A'))
		{
			player->setImage(IMAGEMANAGER->findImage("Ä³¸¯ÅÍÄÞº¸3"));
			player->setFrameX(0);
			player->setTime(0);
			player->setComboCount(2);
		}
		break;
	default:
		break;
	}

}

void comboState::exit(player * player)
{

}
