#pragma once
#include "Vector2D.h"
#include <SFML/Graphics.hpp>
#include "Light.h"
class Line
{
public:
	Line(Vector2D & start,Vector2D & end,float thickness);
	void Update();
	void Draw(sf::RenderWindow & _window);
	void setAlpha(float &);
	void setAlive(bool);
	bool getAlive();
private:
	float thickness;
	float alpha;
	float distance,angle;
	Vector2D start,end;
	sf::RectangleShape line;
	sf::Texture texture;
	sf::Clock clock;
	Light * m_light;
	bool isAlive;
	float timeUntillChange;
	float const TIME_UNTIL_CHANGE;
};

