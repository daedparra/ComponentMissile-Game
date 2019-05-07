//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.h
// definition of MyGame, an implementation of exGameInterface
//

#include "Game/Public/GameInterface.h"
#include "Engine/Public/EngineTypes.h"
#include "Game/Private/Components/Paddle.h"
#include "Game/Private/Components/Ball.h"
#include "Game/Private/COGComponents/World.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

class MyGame : public exGameInterface
{
public:

								MyGame();
	virtual						~MyGame();

	virtual void				Initialize( exEngineInterface* pEngine );

	virtual const char*			GetWindowName() const;
	virtual void				GetClearColor( exColor& color ) const;

	virtual void				OnEvent( SDL_Event* pEvent );
	virtual void				OnEventsConsumed();

	virtual void				Run( float fDeltaT );

	exEngineInterface*			getmEngine();

private:

	exEngineInterface*			mEngine;
	int							mFontID;
	World*						mWorld;

	Paddle*						mLeftPaddle;
	Paddle*						mRightPaddle;

	Ball*						mBall;
	exVector2					mBallPosition;

	exVector2					mPlayer1Position1;
	exVector2					mPlayer1Position2;

	exVector2					mPlayer2Position1;
	exVector2					mPlayer2Position2;


	exVector2					mPlayer1Score;
	exVector2					mPlayer2Score;

	bool						mUp;
	bool						mDown;
	bool						mW;
	bool						mS;

	exVector2					mTextPosition;

};
