#include "Elevator.h"

void Elevator::loadResources()
{
	_animations[TElevator] = animationsGlobal->get(TElevator);
}

Elevator::Elevator(UINT idTexture, float x, float y) : StaticObject(idTexture, x, y - 6, 96, 43)
{
	//y -= 28;
	loadResources();
}

Elevator::~Elevator()
{

}

void Elevator::getBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y + 8;
	right = x + 96;
	bottom = y + 43;
}

void Elevator::update(DWORD dt, unordered_map<int, GameObject*>* staticObjects , unordered_map<int, GameObject*>* dynamicObjects) 
{
	//GameObject::update(dt);
	if (isRun && y >= 170)
	{
		y += -1;
		mainGlobal->y += -1;

	}
}

void Elevator::render(DWORD dt, D3DCOLOR colorBrush)
{
	auto pos = cameraGlobal->transform(x, y);
	_animations[TElevator]->render(pos.x, pos.y);
}

void Elevator::run()
{
	//speed.vy = -0.15f;
	isRun = true;
}
