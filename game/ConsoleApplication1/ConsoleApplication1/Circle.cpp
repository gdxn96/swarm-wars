#include "stdafx.h"
#include "Circle.h"
#include "AssetLoader.h"

Circle::Circle()
{

}

Circle::Circle(Vector2D centre, float radius) : m_radius(radius), m_centre(centre)
{
	circle = sf::CircleShape(m_radius);
	circle.setPosition(centre.toSFMLVector());
}

void Circle::setCentre(Vector2D centre)
{
	m_centre = centre;
}

void Circle::setRadius(float radius)
{
	m_radius = radius;
	circle.setRadius(radius);
}

float Circle::getRadius()
{
	return m_radius;
}

Vector2D Circle::getCentre()
{
	return m_centre;
}

void Circle::setTexture(sf::Texture * _texture)
{
	circle.setTexture(_texture);
}

void Circle::draw(sf::RenderWindow & window)
{
	circle.setOrigin(m_radius, m_radius);
	circle.setTexture(AssetLoader::getInstance()->findTextureByKey("grenade"));
	window.draw(circle);
}

void Circle::setAlpha(float a)
{
	sf::Color temp = circle.getFillColor();
	temp.a = a;
	circle.setFillColor(temp);
}