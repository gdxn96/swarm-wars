#pragma once 
#include "Pylon.h"
#include "Polygon.h"

class Bolt
{
public:
	Bolt(Pylon* left, Pylon* right);
	void update(float dt);
	void draw(sf::RenderWindow& window);
	void kill();
private:
	bool m_alive;
	Pylon* m_nodeLeft;
	Pylon* m_nodeRight;
};
