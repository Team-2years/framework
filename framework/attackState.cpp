#include "stdafx.h"
#include "attackState.h"
#include "idleState.h"
#include "player.h"

state * attackState::inputHandle(player * player)
{
	if (player->getFrameX() >= player->getImage()->getMaxFrameX())
	{
		return new idleState;
	}
	return nullptr;
}

void attackState::enter(player * player)
{
	player->setFrameX(0);
	player->setTime(0);
	player->setSpeed(0.f);
	player->setImage(IMAGEMANAGER->findImage("ÄìÄÚ¹ßÂ÷±â"));
}

void attackState::update(player * player)
{
	if (player->getTime() % 5 == 4)
	{
		player->setFrameX(player->getFrameX() + 1);
	}
}

void attackState::exit(player * player)
{

}
