#include "COGMissile.h"
std::vector<COGMissile*> COGMissile::mTrackMissiles;

COGMissile::COGMissile(GameObject* hPointer, GameObjectInventory* inventory) : Component(hPointer)
{
	mInventory = inventory;
}

ComponentType COGMissile::GetType() const
{
	return ComponentType::TrackMissle;
}


void COGMissile::FindBall()
{
	GameObjectHandle handle;
	handle.mHash = s_hash("enemie");

	if (handle.isValid())
	{

		GameObject* GO = handle.Get();


		exVector2 ballPosition = GO->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
		exVector2 missilePosition = mGO->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();


		exVector2 travel;
		travel.x = ballPosition.x - missilePosition.x;
		travel.y = ballPosition.y - missilePosition.y;

		float length = sqrt(travel.x * travel.x + travel.y * travel.y);

		// normalize vector
		travel.x /= length;
		travel.y /= length;

		travel.x *= 100.0f;
		travel.y *= 100.0f;

		mGO->FindComponent<COGPhysics>(ComponentType::Physics)->SetVelocity(travel);

	}
	else
	{
		if (mGO->GetComponets() != 0) {
			exVector2 missilePosition = mGO->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
			if (missilePosition.y < kViewportHeight / 2) {
				mGO->~GameObject();
			}
		}
	}
}

void COGMissile::Initialize()
{

	AddToComponentVector(mTrackMissiles);
}

void COGMissile::Destroy()
{
	RemoveFromComponentVector(mTrackMissiles);
}
