#include "GameObject.h"

GameObject::GameObject(Hash hash, GameObjectInventory* gGameObjectInventory)
{
	mHash = hash;
	
	storedPointer = gGameObjectInventory;
	storedPointer->Register(this);
}

GameObject::~GameObject()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Destroy();

		delete pComponent;
	}
	storedPointer->Unregister(this);
}

GameObjectHandle GameObject::GetHandle()
{
	GameObjectHandle temp;
	temp.mHash = mHash;

	return temp;
}

int GameObject::GetComponets()
{
	return mComponents.size();
}

void GameObject::Initialize()
{
	for (Component* pComponent : mComponents)
	{
		pComponent->Initialize();
	}
}

void GameObject::AddComponent(Component * pComponent)
{
	mComponents.push_back(pComponent);
}
