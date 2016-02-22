#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include "Bullet.h"
class Light
{
public:

	Light(std::string id, sf::Vector2f, sf::Vector2f, sf::Color, Vector2D velocity,float rotation, Bullet * _parent,string lightkey);
	~Light(void);
	Light();
	void Update(float);
	sf::Sprite GetSprite();
	sf::Vector2f position;
	sf::Vector2f scale;
	sf::Color color;
	std::string id;
	void setIsAlive(bool);
	bool getAlive();
private:
	sf::Texture lightTexture;
	sf::Sprite sprite;
	Vector2D velocity;
	float m_rotation;
	bool m_alive = true;
	Bullet * parent;
	float alpha;
	bool isFlickering;
	sf::Clock clock;
	int swapAmount = -1;
};

