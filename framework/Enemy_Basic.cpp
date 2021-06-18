#include "stdafx.h"
#include "Enemy_Basic.h"

HRESULT Enemy_Basic::init(int _x, int _y, const char * _imageName)
{
	x = _x;
	y = _y;

	imageName = _imageName;

	_image = new image;
	_image = IMAGEMANAGER->findImage(imageName);


	TIMEMANAGER->init();

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());



	isRight = true;
	frameCount = 0;
	frameUpdateCount = 5;
	currentFrameX = 0;

	_image->setFrameX(0);
	_image->setFrameY(0);



	range = 600;


	_time._currentTime = TIMEMANAGER->getElapsedTime(); //
	_time._worldTime = TIMEMANAGER->getWorldTime(); //해당 월드 타임을 저장하는 변수. 이때부터 시간을 잼
	_time._renewalTime = 5.0f; //갱신할 시간


	//select_action = nullptr;

	
	
	return S_OK;
}

void Enemy_Basic::update(image* _FieldImage)
{



	Controller(_FieldImage);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());




	ImageUpdateFunc();

	//if (TIMEMANAGER->getWorldTime() - _time._worldTime >= _time._renewalTime)

	_currentAction_1 = nullptr;
	_CurrentAction = nullptr;
}


void Enemy_Basic::release()
{
}

void Enemy_Basic::render()
{
	Rectangle(getMemDC(), _rc);
	_image->frameRender(getMemDC(), x - _image->getFrameWidth() / 2, y - _image->getFrameHeight() / 2, _image->getFrameX(), _image->getFrameY());

	char str[128];

	sprintf_s(str, "현재 시간 : %2.f", TIMEMANAGER->getWorldTime() - _time._worldTime);

	//TextOut(getMemDC(), x - 30, y - 40, str, strlen(str));

	TextOut(getMemDC(), 0, 100, str, strlen(str));
}

void Enemy_Basic::ImageUpdateFunc()
{

	frameCount++;

	if (frameCount%frameUpdateCount)
	{
		if (isRight)
		{
			_image->setFrameY(0);
			_image->setFrameX(currentFrameX);


			currentFrameX++;

			if (currentFrameX > _image->getMaxFrameX()) currentFrameX = 0;
		}
		else
		{
			_image->setFrameY(1);
			_image->setFrameX(currentFrameX);

			currentFrameX--;

			if (currentFrameX < 0) currentFrameX = _image->getMaxFrameX();
		}
	}
}

void Enemy_Basic::Controller(image* _FieldImage)
{





	//if (KEYMANAGER->isStayKeyDown(VK_LEFT)) moveLeft(_FieldImage);
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) moveRight(_FieldImage);
	//if (KEYMANAGER->isStayKeyDown(VK_UP)) moveUp(_FieldImage);
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN)) moveDown(_FieldImage);
}

void Enemy_Basic::moveLeft(image* _FieldImage)
{
	if (isRight)
	{
		isRight = false;
		_image->setFrameX(_image->getMaxFrameX());
	}
	//_image->setX(_image->getX() - 3);
	x -= 3;

	COLORREF FieldPixel = GetPixel(_FieldImage->getMemDC(), _rc.left, _rc.bottom);

	int r = GetRValue(FieldPixel);
	int g = GetGValue(FieldPixel);
	int b = GetBValue(FieldPixel);

	if (!(r == 255 && g == 0 && b == 255)) x += 3;

}

void Enemy_Basic::moveRight(image* _FieldImage)
{
	if (!isRight)
	{
		isRight = true;
		_image->setFrameX(_image->getMaxFrameX());
	}
	//_image->setX(_image->getX() - 3);
	x += 3;

	COLORREF FieldPixel = GetPixel(_FieldImage->getMemDC(), _rc.right, _rc.bottom);

	int r = GetRValue(FieldPixel);
	int g = GetGValue(FieldPixel);
	int b = GetBValue(FieldPixel);

	if (!(r == 255 && g == 0 && b == 255)) x -= 3;
}

void Enemy_Basic::moveUp(image* _FieldImage)
{



	COLORREF FieldPixel = GetPixel(_FieldImage->getMemDC(), x, _rc.bottom - 5); //y + _image->getFrameHeight()/2);

	int r = GetRValue(FieldPixel);
	int g = GetGValue(FieldPixel);
	int b = GetBValue(FieldPixel);



	y -= 3;

	if (!(r == 255 && g == 0 && b == 255)) y += 3;



}

void Enemy_Basic::moveDown(image* _FieldImage)
{
	y += 3;

	COLORREF FieldPixel = GetPixel(_FieldImage->getMemDC(), x, y + _image->getFrameHeight() / 2);

	int r = GetRValue(FieldPixel);
	int g = GetGValue(FieldPixel);
	int b = GetBValue(FieldPixel);

	if (!(r == 255 && g == 0 && b == 255)) y -= 3;
}

void Enemy_Basic::setting_pattern(image* _FieldImage)
{
	//_pattern.insert(make_pair(0, moveLeft(_FieldImage)));
}
