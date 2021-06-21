#pragma once
#include "state.h"

class player;

class idleState : public state
{
private:
	player* _player;
public:
	virtual state* inputHandle(player* player);
	virtual void enter(player* player);
	virtual void update(player * player);
	virtual void exit(player * player);

};
