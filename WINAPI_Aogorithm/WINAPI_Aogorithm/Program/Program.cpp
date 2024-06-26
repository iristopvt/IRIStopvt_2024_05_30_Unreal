#include "Program.h"
#include "pch.h"

Program::Program()
{
	_scene = make_shared<PaintScene>();
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
