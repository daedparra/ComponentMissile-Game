#include "COGCircleShape.h"
#include "COGTransform.h"

COGCircleShape::COGCircleShape(GameObject * pGO, float fRadius)
	: COGShape(pGO)
	, mRadius(fRadius)
{
}


ComponentType COGCircleShape::GetType() const
{
	return ComponentType::CircleShape;
}

void COGCircleShape::Render(exEngineInterface* pEngine)
{
	exColor c;
	c.mColor[0] = 255;
	c.mColor[1] = 255;
	c.mColor[2] = 255;
	c.mColor[3] = 255;

	exVector2 myPosition = mGO->FindComponent<COGTransform>(ComponentType::Transform)->GetPosition();



	pEngine->DrawCircle(myPosition, mRadius, c, 0);
}

float COGCircleShape::GetRadius()
{
	return mRadius;
}
