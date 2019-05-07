#include "COGShape.h"

std::vector<COGShape*> COGShape::mShapeComponents;

COGShape::COGShape(GameObject* pGO): Component(pGO)
{
}


void COGShape::Initialize()
{
	AddToComponentVector(mShapeComponents);
}

void COGShape::Destroy()
{
	RemoveFromComponentVector(mShapeComponents);
}
