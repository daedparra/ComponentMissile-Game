#include "COGScore.h"
#include <string>


COGScore::COGScore(GameObject * pGO, exVector2 position, int font, int score, exColor color, int flag): COGShape(pGO)
{
	
	mGo = pGO;
	mPosition = position;
	mFontID = font;
	mColor = color;
	mScore = score;
	mFlag = flag;
}

ComponentType COGScore::GetType() const
{
	return ComponentType::Score;
}

void COGScore::Render(exEngineInterface* pEngine)
{
	// Depending on the flag we render the score
	// to the Left or to the right;

	// We load the font, this is bad think of other solution;
	//mFontID = pEngine->LoadFont("Roboto-Regular.ttf", 32);

	// Converting the Score to string to draw it
	std::string score = std::to_string(mScore);


	
	if (mFlag == 0)
	{	
		// Draw score to the left
		//pEngine->DrawText(mFontID, mPosition, score.c_str(), mColor, 0);
	}
	else
	{
		// Draw Score to the right
		//pEngine->DrawText(mFontID, mPosition, score.c_str(), mColor, 0);
	}
}

int COGScore::GetScore()
{
	return mScore;
}

void COGScore::SetScore(int score)
{
	mScore = score;
}
