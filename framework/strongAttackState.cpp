#include "stdafx.h"
#include "strongAttackState.h"
#include "idleState.h"
#include "player.h"

state * strongAttackState::inputHandle(player * player)
{
	if (player->getFrameX() >= player->getImage()->getMaxFrameX())
	{
		return new idleState;
	}
	return nullptr;
}

void strongAttackState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("ĳ���Ͱ�����"));
	player->setTime(0);
	player->setFrameX(0);
	player->setComboCount(0);
}

void strongAttackState::update(player * player)
{
	if (player->getTime() % 5 == 4)
	{
		player->setFrameX(player->getFrameX() + 1);
	}
}

void strongAttackState::exit(player * player)
{
}
