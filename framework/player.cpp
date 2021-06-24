#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	IMAGEMANAGER->addFrameImage("캐릭터기본", "characterIdle.bmp", 1404, 414, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터무브", "characterMove.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("쿄코발차기", "KyokoKick.bmp", 9570, 426, 22, 2, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addFrameImage("캐릭터달리기", "characterRun.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터콤보1", "characterCombo1.bmp", 1494, 390, 6, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터콤보2", "characterCombo2.bmp", 1953, 396, 7, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터콤보3", "characterCombo3.bmp", 4428, 414, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터강공격", "characterStrongAttack.bmp", 3186, 474, 9, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("캐릭터점프", "characterJump.bmp", 405, 420, 3, 2, true, RGB(255, 0, 255), true);
	_player.state = new idleState;
	_player.state->enter(this);
	_player.image->setFrameX(0);
	_player.frameY = 0;
	
	_player.x = 400.0f;
	_player.y = 800.0f;
	_player.z = 0.f;
	_player.frameX = 0;
	_player.gravity = 0.5f;
	_player.jumpPower = 0.f;
	_player.time = 0;
	_player.speed = 0.0f;
	_player.moveCommandInput = 0;
	_player.attackCommandInput = 0;
	_player.comboCount = 0;
	_player.collsionRect = RectMakeCenter(_player.x, _player.y - 105, 110, 210);
	return S_OK;
}

void player::release()
{

}

void player::update()
{
	inputHandle();
	_player.state->update(this);
	_player.time++;
	if (_player.moveCommandInput > 0)
		_player.moveCommandInput--;
	if (_player.attackCommandInput > 0)
		_player.attackCommandInput--;
	
	_player.collsionRect = RectMakeCenter(_player.x, _player.y - 105, 110, 210);
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

void player::setAttackRect(float x, float y, float radius)
{

}

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
