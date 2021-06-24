#pragma once
#include "gameNode.h"
#include "idleState.h"


struct tagPlayer
{
	image* image;
	state* state;
	RECT collsionRect;
	RECT attackRect;
	float x, y, z;
	float hp;
	float gravity;
	float jumpPower;
	int time;
	int frameX;
	int frameY;
	float speed;
	int moveCommandInput;
	int attackCommandInput;
	int comboCount;
};
class player : public gameNode
{
private:
	tagPlayer _player;
	
public:

	HRESULT init();
	void release();
	void update();
	void render();
	void setX(float x) { _player.x = x; }
	void setY(float y) { _player.y = y; }
	void setZ(float z) { _player.z = z; }
	void setImage(image * image) { _player.image = image; }
	void setFrameX(int x) { _player.frameX = x; }
	void setFrameY(int y) { _player.frameY = y; }
	void setJumpPower(float power) { _player.jumpPower = power; }
	void setTime(int time) { _player.time = time; }
	void setSpeed(float speed) { _player.speed = speed; }
	void setMoveCommandInput(int input) { _player.moveCommandInput = input; }
	void setAttackCommandInput(int input) { _player.attackCommandInput = input; }
	void setComboCount(int input) { _player.comboCount = input; }
	void setAttackRect(float x, float y,float radius);
	tagPlayer getPlayer() { return _player; }
	void inputHandle();
};

