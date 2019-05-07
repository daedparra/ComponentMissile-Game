#pragma once
#include "ComponentType.h"
#include "GameObject.h"
#include "Game/Public/GameInterface.h"
#include <vector>
class GameObject;
class Component
{
public:
	Component(GameObject* pGo);

	virtual ComponentType GetType() const = 0;

	virtual void Initialize();
	virtual void Destroy();

	GameObject* GetGO() {
		return mGO;
	}

protected:
	
	template<class T>
	void AddToComponentVector(std::vector<T*>& componentVector);

	template<class T>
	void RemoveFromComponentVector(std::vector<T*>& componentVector);

	GameObject* mGO;
};


// Templated Definitions
template<class T>
inline void Component::AddToComponentVector(std::vector<T*>& componentVector)
{
	componentVector.push_back((T*)this);
}

template<class T>
inline void Component::RemoveFromComponentVector(std::vector<T*>& componentVector)
{
	componentVector.erase(std::remove(componentVector.begin(), componentVector.end(), this), componentVector.end());
}
