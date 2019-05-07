#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "GameObject.h"
#include "ComponentType.h"
#include "COGPhysics.h"
#include "COGScore.h"

class COGBounce: public Component, public IPhysicsCollisionEvent
{
public:
	COGBounce(GameObject* pGO);

	virtual ComponentType GetType() const;
	virtual void Initialize() override;
	virtual void OnCollision(COGPhysics* pMe, COGPhysics* pOther) override;
};

