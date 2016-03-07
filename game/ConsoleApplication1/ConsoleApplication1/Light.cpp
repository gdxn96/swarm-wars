#include "stdafx.h"
#include "Light.h"
#include "AssetLoader.h"

Light::Light(std::string _id, Vector2D pos, Vector2D s, sf::Color c, Vector2D _velocity, float rotation, std::string lightKey)
{   
	// (Optional) It just smoothes the light out a bit
	sprite.setTexture(*AssetLoader::getInstance()->findTextureByKey(lightKey)); // Make our lightsprite use our loaded image
	sprite.setTextureRect(sf::IntRect(0, 0, 512, 512)); // Set where on the image we will take the sprite (X position, Y position, Width, Height)
	sprite.setOrigin(256, 256); // This will offset where we draw our ligts so the center of the light is right over where we want our light to be
	position = pos;
	scale = s;
	color = c;
	id = _id;
	velocity = _velocity;
	m_rotation = rotation;
	sprite.setColor(c);
	sprite.setRotation(rotation);
	sprite.setScale(s.toSFMLVector());
	sprite.setPosition(pos.toSFMLVector());
	alpha = sprite.getColor().a;
	m_alive = true;
}
void Light::Update(float dt)
{
	sf::Time elapsedTime = clock.getElapsedTime();
	position += velocity * dt;
	float w = sprite.getTextureRect().width/2;
	sprite.setOrigin(150, 150);
	sprite.setPosition(position.toSFMLVector());
	color.a = alpha;
	sprite.setColor(color);
	sprite.setScale(scale.toSFMLVector());
}

void Light::setIsAlive(bool _isAlive)
{
	m_alive = _isAlive;
}

sf::Sprite Light::getSprite()
{
	return sprite;
}

bool Light::getAlive()
{
	return m_alive;
}
Vector2D Light::getScale()
{
	return scale;
}

Vector2D Light::getPosition()
{
	return position;
}

sf::Color Light::getColor()
{
	return color;
}
std::string Light::getID()
{
	return id;
}
float Light::getAlpha()
{
	return alpha;
}

void Light::setScale(Vector2D _scale)
{
	scale = _scale;
}

void Light::setPosition(Vector2D _position)
{
	position = _position;
}

void Light::setColor(sf::Color _color)
{
	color = _color;
}

void Light::setID(std::string _id)
{
	id = _id;
}

void Light::setAlpha(float _alpha)
{
	alpha = _alpha;
}