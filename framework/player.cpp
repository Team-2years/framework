#include "stdafx.h"
#include "player.h"

HRESULT player::init()
{
	//// 이미지 초기화
	IMAGEMANAGER->addFrameImage("kyoko_work", "img/kyoko_work.bmp", 984, 268, 12, 2, true, RGB(255, 0, 255));
	_player = IMAGEMANAGER->findImage("kyoko_work");

	//// 애니메이션 초기화
	int rightStop[] = { 12 };
	KEYANIMANAGER->addArrayFrameAnimation("kyokoRightStop", "kyoko_work", rightStop, 1, 6, true);
	int leftStop[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("kyokoLeftStop", "kyoko_work", leftStop, 1, 6, true);

	int rightMove[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayFrameAnimation("kyokoRightMove", "kyoko_work", rightMove, 12, 10, true);
	int leftMove[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	KEYANIMANAGER->addArrayFrameAnimation("kyokoLeftMove", "kyoko_work", leftMove, 12, 10, true);
	
	//// 플레이어 초기화
	_tagPlayer.x = WINSIZEX / 2;
	_tagPlayer.y = WINSIZEY / 2 - 300;
	_tagPlayer.z = 0;

	//// 플레이어 초기 상태 설정
	_tagPlayer.st = kyoko_RIGHTIDLE;
	_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightStop");
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	move();
	KEYANIMANAGER->update();
	_tagPlayer.rc = RectMake(_tagPlayer.x, _tagPlayer.y + 100, _player->getFrameWidth(), _player->getFrameHeight() - 90);

}

void player::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB)) 
	{
		Rectangle(getMemDC(), _tagPlayer.rc);
	}
	_player->aniRender(getMemDC(), _tagPlayer.x, _tagPlayer.y, _kyokoMotion);
	//IMAGEMANAGER->findImage("kyoko_work")->render(getMemDC());
}

void player::move()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightMove");
		_kyokoMotion->start();
		_tagPlayer.st = kyoko_RIGHTMOVE;
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightStop");
		_kyokoMotion->start();
		_tagPlayer.st = kyoko_RIGHTIDLE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoLeftMove");
		_kyokoMotion->start();
		_tagPlayer.st = kyoko_LEFTMOVE;

	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoLeftStop");
		_kyokoMotion->start();
		_tagPlayer.st = kyoko_LEFTIDLE;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_tagPlayer.st == kyoko_RIGHTIDLE || _tagPlayer.st == kyoko_RIGHTMOVE) 
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightMove");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_RIGHTUP;
		}
		else 
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoLeftMove");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_LEFTUP;
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		if (_tagPlayer.st == kyoko_LEFTUP) 
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoLeftStop");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_LEFTIDLE;
		}
		else 
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightStop");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_RIGHTIDLE;
		}
	
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_tagPlayer.st == kyoko_RIGHTIDLE || _tagPlayer.st == kyoko_RIGHTMOVE)
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightMove");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_RIGHTDOWN;
		}
		else
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoLeftMove");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_LEFTDOWN;
		}
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		if (_tagPlayer.st == kyoko_LEFTDOWN)
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoLeftStop");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_LEFTIDLE;
		}
		else
		{
			_kyokoMotion = KEYANIMANAGER->findAnimation("kyokoRightStop");
			_kyokoMotion->start();
			_tagPlayer.st = kyoko_RIGHTIDLE;
		}
	}
	switch (_tagPlayer.st)
	{
	case kyoko_RIGHTMOVE:
		_tagPlayer.x += 5;
		break;
	case kyoko_LEFTMOVE:
		_tagPlayer.x -= 5;
break;
	case kyoko_LEFTUP:
	case kyoko_RIGHTUP:
		_tagPlayer.y -= 5;
		break;

	case kyoko_LEFTDOWN:
	case kyoko_RIGHTDOWN:
		_tagPlayer.y += 5;
		break;
	default:
		break;
	}
}
