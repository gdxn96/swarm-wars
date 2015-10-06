#pragma once
#include <SFML/Graphics.hpp>
class Light
{
public:

	Light(sf::Vector2f ,sf::Vector2f ,sf::Color,sf::Vector2f);
	~Light(void);
	Light();
	void Update(sf::Vector2f ,sf::Vector2f ,sf::Color );
	void Update();
	sf::Sprite GetSprite();
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Color color;
private:
	sf::Vector2f velocity;
	sf::Texture lightTexture;
	sf::Sprite sprite;
};

