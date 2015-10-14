#pragma once

#include "Scene.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	void update() override;
	void draw() override;

	//can be overrided
	//void exit();
	//void enter();

private:


};
