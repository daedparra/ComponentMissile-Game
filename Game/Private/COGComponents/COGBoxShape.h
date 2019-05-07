#pragma once
#include "COGShape.h"
#include "Engine/Public/EngineInterface.h"

class COGBoxShape: public COGShape
{
public:
	COGBoxShape(GameObject* pGO, float fWidth, float fHeight, exColor color);

	virtual ComponentType GetType() const;
	virtual void Render(exEngineInterface* pEngine) override;
	float GetWidth();
	float GetHeight();


private:
	float mWidth;
	float mHeight;
	exColor mColor;
};

