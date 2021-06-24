#include "stdafx.h"
#include "comboState.h"
#include "player.h"
#include "idleState.h"
#include "strongAttackState.h"

state * comboState::inputHandle(player * player)
{
	if (player->getPlayer().frameX >= player->getPlayer().image->getMaxFrameX())
	{
		return new idleState;
	}
	if (player->getPlayer().comboCount == 2 &&
		player->getPlayer().time > 26 && 
		player->getPlayer().time < 30 &&
		KEYMANAGER->isOnceKeyDown('S'))
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
	player->setSpeed(0.f);
	player->setComboCount(0);
	_comboOn = false;
}

void comboState::update(player * player)
{
	if (player->getPlayer().time % 4 == 3)
	{
		player->setFrameX(player->getPlayer().frameX + 1);
	}
	switch (player->getPlayer().comboCount)
	{
	case 0:
		if (player->getPlayer().time > 4 &&
			player->getPlayer().time < 19 &&
			KEYMANAGER->isOnceKeyDown('A'))
		{
			_comboOn = true;
		}
		if (player->getPlayer().time == 19 &&
			_comboOn)
		{
			_comboOn = false;
			player->setImage(IMAGEMANAGER->findImage("Ä³¸¯ÅÍÄÞº¸2"));
			player->setFrameX(0);
			player->setTime(0);
			player->setComboCount(1);
		}
		break; 
	case 1:
		if (player->getPlayer().time > 11 &&
			player->getPlayer().time < 23 &&
			KEYMANAGER->isOnceKeyDown('A'))
		{ 
			_comboOn = true;
		}
		if (player->getPlayer().time == 23 &&
			_comboOn)
		{
			_comboOn = false;
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
