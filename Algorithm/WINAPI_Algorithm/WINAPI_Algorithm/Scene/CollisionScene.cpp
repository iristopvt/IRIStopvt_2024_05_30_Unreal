#include "pch.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle1 = make_shared<CircleCollider>(Vector2(500, 500), 50);
	_moveCircle = make_shared<CircleCollider>(Vector2(0, 0), 30);


	_rect1 = make_shared<RectCollider>(Vector2(700, 300), Vector2(50, 70));
	_moveRect = make_shared<RectCollider>(Vector2(0, 0), Vector2(30, 30));
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_circle1->Update();
	_moveCircle->Update();
	//_moveCircle->_center = mousePos;
	//_moveRect->
	_moveRect->_center = mousePos;
	_rect1->Update();
	_moveRect->Update();

	//점 원 
	if (_circle1->Iscollision(mousePos))
	{
		_circle1->SetRed();
	}
	else
	{
		_circle1->SetGreen();
	}

	// 사각형 원 ...과제
	if (_moveCircle->IsCollision(_rect1))
	{
		_moveCircle->SetRed();
	}
	else
	{
		_moveCircle->SetGreen();

	}

	//점 사각형
	if (_rect1->Iscollision(mousePos))
	{
		_rect1->SetRed();
	}
	else
	{
		_rect1->SetGreen();
	}
	//사각형 사각형
	if (_rect1 ->IsCollision(_moveRect))
	{
		_rect1->SetRed();
	}
	else
	{
		_rect1->SetGreen();
	}


}

void CollisionScene::Render(HDC hdc)
{
	_circle1->Render(hdc);
	_moveCircle->Render(hdc);
	_rect1->Render(hdc);
	_moveRect->Render(hdc);


}
