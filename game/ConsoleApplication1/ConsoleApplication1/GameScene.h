#pragma once

#include "Scene.h"

class GameScene : public Scene
{
public:
	GameScene();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;

	//local method to game scene that needs to be addressed, no implementation
	void pause();
	

	//can be overrided
	//void exit();
	//void enter();

private:


};
