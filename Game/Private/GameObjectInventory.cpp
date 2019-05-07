#include "GameObjectInventory.h"

#include "Game/Private/COGComponents/GameObject.h"

GameObjectInventory gGameObjectInventory;

GameObjectInventory::GameObjectInventory()
{
}

GameObjectInventory::~GameObjectInventory()
{
}

void GameObjectInventory::Register(GameObject * pGO)
{
	mMap.InsertNoCheck(pGO);
}

void GameObjectInventory::Unregister(GameObject * pGO)
{
	mMap.Delete(pGO);
}

bool GameObjectInventory::Exists(Hash hash) const
{
	return (mMap.Find(hash) != nullptr);
}

GameObject * GameObjectInventory::Lookup(Hash hash)
{
	return mMap.Find(hash);
}

const GameObject * GameObjectInventory::Lookup(Hash hash) const
{
	return mMap.Find(hash);
}
