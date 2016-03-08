#pragma once
#include "Vector2D.h"
#include "SFML\Graphics.hpp"
#include "AssetLoader.h"
class bar
{
public:
	
	float width = 100, height = 5;
	int offset = 3;

	Vector2D m_position;
	bar(Vector2D _position, Vector2D scale, float startingValue,sf::Color,sf::Color);
	sf::RectangleShape bgRect,fgRect;
	sf::CircleShape point;
	void draw(sf::RenderWindow &);
	void remove(float);
	void setPosition(Vector2D);
	void setBarAmount(float);
	void setPercentAmount(float);
	void setCurrentAmount(float);
	void setScale(Vector2D);
	void update();
	sf::Texture * bgTexture, * fgTexture;
	void setColor(sf::Color);
	void setFGColor(sf::Color);
	void setBGColor(sf::Color);
	float getAmount();
	void setAlpha(float _alpha);
private:
	sf::Color fgColor;
	sf::Color bgColor;
	float m_max, m_current, percentAmount;
	float m_amount = 0;
	Vector2D scale;
	float alpha;
};

