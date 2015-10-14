#include "stdafx.h"
#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() : Scene(Scenes::MAINMENU)
{

}

void MainMenuScene::update()
{
	if (alive)
	{
		cout << "Main Menu Active" << endl;
	}

	//just so my console doesn't get flooded
	alive = false;
}

void MainMenuScene::draw()
{

}