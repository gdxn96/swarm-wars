#pragma once
#include "Vector2D.h"
#include <SFML/Graphics.hpp>
class Line
{
public:
	Line(void);
	Line(Vector2D & start,Vector2D & end,float thickness);
	~Line(void);
	void Update();
	void Draw(sf::RenderWindow & _window);
	void setAlpha(float &);
private:
	float thickness;
	float alpha;
	float distance,angle;
	Vector2D start,end;
	sf::RectangleShape line;
	sf::Texture texture;
	sf::Clock clock;
};

