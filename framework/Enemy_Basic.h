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


	

	RECT _rc;	//충돌판정용 몸
	int x, y;	//rc의 중점

	image* _image; //이미지 클래스 변수
	const char* imageName; //해당 IMAGEMANAGER에서 해당 이미지를 찾기 위한 key값


	bool isRight;		//오른쪽인지 판단여부
	int frameCount;		//프레임 카운트. 계속해서 증가 할 카운트 
	int frameUpdateCount;	//frameCount와 연동해서 frameCount%frameUpdateCount ==0이 될때마다 이미지 index값 증가
	int currentFrameX;		//현재 frameX


	int range; //에너미의 판단범위. 아직 미구현 

	tagTime _time;

	//select_action _currentAction;



	function<void(image*)> _CurrentAction;
	function<void(Enemy_Basic&, image*)> _currentAction_1;

public:

	virtual HRESULT init(int _x, int _y, const char* _imageName); //init
	virtual void update(image* _FieldImage);	//아직 플레이어 x,y값은 안넣엇고, 이미지 판단 
	virtual void release();
	virtual void render();


	void ImageUpdateFunc();
	void Controller(image* _FieldImage);

	RECT getRECT() { return _rc; } //에너미 RECT 게터


	void moveLeft(image* _FieldImage);
	void moveRight(image* _FieldImage);
	void moveUp(image* _FieldImage);
	void moveDown(image* _FieldImage);

	


	void setting_pattern(image* _FieldImage);

};

