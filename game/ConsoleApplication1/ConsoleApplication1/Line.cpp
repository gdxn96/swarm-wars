#include "stdafx.h"
#include "Line.h"
#include "LightManager.h"

Line::Line(Vector2D & _start, Vector2D & _end, float _thickness) :
TIME_UNTIL_CHANGE(0.005f),
m_light(nullptr)
{
	timeUntillChange = TIME_UNTIL_CHANGE;
	alpha = 255;
	//texture.loadFromFile("line.png");
	//texture.setSmooth(true);
	start = _start;
	end = _end;
	thickness = _thickness;
	distance = -Vector2D::Distance(_start,_end);
	angle = Vector2D::AngleDeg(_start,_end);
	line = sf::RectangleShape(sf::Vector2f(distance,thickness));
	line.setPosition(_start.toSFMLVector());
	line.setRotation(angle);
	line.setFillColor(sf::Color(255, 0, 255, alpha));
	//line.setTexture(& texture);
	m_light = new Light("line", start, Vector2D(0.049f, 0.049f), sf::Color(255, 0, 255, alpha), Vector2D(0, 0), 0, "spotLight");
	LightManager::getInstance()->AddLight(m_light);
	isAlive = true;

}
void Line::Update()
{
	distance = -Vector2D::Distance(start, end);
	angle = Vector2D::AngleDeg(start, end);
	line = sf::RectangleShape(sf::Vector2f(distance, thickness));
	line.setPosition(start.toSFMLVector());
	line.setRotation(angle);
	line.setFillColor(sf::Color(255,0,255,alpha));

	m_light->setAlpha(alpha);
}
void Line::setAlpha(float & _alpha)
{
	alpha = _alpha;
}
void Line::Draw(sf::RenderWindow & _window)
{
	if (isAlive)
	_window.draw(line,sf::BlendAdd);
}
void Line::setAlive(bool _alive)
{
	isAlive = _alive;
	if (m_light != nullptr)
	m_light->setIsAlive(_alive);
	m_light = nullptr;
}

bool Line::getAlive()
{
	return isAlive;
}
