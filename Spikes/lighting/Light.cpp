#include "stdafx.h"
#include "Light.h"

Light::Light(sf::Vector2f pos,sf::Vector2f s,sf::Color c, sf::Vector2f v)
{
	lightTexture.loadFromFile("biglight.png"); // Load in our light 
	lightTexture.setSmooth(true); // (Optional) It just smoothes the light out a bit
	sprite.setTexture(lightTexture); // Make our lightsprite use our loaded image
	sprite.setTextureRect(sf::IntRect(0, 0, 512, 512)); // Set where on the image we will take the sprite (X position, Y position, Width, Height)
	sprite.setOrigin(256.f, 256.f); // This will offset where we draw our ligts so the center of the light is right over where we want our light to be
	position = pos;
	scale = s;
	color = c;
	velocity = v;
}
void Light::Update(sf::Vector2f pos,sf::Vector2f s,sf::Color c)
{
	position = pos;
	scale = s;
	color = c;
}
void Light::Update()
{
	position += velocity;
}
sf::Sprite Light::GetSprite()
{
	return sprite;
}
Light::~Light(void)
{
}
