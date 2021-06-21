#include "stdafx.h"
#include "TestScene.h"

HRESULT TestScene::init()
{
	IMAGEMANAGER->addImage("BackGround", "img/background.bmp",1200, 900, true, RGB(255, 0, 255));
	_background = IMAGEMANAGER->findImage("BackGround");
	_player = new player();
	_player->init();
	return S_OK;
}

void TestScene::release()
{
	//_player->release();
}

void TestScene::update()
{
	_player->update();
	_tagPlayer = _player->getPlayerData();
	pixelCollision();
}

void TestScene::render()
{
	_player->render();
	_background->render(getMemDC());
}

void TestScene::pixelCollision()
{
	
	for (int i = _tagPlayer->rc.left; i <= _tagPlayer->rc.left + 20; i++) 
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("BackGround")->getMemDC(), i, _tagPlayer->rc.top);
		int g = GetGValue(color);
		if ((g == 255))
		{
			_tagPlayer->x = i;
		}
	}
	for (int i = _tagPlayer->rc.right; i >= _tagPlayer->rc.right-20; i--)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("BackGround")->getMemDC(), i, _tagPlayer->rc.top);
		int g = GetGValue(color);
		if ((g == 255))
		{
			_tagPlayer->x = i - (_tagPlayer->rc.right - _tagPlayer->rc.left);
		}
	}
	for (int i = _tagPlayer->rc.top; i <= _tagPlayer->rc.top + 20; i++) 
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("BackGround")->getMemDC(), _tagPlayer->rc.left, i);
		int g = GetGValue(color);
		if ((g == 255))
		{
			_tagPlayer->y = i;
		}
	}
	for (int i = _tagPlayer->rc.bottom; i >= _tagPlayer->rc.bottom - 20; i--)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("BackGround")->getMemDC(), _tagPlayer->rc.left, i);
		int g = GetGValue(color);
		if ((g == 255))
		{
			_tagPlayer->y = i;
		}
	}
}
