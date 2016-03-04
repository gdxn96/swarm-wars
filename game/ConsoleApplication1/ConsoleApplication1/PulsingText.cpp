#include "stdafx.h"
#include "PulsingText.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>

PulsingText::PulsingText()
{
}



PulsingText::PulsingText(std::string _text, Vector2D _position, float min, float fluxSpeed, std::string fontFilePath) :
m_minAlpha(min),
text(_text),
m_position(_position),
m_maxAlpha(255),
m_fluxSpeed(fluxSpeed),
m_currentAlpha(255)
{
	font.loadFromFile("stoNe.ttf");
	m_text.setFont(font);
	m_text.setString(_text);
	m_text.setPosition(_position.toSFMLVector());
	c.r = 135;
	c.g = 206;
	c.b = 250;
	c.a = m_currentAlpha;
}
void PulsingText::update(float dt)
{
	if (m_minAlpha != 255)
	{
		sf::Time elapsedTime = clock.getElapsedTime();
		if (m_currentAlpha <= m_minAlpha)
		{
			m_currentAlpha = m_minAlpha + 1;
			direction = m_fluxSpeed;
		}
		else if (m_currentAlpha >= m_maxAlpha)
		{
			m_currentAlpha = 254;
			direction = -m_fluxSpeed;
		}
		if (elapsedTime > sf::milliseconds(0.1f))
		{
			m_currentAlpha += direction;
			clock.restart();
		}
	}
	m_text.setColor(sf::Color(c.r, c.g, c.b, m_currentAlpha));
	m_text.setPosition(m_position.toSFMLVector());
}

void PulsingText::draw(sf::RenderWindow & window)
{
	window.draw(m_text);
}

void PulsingText::setText(std::string text)
{
	m_text.setString(text);
}

void PulsingText::setColor(sf::Color color)
{
	c = color;
}
void PulsingText::setPosition(Vector2D pos)
{
	m_position = pos;
}

PulsingText::~PulsingText()
{
}
