#pragma once

#include "Scene.h"

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

};
