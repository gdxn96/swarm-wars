#include "stdafx.h"
#include "AABB.h"

AABB::AABB()
{

}
AABB::AABB(float _x, float _y, float _width, float _height):
position(Vector2D(_x, _y)), width(_width), height(_height)
{
	top = _x;
	bottom = _x + _height;
	left = _y;
	right = _y + _width;
	width = _width;
	height = _height;
}
AABB::AABB(Vector2D _position, float _width,float _height):
position(_position), width(_width), height(_height)
{
	top = _position.x;
	bottom = _position.x + _height;
	left = _position.y;
	right = _position.y + _width;
	width = _width;
	height = _height;
}

void AABB::Draw(sf::RenderWindow & _window)
{
	if (draw)
	{
		sf::Vertex line[] =
		{
			sf::Vertex(position.toSFMLVector(), color),
			sf::Vertex(sf::Vector2f(position.x + width, position.y), color),
			sf::Vertex(sf::Vector2f(position.x + width, position.y), color),
			sf::Vertex(sf::Vector2f(position.x + width, position.y + height), color),
			sf::Vertex(sf::Vector2f(position.x + width, position.y + height), color),
			sf::Vertex(sf::Vector2f(position.x, position.y + height), color),
			sf::Vertex(sf::Vector2f(position.x, position.y + height), color),
			sf::Vertex(sf::Vector2f(position.toSFMLVector()), color)
		};
		top = position.x;
		bottom = position.x + height;
		left = position.y;
		right = position.y + width;
		_window.draw(line, 8, sf::Lines);
	}
}
bool AABB::Contains(Circle & _circle)
{
	//if (_circle.position.x + _circle.radius > position.x && _circle.position.x - _circle.radius < position.x + width
	//	&& _circle.position.y + _circle.radius > position.y && _circle.position.y - _circle.radius < position.y + height)
	//{
	//	return true;
	//}
	//else
	//{
		return false;
	//}
}
bool AABB::Intersects(AABB * box)
{
	top = position.x;
	bottom = position.x + height;
	left = position.y;
	right = position.y + width;
	if (position.x < box->position.x+box->width && position.x + width > box->position.x && position.y < box->position.y +box->height && position.y + height > box->position.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool AABB::Contains(Vector2D & point)
{
	return false;
}
float AABB::GetX()
{
	return position.x;
}
float AABB::GetY()
{
	return position.y;
}
float AABB::GetWidth()
{
	return width;
}
float AABB::GetHeight()
{
	return height;
}
AABB::~AABB()
{
}
