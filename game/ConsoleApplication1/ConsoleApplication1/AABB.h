#pragma once
#include "Vector2D.h"
#include <SFML\Graphics.hpp>
#include "Circle.h"
class AABB
{
public:
	AABB(Vector2D _position, float width, float height);
	AABB(float, float, float, float);
	AABB();
	~AABB();
	bool Contains(Vector2D & point);
	bool Contains(AABB & box);
	bool Contains(Circle & circle);
	bool Intersects(AABB * box);
	void Update();
	void Draw(sf::RenderWindow & window);
	float GetX();
	float GetY();
	float GetWidth();
	float GetHeight();
	float left, right, top, bottom;
	sf::Color color = sf::Color::Red;
	Vector2D position;
	bool draw = true;
private:
	
	float width;
	float height;
};

