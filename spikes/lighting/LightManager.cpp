#include "stdafx.h"
#include "LightManager.h"


LightManager::LightManager(sf::Vector2f position, sf::Vector2f scale,sf::Color color)
{
	lightMapTexture.create(1920, 1080); // Make a lightmap that can cover our screen
	lightmap.setTexture(lightMapTexture.getTexture()); // Make our lightmap sprite use the correct texture
	lightTexture.loadFromFile("biglight.png"); // Load in our light 
	lightTexture.setSmooth(true); // (Optional) It just smoothes the light out a bit
	light.setTexture(lightTexture); // Make our lightsprite use our loaded image
	light.setTextureRect(sf::IntRect(0, 0, 512, 512)); // Set where on the image we will take the sprite (X position, Y position, Width, Height)
	light.setOrigin(256.f, 256.f); // This will offset where we draw our ligts so the center of the light is right over where we want our light to be
}
void LightManager::Update(sf::RenderWindow & window,sf::Vector2f  position)
{
	lightMapTexture.clear(sf::Color(50,50,80));

	// Loop over the lights in the vector
	for (std::size_t i = 0; i < lights.size(); ++i)
	{
		lights[i].Update();
		// Set the attributes of the light sprite to those of the current light
		light.setScale(lights[i].scale);
		light.setColor(lights[i].color);
		light.setPosition(lights[i].position);
		//Draw it to the lightmap
		lightMapTexture.draw(light, sf::BlendAdd); // This blendmode is used so the black in our lightimage won't be drawn to the lightmap
	}
	lightmap.setTextureRect(sf::IntRect(0, 0, 1920, 1080)); // What from the lightmap we will draw
	lightmap.setPosition(0, 0); // Where on the backbuffer we will draw
	window.draw(lightmap, sf::BlendMultiply); // This blendmode is used to add the darkness from the lightmap with the parts where we draw ur light image show up brighter
	window.display(); // Display the backbuffer
	lightMapTexture.display();
}
sf::Sprite LightManager::getLightMap()
{
	return lightmap;
}
void LightManager::AddLight(sf::Vector2f position, sf::Vector2f scale,  sf::Color color,sf::Vector2f v)
{
	lights.push_back(Light(position, scale,  color,v));
}
LightManager::~LightManager(void)
{
}
