#pragma once
#include "HashMap.h"

class GameObject;
class GameObjectInventory
{
public:

	GameObjectInventory();
	~GameObjectInventory();

	void Register(GameObject* pGO);
	void Unregister(GameObject* pGO);

	bool Exists(Hash hash) const;
	GameObject* Lookup(Hash hash);
	const GameObject* Lookup(Hash hash) const;


private:
	HashMap<GameObject*, 256> mMap;
};

extern GameObjectInventory gGameObjectInventory;
