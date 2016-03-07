#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
class Light
{
public:

	Light(std::string id, Vector2D pos, Vector2D scale, sf::Color, Vector2D velocity,float rotation,std::string lightkey);

	void Update(float);

	void setPosition(Vector2D);
	void setIsAlive(bool);
	void setScale(Vector2D);
	void setColor(sf::Color);
	void setID(std::string);
	void setAlpha(float);

	Vector2D getScale();
	bool getAlive();
	sf::Sprite getSprite();
	Vector2D getPosition();
	sf::Color getColor();
	std::string getID();
	float getAlpha();
	
private:
	Vector2D scale;
	Vector2D position;
	sf::Color color;
	std::string id;
	sf::Sprite sprite;
	Vector2D velocity;
	float m_rotation;
	bool m_alive;
	//Bullet * parent;
	float alpha;
	bool isFlickering;
	sf::Clock clock;
	int swapAmount = -1;
};

