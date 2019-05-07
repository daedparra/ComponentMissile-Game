#pragma once
#include "HashMap.h"
#include "GameObjectInventory.h"

class GameObject;

class GameObjectHandle
{
public:
	bool isValid() const;
	GameObject* Get();
	const GameObject* Get() const;

	Hash mHash;

private:
	//GameObjectInventory gGameObjectInventory;
};

