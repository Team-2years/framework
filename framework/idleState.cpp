#include "stdafx.h"
#include "idleState.h"
#include "player.h"

state * idleState::inputHandle(player * player)
{
	return nullptr;
}

void idleState::enter(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("ĳ���͹���"));
}

void idleState::update(player * player)
{

}

void idleState::exit(player * player)
{
}
