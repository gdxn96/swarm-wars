#pragma once

#include "Scene.h"

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;

	//can be overrided
	//void exit();
	//void enter();

private:


};
