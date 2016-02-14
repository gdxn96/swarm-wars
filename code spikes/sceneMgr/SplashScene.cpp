#include "stdafx.h"
#include "SplashScene.h"

SplashScene::SplashScene() : Scene(Scenes::SPLASH)
{

}

void SplashScene::update()
{
	if (alive)
	{
		cout << "Splash Active" << endl;
	}

	//just so my console doesn't get flooded
	alive = false;
}

void SplashScene::draw(){}