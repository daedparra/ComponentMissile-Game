#include "World.h"
#include "COGTransform.h"
#include "COGPhysics.h"
#include "COGBoxShape.h"
#include "COGCircleShape.h"
#include "COGBounce.h"
#include "COGInputManager.h"
#include "COGScore.h"
#include "COGMissile.h"
#include <algorithm>

GameObject * World::CreateMissile(std::string hash) {
	float WallWidth;
	float WallHeight;
	exVector2 position;
	exVector2 velocity;
	exVector2 normal;

	velocity.x = 0.0f;
	velocity.y = -50.0f;

	WallWidth = 50.0f;
	WallHeight = 50.0f;
	
	normal.x = 0;
	normal.y = 0;

	position.x = kViewportWidth / 2;
	position.y = kViewportHeight - 100;

	exColor c;
	c.mColor[0] = 255;
	c.mColor[1] = 100;
	c.mColor[2] = 255;
	c.mColor[3] = 255;

	GameObject* pMissile = new GameObject(s_hash(hash), &gGameObjectInventory);

	COGMissile* pTrack = new COGMissile(pMissile, &gGameObjectInventory);
	pMissile->AddComponent(pTrack);

	COGTransform* pTransform = new COGTransform(pMissile, position);
	pMissile->AddComponent(pTransform);

	COGBoxShape* pBoxShape = new COGBoxShape(pMissile, WallWidth, WallHeight, c);
	pMissile->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pMissile, false, velocity, normal);
	pMissile->AddComponent(pPhysics);

	pMissile->Initialize();

	return pMissile;

}

GameObject * World::CreateBall()
{
	const float fBallRadius = 12.0f;
	exColor c;
	exVector2 position;
	exVector2 normal;
	exVector2 velocity;

	normal.x = 0;
	normal.y = 0;

	velocity.x = 150.0f;
	velocity.y = 0.0f;

	position.x = kViewportWidth  / 2;
	position.y = kViewportHeight / 5;


	GameObject* pBall = new GameObject(s_hash("enemie"), &gGameObjectInventory);

	COGTransform* pTransform = new COGTransform(pBall, position);
	pBall->AddComponent(pTransform);

	COGCircleShape* pBoxShape = new COGCircleShape(pBall, fBallRadius);
	pBall->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pBall, true, velocity, normal);
	pBall->AddComponent(pPhysics);

	COGBounce* pBounce = new COGBounce(pBall);
	pBall->AddComponent(pBounce);

	pBall->Initialize();

	return pBall;
}

GameObject* World::CreateWallTB(bool top)
{
	float wallWidth ;
	float wallHeight;
	exVector2 position;
	exVector2 velocity;
	velocity.x = 0;
	velocity.y = 0;
	exVector2 normal;
	exColor c;
	c.mColor[0] = 200;
	c.mColor[1] = 200;
	c.mColor[2] = 255;
	c.mColor[3] = 255;

	if (top)
	{
		wallWidth = 100.0f;
		wallHeight = 50.0f;

		normal.x = 0;
		normal.y = 1;
		position.x = kViewportWidth / 2;
		position.y = kViewportHeight - 25;
	}
	else
	{
		wallWidth = kViewportWidth;
		wallHeight = 10.0f;

		normal.x = 0;
		normal.y = -1;
		position.x = kViewportWidth / 2;
		position.y = kViewportHeight + 3;
	}

	GameObject* pWall = new GameObject(s_hash("wall"), &gGameObjectInventory);
	COGTransform* pTransform = new COGTransform(pWall, position);
	pWall->AddComponent(pTransform);

	COGBoxShape* pBoxShape = new COGBoxShape(pWall, wallWidth, wallHeight, c);
	pWall->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pWall, false, velocity, normal);
	pWall->AddComponent(pPhysics);

	pWall->Initialize();

	return pWall;
}

GameObject* World::CreateWallLR(bool right)
{
	float wallWidth = 20;
	float wallHeight = kViewportHeight;
	exVector2 position;
	exVector2 velocity;
	velocity.x = 0;
	velocity.y = 0;
	exVector2 normal;
	exColor c;
	c.mColor[0] = 200;
	c.mColor[1] = 200;
	c.mColor[2] = 255;
	c.mColor[3] = 255;


	if (right)
	{
		wallWidth = 10.0f;
		wallHeight = kViewportHeight;

		normal.x = 1;
		normal.y = 0;

		position.x = kViewportWidth + 10;
		position.y = kViewportHeight / 2;
	}
	else
	{
		wallWidth = 10.0f;
		wallHeight = kViewportHeight;

		normal.x = -1;
		normal.y = 0;

		position.x = -10;
		position.y = kViewportHeight / 2;
	}

	GameObject* pWall = new GameObject(s_hash("wall"), &gGameObjectInventory);
	COGTransform* pTransform = new COGTransform(pWall, position);
	pWall->AddComponent(pTransform);

	COGBoxShape* pBoxShape = new COGBoxShape(pWall, wallWidth, wallHeight, c);
	pWall->AddComponent(pBoxShape);

	COGPhysics* pPhysics = new COGPhysics(pWall, false, velocity, normal);
	pWall->AddComponent(pPhysics);

	pWall->Initialize();

	return pWall;
}


World::World(exEngineInterface* pEngine, int pFont)
{
	mEngine = pEngine;
	thisFont = mEngine->LoadFont("Roboto-Regular.ttf", 32);

}

void World::Create()
{
	mGameObjects.push_back(CreateMissile("Missile"));
	mGameObjects.push_back(CreateBall());
	mGameObjects.push_back(CreateWallTB(true));
	mGameObjects.push_back(CreateWallTB(false));
	mGameObjects.push_back(CreateWallLR(true));
	mGameObjects.push_back(CreateWallLR(false));
}

void World::Destroy()
{
	for (GameObject* pGameObject : mGameObjects)
	{
		delete pGameObject;
	}

	mGameObjects.clear();
}

void World::Update(float fDeltaT, bool mUp, bool mDown, bool mW, bool mS)
{
	if (mUp) 
	{
		numMissile++;
		mGameObjects.push_back(CreateMissile("Missile"+numMissile));
	}
		// run simulation first
	for (COGPhysics* pPhysics : COGPhysics::mPhysicsComponents)
	{
		pPhysics->Update(fDeltaT);

	}
	
	// Listens for the user input
	for (COGInputManager* pInput : COGInputManager::mInputs)
	{
		pInput->MovementEventListener(mUp, mDown, mW, mS, fDeltaT);
			
	}

	for (COGMissile* pTrack : COGMissile::mTrackMissiles)
	{
		pTrack->FindBall();
	}

	// then render everything
	for (COGShape* pShape : COGShape::mShapeComponents)
	{
		pShape->Render(mEngine);
	}
}