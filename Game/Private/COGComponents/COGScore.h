#pragma once

#include "Engine/Public/EngineInterface.h"
#include "COGShape.h"


class COGScore : public COGShape
{
public: 
	COGScore(GameObject* pGO, exVector2 position,int font, int score, exColor color, int flag);
    virtual ComponentType GetType() const;
    virtual void Render(exEngineInterface* pEngine) override;

	int GetScore();
	void SetScore(int score);

private:

    int mFontID;
	int mFlag;
	int mScore;
	GameObject* mGo;
	exVector2 mPosition;
    exColor mColor;
};