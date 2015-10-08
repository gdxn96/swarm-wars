#pragma once

#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	void enter();
	void update();
	void exit();
	void pause();
	void draw();
	const Scenes getTitle();

private:


};
