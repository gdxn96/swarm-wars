#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() : Scene(Scenes::GAME)
{

}

void GameScene::update()
{
	if (alive)
	{
		cout << "GameScene Active" << endl;
	}

	//just so my console doesn't get flooded
	alive = false;
}

void GameScene::pause()
{
}

void GameScene::draw()
{
}