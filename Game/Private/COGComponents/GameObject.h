#pragma once
#include "Component.h"
#include <vector>
#include <algorithm>
#include "../HashMap.h"
#include "Game/Private/GameObjectHandle.h"

class Component;
class GameObjectInventory;

class GameObject
{
public:
	GameObject(Hash hash, GameObjectInventory* gGameObjectInventory);
	~GameObject();

	void Initialize();
	void AddComponent(Component* pComponent);
	GameObjectHandle GetHandle();
	int GetComponets();
	template<class T>
	T* FindComponent(ComponentType eType);

private:
	std::vector<Component*> mComponents;

public:
	Hash mHash;

	GameObjectInventory* storedPointer;
	GameObjectHandle thisHandle;

};

template<class T>
inline T * GameObject::FindComponent(ComponentType eType)
{
	for (Component* pComponent : mComponents)
	{
		if (pComponent->GetType() == eType)
		{
			return (T*)pComponent;
		}
	}
	return nullptr;
}
