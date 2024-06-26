#include "pch.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/LineScene.h"
#include "Scene/Line2scene.h"

Program::Program()
{
	_scene = make_shared<Line2scene>(); // make_shared 안에 있는걸 
	//PaintScene나 CollisionScene로 바꾸면 다른게 실행됨
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	_scene->Render(hdc);
}
