#pragma once
#include "gameNode.h"

// ĳ���� ���� ����
enum player_moveState
{
	kyoko_RIGHTIDLE,
	kyoko_LEFTIDLE,
	kyoko_RIGHTMOVE,
	kyoko_LEFTMOVE,
	kyoko_RIGHTUP,
	kyoko_RIGHTDOWN,
	kyoko_LEFTUP,
	kyoko_LEFTDOWN
};
// ĳ���Ͱ� ������ �ִ� ���Ȱ� ��ġ ������ ���⿡
struct tag_Player
{
	int x;
	int y;
	int z;
	player_moveState st;
	RECT rc;
};

class player :
	public gameNode
{
private:
	animation* _kyokoMotion;
	image* _player;
	tag_Player _tagPlayer;
public:
	player() {}
	~player() {}

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	// ������ ����
	void move();

	// �±� �÷��̾� �����͸� ��ȯ
	tag_Player* getPlayerData() { return &_tagPlayer; }
};

