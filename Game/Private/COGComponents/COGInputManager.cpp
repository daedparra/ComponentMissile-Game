#include "COGInputManager.h"

std::vector<COGInputManager*> COGInputManager::mInputs;

COGInputManager::COGInputManager(GameObject * mPointer, int flag) : Component(mPointer)
{
	mObject = mPointer;
	thisFlag = flag;
}

ComponentType COGInputManager::GetType() const
{
	return ComponentType::InputManager;
}

void COGInputManager::Initialize()
{
	AddToComponentVector(mInputs);
}

void COGInputManager::Destroy()
{
	//RemoveFromComponentVector(mInputs);
}

void COGInputManager::MovementEventListener(bool mUp, bool mDown, bool mW, bool mS, float time)
{
	// This will return the position 
	exVector2& position = mObject->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();
	exVector2 velocity = mObject->FindComponent<COGPhysics>(ComponentType::Physics)->GetVelocity();
	COGPhysics* pMe = mObject->FindComponent<COGPhysics>(ComponentType::Physics);


	// Multiply by Time if you want Drag
	if (thisFlag == 0)
	{
		// Left Pedal Movement
		if (mW && position.x != 0)
		{
			
			// Translate the paddle upwards
			if (position.y <= 60) {
				position.y = 60;
			}
			position.y -= 10.0f;
			//pMe->SetVelocity(velocity);


		}
		else if (mS)
		{
			// Translate the paddle downwards
			if (position.y >= kViewportHeight - 60) {
				position.y = kViewportHeight - 60;
			}
			position.y += 10.0f;
			//pMe->SetVelocity(velocity);
		}
	}
	else
	{
		// Right Pedal Movement
		if (mUp)
		{
			// Translate the paddle upwards
			if (position.y <= 60) {
				position.y = 60;
			}
			position.y -= 10.0f;
			//pMe->SetVelocity(velocity);


		}
		else if (mDown)
		{
			// Translate the paddle downwards
			if (position.y >= kViewportHeight - 60) {
				position.y = kViewportHeight - 60;
			}
			position.y += 10.0f;
			//pMe->SetVelocity(velocity);
		}
	}
}
