#include "COGBoxShape.h"
#include "COGTransform.h"

COGBoxShape::COGBoxShape(GameObject * pGO, float fWidth, float fHeight, exColor color)
	:COGShape(pGO)
	, mWidth(fWidth)
	, mHeight(fHeight)
{
	mColor = color;
}

ComponentType COGBoxShape::GetType() const
{
	return ComponentType::BoxShape;
}

void COGBoxShape::Render(exEngineInterface* pEngine)
{	
	COGTransform* pTransform = mGO->FindComponent<COGTransform>(ComponentType::Transform);
	exVector2 myPosition = pTransform->GetPosition();

	exVector2 p1, p2;
	p1.x = myPosition.x + (mWidth * 0.5f);
	p1.y = myPosition.y + (mHeight * 0.5f);
	p2.x = myPosition.x - (mWidth * 0.5f);
	p2.y = myPosition.y - (mHeight * 0.5f);

	pEngine->DrawBox(p1, p2, mColor, 0);
	
}

float COGBoxShape::GetWidth()
{
	return mWidth;
}

float COGBoxShape::GetHeight()
{
	return mHeight;
}
