#include "stdafx.h"
#include "bar.h"
#include "LightManager.h"
bar::bar(Vector2D _position, Vector2D _scale, float startingValue, sf::Color foregroundColor, sf::Color backGroundColor) :
m_position(_position),
scale(_scale),
m_max(startingValue),
m_current(startingValue)
{
	bgTexture = AssetLoader::getInstance()->findTextureByKey("BGBar");
	fgTexture = AssetLoader::getInstance()->findTextureByKey("BGBar");
	bgRect.setTexture(bgTexture);
	fgRect.setTexture(fgTexture);
	bgRect.setFillColor(backGroundColor);
	bgRect.setOutlineColor(sf::Color(255, 215, 0, 255));
	bgRect.setOutlineThickness(1);
	fgRect.setFillColor(foregroundColor);
	percentAmount = (m_max / m_current) * 100;
	bgRect.setSize(sf::Vector2f((width)*scale.x, height*scale.y));
	fgRect.setSize(sf::Vector2f((width*scale.x)*(percentAmount / 100), height*scale.y));
}
void bar::update()
{
	bgRect.setPosition(m_position.toSFMLVector());
	fgRect.setPosition(m_position.toSFMLVector());
	bgRect.setSize(sf::Vector2f((width)*scale.x, height*scale.y));
	fgRect.setSize(sf::Vector2f((width*scale.x)*(percentAmount / 100), height*scale.y));
	if (fgRect.getSize().x <= 0)
	{
		fgRect.setSize(sf::Vector2f(1*scale.x, height*scale.y));
	}
}

float bar::getAmount()
{
	return m_amount;
}


void bar::setScale(Vector2D s)
{
	scale = s;
}

void bar::setBarAmount(float _amount)//change name of method
{
	m_current -= _amount;
	percentAmount = ( m_current/m_max) * 100;
}

void bar::setPercentAmount(float _amount)
{
	percentAmount = _amount;
}
void bar::setCurrentAmount(float _amount)
{
	percentAmount = (_amount / m_max) * 100;

	m_amount = _amount;
}
void bar::setPosition(Vector2D _pos)
{
	m_position = _pos;
}
void bar::setFGColor(sf::Color c)
{
	fgRect.setFillColor(c);
}
void bar::setBGColor(sf::Color c)
{
	bgRect.setFillColor(c);
}
void bar::draw(sf::RenderWindow & window)
{
	window.draw(bgRect);
	window.draw(fgRect);
}

void bar::setAlpha(float _alpha)
{
	alpha = _alpha;
}

