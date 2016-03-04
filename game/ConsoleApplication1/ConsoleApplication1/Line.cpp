#include "stdafx.h"
#include "Line.h"
#include "LightManager.h"

Line::Line(void)
{}
Line::Line(Vector2D & _start, Vector2D & _end, float _thickness)
{
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
	LightManager::getInstance()->AddLight("line", start.toSFMLVector(), sf::Vector2f(0.039f, 0.039f), sf::Color(255, 0, 255, alpha), Vector2D(0, 0), 0, nullptr, "spotLight");


}
void Line::Update()
{
	distance = -Vector2D::Distance(start, end);
	angle = Vector2D::AngleDeg(start, end);
	line = sf::RectangleShape(sf::Vector2f(distance, thickness));
	line.setPosition(start.toSFMLVector());
	line.setRotation(angle);
	line.setFillColor(sf::Color(255,0,255,alpha));
	//LightManager::getInstance()->updateLightByID("line", start, Vector2D(0.19f, 0.19f), sf::Color(0, 0, 255, alpha));
}
void Line::setAlpha(float & _alpha)
{
	alpha = _alpha;
}
void Line::Draw(sf::RenderWindow & _window)
{
	_window.draw(line,sf::BlendAdd);
}

Line::~Line(void)
{

}
