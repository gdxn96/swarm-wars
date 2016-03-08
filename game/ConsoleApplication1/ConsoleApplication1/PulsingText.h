#pragma once
#include "SFML/Graphics.hpp"
#include "Vector2D.h"
#include "GameConstants.h"

class PulsingText
{
public:
	PulsingText(std::string _text, Vector2D _position, float min, float speed);
	void update(float dt);
	void draw(sf::RenderWindow & window);
	void setText(std::string  text);
	void setColor(sf::Color color);
	void setPosition(Vector2D pos);
private:
	sf::Font * font;
	sf::Text m_text;
	Vector2D m_position;
	float m_currentAlpha,m_maxAlpha,m_minAlpha,m_fluxSpeed;
	std::string text;
	sf::Clock clock;
	int direction;
	sf::Color c;
	
};

