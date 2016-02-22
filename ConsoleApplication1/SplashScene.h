#pragma once

#include "Scene.h"
#include "PhysicsObject.h"

class SplashScene : public Scene
{
public:
	SplashScene();
	void update(float dt);
	void draw(sf::RenderWindow &window);

	//can be overrided
	//void exit();
	//void enter();

private:
	float m_timeToSwitch;
	PhysicsObject object;
};
