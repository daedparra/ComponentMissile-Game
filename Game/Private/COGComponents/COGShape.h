#pragma once
#include "Component.h"

class exEngineInterface;

class COGShape : public Component
{
public:
	COGShape(GameObject* pGO);

	virtual void Initialize() override;
	virtual void Destroy() override;
	virtual void Render(exEngineInterface* pEngine) = 0;

	static std::vector<COGShape*> mShapeComponents;

private:
	// TODO - add a color variable here!

	
};