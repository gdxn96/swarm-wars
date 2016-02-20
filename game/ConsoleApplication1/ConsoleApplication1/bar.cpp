#include "stdafx.h"
#include "bar.h"
#include "LightManager.h"

bar::bar()
{
}

bar::bar(Vector2D _position, Vector2D _scale,float startingValue) :
m_position(_position),
scale(_scale),
m_max(startingValue),
m_current(startingValue)
{
	//bgRect.setFillColor(sf::Color::Blue);
	bgTexture = AssetLoader::getInstance()->findTextureByKey("BGbar");
	fgTexture = AssetLoader::getInstance()->findTextureByKey("FGBar");
	bgRect.setTexture(bgTexture);
	fgRect.setTexture(fgTexture);
	
	percentAmount = (m_max / m_current) * 100;

}
void bar::update()
{
	bgRect.setPosition(m_position.toSFMLVector());
	fgRect.setPosition(m_position.toSFMLVector());
	bgRect.setSize(sf::Vector2f((width +4)*scale.x , height*scale.y));
	percentAmount = (m_max / m_current) * 100;
	fgRect.setSize(sf::Vector2f((width*scale.x)*(percentAmount / 100), height*scale.y));
}
void bar::setBarAmount(float _amount)
{
	m_current += _amount;
}
void bar::setPosition(Vector2D _pos)
{
	m_position = _pos;
}
void bar::draw(sf::RenderWindow & window)
{
	window.draw(bgRect);
	window.draw(fgRect);
}

bar::~bar()
{
}
