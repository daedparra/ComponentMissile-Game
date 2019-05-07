#pragma once

#include <vector>
#include "Game/Private/GameObjectInventory.h"
class GameObject;


class exEngineInterface;

class World
{
public:
	World(exEngineInterface* pEngine, int pFont);

	void Create();
	void Destroy();
	void Update(float fDeltaT, bool mUp, bool mDown, bool mW, bool mS);
	

private:
	std::vector<GameObject*> mGameObjects;
	GameObject* CreateBall();
	GameObject* CreateMissile(std::string hash);
	GameObject * CreateWallTB(bool top);
	GameObject* CreateWallLR(bool right);

	int thisFont;

	bool thisUp;
	bool thisDown;

	bool thisW;
	bool thisS;
	int numMissile;
	exEngineInterface* mEngine;
};

