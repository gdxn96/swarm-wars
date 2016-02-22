#pragma once

#include "Scene.h"
#include "PhysicsObject.h"

class LoadScene : public Scene
{
public:
	LoadScene();
	void update(float dt);
	void draw(sf::RenderWindow &window);

	//can be overrided
	//void exit();
	//void enter();

private:
	int loadAssets();
	int amount;
};
