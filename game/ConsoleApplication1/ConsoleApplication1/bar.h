#pragma once
#include "Vector2D.h"
#include "SFML\Graphics.hpp"
#include "AssetLoader.h"
class bar
{
public:
	float m_max,m_current,percentAmount;
	float width = 100, height = 10;
	int offset = 3;
	Vector2D m_position, scale;
	bar();
	bar(Vector2D _position, Vector2D scale, float startingValue);
	~bar();
	sf::RectangleShape bgRect,fgRect;
	sf::CircleShape point;
	void draw(sf::RenderWindow &);
	void remove(float);
	void setPosition(Vector2D);
	void setBarAmount(float);
	void setPercentAmount(float);
	void setCurrentAmount(float);
	void update();
	sf::Texture * bgTexture, * fgTexture;
	void setColor(sf::Color);
private:
	sf::Color color;
};

