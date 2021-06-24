#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	IMAGEMANAGER->addFrameImage("캐릭터기본", "KyokoIdle.bmp", 1404, 414, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터무브", "KyokoMove.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("쿄코발차기", "KyokoKick.bmp", 9570, 426, 22, 2, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addFrameImage("캐릭터달리기", "KyokoRun.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터콤보1", "KyokoCombo1.bmp", 1494, 390, 6, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터콤보2", "KyokoCombo2.bmp", 1953, 396, 7, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터콤보3", "KyokoCombo3.bmp", 4428, 414, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터강공격", "KyokoStrongAttack.bmp", 3186, 474, 9, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터점프", "KyokoJump.bmp", 405, 420, 3, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터점프강공격", "KyokoJumpStrongAttack.bmp", 1551, 522, 11, 2, true, RGB(255, 0, 255), true);
	_player.state = new idleState;
	_player.state->enter(this);
	_player.image->setFrameX(0);
	_player.frameY = 0;
	
	_player.x = 400.0f;
	_player.y = 800.0f;
	_player.z = 0.f;
	_player.frameX = 0;
	_player.gravity = 0.7f;
	_player.jumpPower = 0.f;
	_player.time = 0;
	_player.speed = 0.0f;
	_player.moveCommandInput = 0;
	_player.attackCommandInput = 0;
	_player.comboCount = 0;
	_player.collsionRcWidth = 110;
	_player.collsionRcHeight = 210;
	_player.collsionRect = RectMakeCenter(_player.x,
		_player.y - 105,
		_player.collsionRcWidth,
		_player.collsionRcHeight);
	return S_OK;
}

void player::release()
{

}

void player::update()
{
	inputHandle();
	_player.state->update(this);
	//타임은 계속 올라가고 커맨드 입력시간은 줄임
	_player.time++;
	if (_player.moveCommandInput > 0)
		_player.moveCommandInput--;
	if (_player.attackCommandInput > 0)
		_player.attackCommandInput--;

	//일단 대충 콜리전 렉트
	if (_player.image->getFrameWidth() > 100)
		_player.collsionRcWidth = 100;
	else
		_player.collsionRcWidth = _player.image->getFrameWidth();

	if (_player.image->getFrameHeight() > 190)
		_player.collsionRcHeight = 190;
	else
		_player.collsionRcHeight = _player.image->getFrameHeight();

	_player.collsionRect = RectMakeCenter(
		_player.x, 
		_player.y - _player.collsionRcHeight*0.5 -_player.z,
		_player.collsionRcWidth,
		_player.collsionRcHeight);

	if (_player.time == 50)
		_player.time = 1;
	
}

void player::render()
{
	Rectangle(getMemDC(), _player.collsionRect);
	EllipseMakeCenter(getMemDC(), _player.x, _player.y, 90, 45);
	_player.image->frameRender(getMemDC(),
		_player.x - _player.image->getFrameWidth() * 0.5,
		_player.y - _player.image->getFrameHeight() - _player.z,
		_player.frameX,
		_player.frameY);
}

void player::setAttackRect(float x, float y)
{
	
}

//업데이트마다 상태가 바뀌는지 체크
void player::inputHandle()
{
	state* tmpstate = _player.state->inputHandle(this);
	if (tmpstate != nullptr)
	{
		SAFE_DELETE(_player.state);
		_player.state = tmpstate;
		_player.state->enter(this);
	}

}
