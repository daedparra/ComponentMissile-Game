#pragma once

#include "Engine/Public/EngineInterface.h"
#include "GameObject.h"
#include "Component.h"
#include "COGTransform.h"
#include "COGPhysics.h"


class COGInputManager : public Component
{
public:

	COGInputManager(GameObject* mPointer, int flag);
	virtual ComponentType GetType() const;
	virtual void Initialize() override;
	virtual void Destroy() override;
	

	void MovementEventListener(bool Up, bool Down, bool W, bool S, float time);

	static std::vector<COGInputManager*> mInputs;

private:

	// Player one Controls or Player Two depnding who is controlling
	GameObject* mObject;
	int thisFlag;
};