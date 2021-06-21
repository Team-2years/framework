#pragma once
#include "gameNode.h"

// 캐릭터 상태 정의
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
// 캐릭터가 가지고 있는 스탯과 위치 정보는 여기에
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

	// 움직임 설정
	void move();

	// 태그 플레이어 데이터를 반환
	tag_Player* getPlayerData() { return &_tagPlayer; }
};

