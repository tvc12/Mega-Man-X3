#include "Stage4.h"



Stage4::Stage4()
{
	gate = new Gate(2280, 894, 16, 48, false);
}


Stage4::~Stage4()
{
}

void Stage4::getStaticObjects(unordered_map<int, GameObject*>* saticObjects)
{
}

void Stage4::getDynamicObjects(unordered_map<int, GameObject*>* dynamicObjects)
{
}

void Stage4::update(DWORD dt, unordered_map<int, GameObject*>* staticObjects)
{
	if (gate->getBoundBox().contains(viewPortGlobal))
	{
		draw = true;
	}
	else draw = false;
}

void Stage4::render(DWORD dt, D3DCOLOR colorBrush)
{
	if (draw)
		gate->render(dt);
}

void Stage4::reset()
{
	gate->state = GateLock;
}
