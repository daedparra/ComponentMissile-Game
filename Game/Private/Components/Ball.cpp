#include "Ball.h"

#include "Engine/Public/EngineTypes.h"
#include "Engine/Public/EngineInterface.h"
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;
// Constructor
Ball::Ball(exVector2 mPosition, exColor mColor, float mSpeed, Paddle* mPlayer1, Paddle* mPlayer2, exEngineInterface* mEngine)
{
	this->mBallCenter = mPosition;
	this->mBallColor = mColor;
	this->mEngine = mEngine;

	// Paddles
	this->mPlayer1 = mPlayer1;
	this->mPlayer2 = mPlayer2;

	mSpeedX = mSpeed;
	mSpeedY = mSpeed * -1;

	srand(time(NULL));
}

// Destructor
Ball::~Ball()
{
}

float Ball::getspeedX() {
	return mSpeedX;
}
float Ball::getspeedY() {
	return mSpeedY;
}

void Ball::setspeedX(float x) {
	mSpeedX=x;
}
void Ball::setspeedY(float y) {
	mSpeedY=y;
}

void Ball::render()
{
	mEngine->DrawCircle(mBallCenter, radius, mBallColor, 1);
}

void Ball::renderBall(float time, Paddle* Player1, Paddle* Player2)
{
	
	if (mBallCenter.y < radius)
	{
		mSpeedY *= -1;

	}
	else if (mBallCenter.y > kViewportHeight)
	{
		mSpeedY *= -1;

	}
	if (mBallCenter.x < radius)
	{
		mPlayer2Score++;
		this->resetBall();
	}
	else if (mBallCenter.x > kViewportWidth)
	{
		mPlayer1Score++;
		this->resetBall();
	}
	if (mBallCenter.x > Player1->getmPaddleLeftVecX() + 9.0f && mBallCenter.x < Player1->getmPaddleRightVecX())
	{
		if (mBallCenter.y > Player1->getmPaddleLeftVecY() && mBallCenter.y < Player1->getmPaddleRightVecY())
		{
			mSpeedX *= -1;
		}
	}
	if (mBallCenter.x < Player2->getmPaddleLeftVecX() + 9.0f && mBallCenter.x > Player2->getmPaddleRightVecX())
	{
		if (mBallCenter.y > Player2->getmPaddleLeftVecY() && mBallCenter.y < Player2->getmPaddleRightVecY())
		{
			mSpeedX *= -1;
		}

	}

	mBallCenter.x += mSpeedX * time;
	mBallCenter.y += mSpeedY * time;

}

void Ball::resetBall()
{
	mBallCenter.x = kViewportWidth  / 2;
	mBallCenter.y = kViewportHeight / 2;


	mSpeedX = 250;
	mSpeedY = 250;
	mSpeedX *= rand() % 3 - 1;
	if (mSpeedX == 0)
	{
		mSpeedX = rand() % 275 + 320;
	}
	mSpeedY *= rand() % 3 - 1;
	if (mSpeedY == 0)
	{
		mSpeedY = rand() % 250 + 450;
	}
}



// Getters
exVector2 Ball::getCenter()
{
	return mBallCenter;
}

int Ball::getPlayer1Score()
{
	return mPlayer1Score;
}

int Ball::getPlayer2Score()
{
	return mPlayer2Score;
}



float Ball::getRadius()
{
	return radius;
}


// Setters
void Ball::setPlayer1Score(int score) {
	mPlayer1Score = score;
}
void Ball::setPlayer2Score(int score) {
	mPlayer2Score = score;
}

void Ball::setP1(exVector2 center)
{
	this->mBallCenter = center;
}

void Ball::setRadius(float r)
{
	this->radius = r;
}

