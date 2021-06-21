#include "stdafx.h"
#include "idleState.h"
#include "player.h"

state * idleState::inputHandle(player * player)
{
	return nullptr;
}

void idleState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("캐릭터무브"));
}

void idleState::update(player * player)
{

}

void idleState::exit(player * player)
{
}
