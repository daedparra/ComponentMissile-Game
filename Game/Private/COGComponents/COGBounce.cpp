#include "COGBounce.h"

COGBounce::COGBounce(GameObject* pGO)
	:Component(pGO)
{
}

ComponentType COGBounce::GetType() const
{
	return ComponentType::Bounce;
}

void COGBounce::Initialize()
{
	COGPhysics* pPhysics = mGO->FindComponent<COGPhysics>(ComponentType::Physics);

	// add myself to the list of objects that are interested in collisions
	// COGPhysics is able to interface with us because we inherit from IPhysicsCollisionEvent
	pPhysics->AddCollisionEventListener(this);
}

void COGBounce::OnCollision(COGPhysics* pMe, COGPhysics* pOther)
{

	exVector2 position;
	position.x = 400.0f;
	position.y = 300.0f;

	exVector2 Square = pOther->GetNormal();
	exVector2 Ball = pMe->GetGO()->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
	
	
	float dotProduct = Square.x * pMe->GetVelocity().x + Square.y * pMe->GetVelocity().y;

	Square.x *= 2;
	Square.x *= dotProduct;

	Square.y *= 2;
	Square.y *= dotProduct;

	Square.x = pMe->GetVelocity().x - Square.x;
	Square.y = pMe->GetVelocity().y - Square.y;

	pMe->SetVelocity(Square);
	Square = pOther->GetNormal();

	if (Square.x == 0 & Square.y == 0) {
		pMe->GetGO()->~GameObject();
		pOther->GetGO()->~GameObject();
	}
}


