#pragma once
#include "Component.h"
#include "IPhysicsCollisionEvent.h"
#include "GameObject.h"
#include "COGTransform.h"
#include "COGBoxShape.h"
#include "COGInputManager.h"
#include "COGCircleShape.h"

class COGPhysics: public Component
{
public:
	COGPhysics(GameObject* pGO, bool bGenerateCollisionEvents, exVector2 velocity, exVector2 normal);

	virtual ComponentType GetType() const;
	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Update(float fDeltaT);

	bool IsColliding(COGPhysics* pOther);
	void AddCollisionEventListener(IPhysicsCollisionEvent* pEvent);
	static std::vector<COGPhysics*> mPhysicsComponents;

	void SetVelocity(exVector2 velocity);
	exVector2 GetVelocity();
	exVector2 GetNormal();


protected:
	//static std::vector<COGPhysics*> mPhysicsComponents;
	
private:
	COGTransform* mTransform;
	COGBoxShape* mBoxShape;
	COGCircleShape* mCircleShape;

	exVector2 mNormal;
	exVector2 mVelocity;

	bool mGenerateCollisionEvents;
	std::vector<IPhysicsCollisionEvent*> mCollisionEventListeners;
};