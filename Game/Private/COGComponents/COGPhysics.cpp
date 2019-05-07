#include "COGPhysics.h"

std::vector<COGPhysics*> COGPhysics::mPhysicsComponents;

COGPhysics::COGPhysics(GameObject * pGO, bool bGenerateCollisionEvents, exVector2 velocity, exVector2 normal)
	:Component(pGO)
	, mGenerateCollisionEvents(bGenerateCollisionEvents)
{
	mVelocity = velocity;
	mNormal = normal;
}

ComponentType COGPhysics::GetType() const
{
	return ComponentType::Physics;
}

void COGPhysics::Initialize()
{
	mTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	mBoxShape = mGO->FindComponent<COGBoxShape>(ComponentType::BoxShape);
	mCircleShape = mGO->FindComponent<COGCircleShape>(ComponentType::CircleShape);

	AddToComponentVector(mPhysicsComponents);
}

void COGPhysics::Destroy()
{
	RemoveFromComponentVector(mPhysicsComponents);
}

void COGPhysics::Update(float fDeltaT)
{
	// integrate velocity
	exVector2& myPosition = mTransform->GetPosition();

	myPosition.x += mVelocity.x * fDeltaT;
	myPosition.y += mVelocity.y * fDeltaT;

	// check collisions
	if (mGenerateCollisionEvents)
	{
		for (COGPhysics* pPhysicsOther : COGPhysics::mPhysicsComponents)
		{
			// do not collide with self
			if (pPhysicsOther == this)
			{
				continue;
			}

			// TODO - maybe have IsColliding produce a vector/struct that contains the normal and then pass that into OnCollision?
			const bool bResult = IsColliding(pPhysicsOther);

			if (bResult)
			{
				for (IPhysicsCollisionEvent* pCollisionEventListener : mCollisionEventListeners)
				{
					pCollisionEventListener->OnCollision(this, pPhysicsOther);
				}
			}
		}
	}
}

bool COGPhysics::IsColliding(COGPhysics * pOther)
{
	if (mGO->GetComponets() == 0) {
		return false;
	}
	exVector2 Circle = mGO->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
	exVector2 Rectangle = pOther->GetGO()->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();

	float rectWidht = pOther->mBoxShape->GetWidth();
	float rectHeight = pOther->mBoxShape->GetHeight();
	float DeltaX = Circle.x - std::max(Rectangle.x, std::min(Circle.x, Rectangle.x + rectWidht));
	float Deltay = Circle.y - std::max(Rectangle.y, std::min(Circle.y, Rectangle.y + rectHeight));

	float halfWidth = rectWidht * 0.5f;
	float halfHeight = rectHeight * 0.5f;
	float radius = mCircleShape->GetRadius();

	float leftEdgeX = Rectangle.x - halfWidth;
	float rightEdgeX = Rectangle.x + halfWidth;

	if (Circle.x + radius >= leftEdgeX && Circle.x - radius <= rightEdgeX)
	{
		float topEdgeY = Rectangle.y - halfHeight;
		float bottomEdgeY = Rectangle.y + halfHeight;

		if (Circle.y + radius >= topEdgeY && Circle.y - radius <= bottomEdgeY)
		{
			return true;
		}
	}

	return false;
}

void COGPhysics::AddCollisionEventListener(IPhysicsCollisionEvent* pEvent)
{
	mCollisionEventListeners.push_back(pEvent);
}

void COGPhysics::SetVelocity(exVector2 velocity)
{
	mVelocity = velocity;
}

exVector2 COGPhysics::GetVelocity()
{
	return mVelocity;
}

exVector2 COGPhysics::GetNormal()
{
	return mNormal;
}
