#pragma once
#include "stdafx.h"
#include "gameNode.h"

#include <functional>

#define MOVESPEED 2.0f

typedef void(*select_action)(image*);


enum state
{
	MOVE,
	ATTACK
};
struct tagTime
{

	//timer* _timer;
	float _worldTime;
	float _currentTime;
	float _renewalTime;

};

class Enemy_Basic :
	public gameNode
{
private:

	
protected:


	

	RECT _rc;	//�浹������ ��
	int x, y;	//rc�� ����

	image* _image; //�̹��� Ŭ���� ����
	const char* imageName; //�ش� IMAGEMANAGER���� �ش� �̹����� ã�� ���� key��


	bool isRight;		//���������� �Ǵܿ���
	int frameCount;		//������ ī��Ʈ. ����ؼ� ���� �� ī��Ʈ 
	int frameUpdateCount;	//frameCount�� �����ؼ� frameCount%frameUpdateCount ==0�� �ɶ����� �̹��� index�� ����
	int currentFrameX;		//���� frameX


	int range; //���ʹ��� �Ǵܹ���. ���� �̱��� 

	tagTime _time;

	//select_action _currentAction;



	function<void(image*)> _CurrentAction;
	function<void(Enemy_Basic&, image*)> _currentAction_1;

public:

	virtual HRESULT init(int _x, int _y, const char* _imageName); //init
	virtual void update(image* _FieldImage);	//���� �÷��̾� x,y���� �ȳ־���, �̹��� �Ǵ� 
	virtual void release();
	virtual void render();


	void ImageUpdateFunc();
	void Controller(image* _FieldImage);

	RECT getRECT() { return _rc; } //���ʹ� RECT ����


	void moveLeft(image* _FieldImage);
	void moveRight(image* _FieldImage);
	void moveUp(image* _FieldImage);
	void moveDown(image* _FieldImage);

	


	void setting_pattern(image* _FieldImage);

};

