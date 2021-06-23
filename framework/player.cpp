#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	IMAGEMANAGER->addFrameImage("ĳ���ͱ⺻", "characterIdle.bmp", 1332, 414, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("ĳ���͹���", "characterMove.bmp", 1476, 402, 12, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("���ڹ�����", "KyokoKick.bmp", 9570, 426, 22, 2, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addFrameImage("ĳ���ʹ޸���", "characterRun.bmp", 2736, 384, 16, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("ĳ�����޺�1", "characterCombo1.bmp", 1494, 390, 6, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("ĳ�����޺�2", "characterCombo2.bmp", 1953, 396, 7, 2, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addFrameImage("ĳ�����޺�3", "characterCombo3.bmp", 4428, 414, 12, 2, true, RGB(255, 0, 255), true);
	_state = new idleState;
	_state->enter(this);
	_player->setFrameX(0);
	_frameY = 0;
	_direction = false;
	
	_x = 400.0f;
	_y = 800.0f;
	_z = 0.f;
	_frameX = 0;
	_gravity = 0.5f;
	_isMove = false;
	_isJump = false;
	_jumpPower = 0.f;
	_time = 0;
	_cantMove = false;
	_speed = 0.0f;
	_moveCommandInput = 0;
	return S_OK;
}

void player::release()
{

}

void player::update()
{
	inputHandle();
	_state->update(this);
	_time++;
	if (_moveCommandInput > 0)
		_moveCommandInput--;
	if (!_cantMove && !_isJump && KEYMANAGER->isStayKeyDown('D'))
	{
		_jumpPower = 12.0f;
		_z += _jumpPower;
		_jumpPower -= _gravity;
		_isJump = true;
	}
	if (_isJump)
	{
		_z += _jumpPower;
		_jumpPower -= _gravity;
		if (_y - _z > _y)
		{
			_z = 0.f;
			_jumpPower = 0.f;
			_isJump = false;
		}
	}
	if (_time == 50)
		_time = 1;
}

void player::render()
{
	EllipseMakeCenter(getMemDC(), _x, _y, 90, 45);
	_player->frameRender(getMemDC(),
		_x - _player->getFrameWidth() * 0.5,
		_y - _player->getFrameHeight() - _z,
		_frameX,
		_frameY);
}

void player::inputHandle()
{
	state* tmpstate = _state->inputHandle(this);
	if (tmpstate != nullptr)
	{
		SAFE_DELETE(_state);
		_state = tmpstate;
		_state->enter(this);
	}

}
