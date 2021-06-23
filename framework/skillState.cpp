#include "stdafx.h"
#include "skillState.h"
#include "idleState.h"
#include "player.h"

state * skillState::inputHandle(player * player)
{
	if (player->getFrameX() >= player->getImage()->getMaxFrameX())
	{
		return new idleState;
	}
	return nullptr;
}

void skillState::enter(player * player)
{
	player->setFrameX(0);
	player->setTime(0);
	player->setSpeed(0.f);
	player->setImage(IMAGEMANAGER->findImage("ÄìÄÚ¹ßÂ÷±â"));
}

void skillState::update(player * player)
{
	if (player->getTime() % 5 == 4)
	{
		player->setFrameX(player->getFrameX() + 1);
	}
}

void skillState::exit(player * player)
{

}
