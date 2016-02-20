#include "stdafx.h"
#include "Light.h"
#include "AssetLoader.h"

Light::Light(std::string _id, sf::Vector2f pos, sf::Vector2f s, sf::Color c, Vector2D _velocity, float rotation, Bullet * _parent, string lightKey)
{   
	// (Optional) It just smoothes the light out a bit
	sprite.setTexture(*AssetLoader::getInstance()->findTextureByKey(lightKey)); // Make our lightsprite use our loaded image
	sprite.setTextureRect(sf::IntRect(0, 0, 512, 512)); // Set where on the image we will take the sprite (X position, Y position, Width, Height)
	sprite.setOrigin(256.f, 256.f); // This will offset where we draw our ligts so the center of the light is right over where we want our light to be
	position = pos;
	scale = s;
	color = c;
	id = _id;
	velocity = _velocity;
	m_rotation = rotation;
	sprite.setColor(c);
	sprite.setRotation(rotation);
	sprite.setScale(s);
	sprite.setPosition(pos);
	alpha = sprite.getColor().a;
	parent = _parent;
	
}
void Light::Update(float dt)
{
	sf::Time elapsedTime = clock.getElapsedTime();
	position += velocity.toSFMLVector() * dt;
	float w = sprite.getTextureRect().width/2;
	sprite.setOrigin(150, 150);
	sprite.setPosition(position);
	sprite.setColor(color);
	sprite.setScale(scale);
	if (id == "flicker")
	{
		if (elapsedTime >= sf::microseconds(1000000))
		{
			if (swapAmount == -1)
			{
				swapAmount == 1;
				alpha += 100;
			}
			else
			{
				swapAmount = -1;
				alpha -= 100;
			}
			clock.restart();
		}
		
	}
	if (parent != nullptr)
	{
		m_alive = parent->getAlive();
	}
	else
	{
		m_alive = true;
	}
	sf::Color temp = sprite.getColor();
	temp.a = alpha;
	sprite.setColor(temp);
}

void Light::setIsAlive(bool _isAlive)
{
	m_alive = _isAlive;
}

bool Light::getAlive()
{
	return m_alive;
}

sf::Sprite Light::GetSprite()
{
	return sprite;
}
Light::~Light(void)
{
}
