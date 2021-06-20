#pragma once
#include "gameNode.h"

class player;

class state : public gameNode
{

public:
	virtual state* inputHandle(player* player) = 0;
	virtual void enter(player* player) = 0;
	virtual void update(player * player) = 0;
	virtual void exit(player * player) = 0;
};

