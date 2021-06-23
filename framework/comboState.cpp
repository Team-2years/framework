#include "stdafx.h"
#include "comboState.h"
#include "player.h"
#include "idleState.h"

state * comboState::inputHandle(player * player)
{
	return nullptr;
}

void comboState::enter(player * player)
{
	
}

void comboState::update(player * player)
{
	player->setImage(IMAGEMANAGER->findImage("Ä³¸¯ÅÍÄÞº¸1"));
	player->setFrameX(0);
}

void comboState::exit(player * player)
{

}
