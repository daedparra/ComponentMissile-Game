#include "GameObjectHandle.h"


bool GameObjectHandle::isValid() const
{
	return gGameObjectInventory.Exists(mHash);
}

const GameObject* GameObjectHandle::Get() const
{
	return gGameObjectInventory.Lookup(mHash);
}

GameObject* GameObjectHandle::Get()
{
	return gGameObjectInventory.Lookup(mHash);
}
