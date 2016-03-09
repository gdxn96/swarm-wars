#pragma once 
#include "Pylon.h"
#include "Polygon.h"
#include "line.h"
class Bolt
{
public:
	Bolt(Pylon* left, Pylon* right);
	void update(float dt);
	void draw(sf::RenderWindow& window);

	bool containsPylon(Pylon * node);
	void kill();
private:
	bool m_alive;
	Pylon* m_nodeLeft;
	Pylon* m_nodeRight;
	std::vector<Line *> CreateArk(Vector2D & start, Vector2D & end, float thickness);
	std::vector<Line *> listOfLines;
	float timeUntillChange;
	float const TIME_UNTIL_CHANGE;
	float alpha = 255;
	float thickness = 2;
	
};
