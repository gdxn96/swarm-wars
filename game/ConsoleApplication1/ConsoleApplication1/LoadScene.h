#pragma once

#include "Scene.h"
#include "PhysicsObject.h"

class LoadScene : public Scene
{
public:
	LoadScene();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;

	//can be overrided
	//void exit();
	//void enter();

private:
	int loadAssets();
	int amount;
};
