#pragma once
#include "COGShape.h"
#include "Engine/Public/EngineInterface.h"

class COGCircleShape: public COGShape
{
public:
	COGCircleShape(GameObject* pGO, float fRadius);

	virtual ComponentType GetType() const;
	virtual void Render(exEngineInterface* pEngine) override;

	float GetRadius();


private:
	float mRadius;
};

