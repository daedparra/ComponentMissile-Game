#pragma once
#include "Component.h"


class COGTransform :public Component
{
public:
	COGTransform(GameObject* pGO, exVector2 position);

	virtual ComponentType GetType() const;

	exVector2& GetPosition();
	void SetPosition(exVector2 position);

private:
	exVector2 mPosition;
};

