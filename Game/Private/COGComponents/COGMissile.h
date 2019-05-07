#pragma once
#include "COGPhysics.h"
#include "ComponentType.h"
#include "Game/Private/GameObjectHandle.h"
#include <vector>

class COGMissile : public Component {
public:
	COGMissile(GameObject* hPointer, GameObjectInventory* inventory);

	virtual ComponentType GetType() const;


	void FindBall();
	virtual void Initialize();
	virtual void Destroy();

	static std::vector<COGMissile*> mTrackMissiles;
private:
	GameObject* thisObject;
	GameObjectInventory* mInventory;
};
