#include "COGTransform.h"

COGTransform::COGTransform(GameObject * pGO, exVector2 position): Component(pGO)
{
	mPosition = position;
}

ComponentType COGTransform::GetType() const
{
	return ComponentType::Transform;
}

exVector2 & COGTransform::GetPosition()
{
	return mPosition;
}

void COGTransform::SetPosition(exVector2 position)
{
	mPosition = position;
}
