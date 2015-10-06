#include "stdafx.h"
#include "LightManager.h"


LightManager::LightManager(void)
{
	lightMapTexture.create(1920, 1080); // Make a lightmap that can cover our screen
	lightmap.setTexture(lightMapTexture.getTexture()); // Make our lightmap sprite use the correct texture

}
void LightManager::Update(sf::RenderWindow & window,sf::Vector2f position)
{
	lightMapTexture.clear(sf::Color(50,50,80));
	lightTexture.loadFromFile("biglight.png"); // Load in our light 
	lightTexture.setSmooth(true); // (Optional) It just smoothes the light out a bit
	loadedSprite.setTexture(lightTexture); // Make our lightsprite use our loaded image
	loadedSprite.setTextureRect(sf::IntRect(0, 0, 512, 512)); // Set where on the image we will take the sprite (X position, Y position, Width, Height)
	loadedSprite.setOrigin(256.f, 256.f);
	// Loop over the lights in the vector
	//for (std::size_t i = 0; i < lights.size(); ++i)
	//{
	lightMapTexture.draw(loadedSprite, sf::BlendAdd); // This blendmode is used so the black in our lightimage won't be drawn to the lightmap
	//}
	lightmap.setTextureRect(sf::IntRect(0, 0, 1920, 1080)); // What from the lightmap we will draw
	lightmap.setPosition(0, 0); // Where on the backbuffer we will draw
	window.draw(lightmap, sf::BlendMultiply); // This blendmode is used to add the darkness from the lightmap with the parts where we draw ur light image show up brighter
	window.display(); // Display the backbuffer
	lightMapTexture.display();
}
void LightManager::AddLight(Light light)
{
	loadedSprite = light.GetSprite();
	lights.push_back(light);
}
LightManager::~LightManager(void)
{
}
