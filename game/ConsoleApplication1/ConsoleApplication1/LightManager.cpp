#include "stdafx.h"
#include "LightManager.h"
#include "AssetLoader.h"
LightManager * LightManager::instance = nullptr;

LightManager::LightManager() :
TIME_UNTIL_CHANGE(0.005f)
{
	timeUntillChange = TIME_UNTIL_CHANGE;
	lightMapTexture.create(1920, 1880); // Make a lightmap that can cover our screen
	lightmap.setTexture(lightMapTexture.getTexture());
	lightmap.setTextureRect(sf::IntRect(0, 0, 1920, 1880)); // What from the lightmap we will draw
	lightmap.setPosition(0, 0);
	// Make our lightmap sprite use the correct texture

}

LightManager * LightManager::getInstance()
{
	//singleton getter
	if (instance == nullptr)
	{
		instance = new LightManager();
	}
	return instance;
}
void LightManager::clear()
{
	lights.clear();
}


void LightManager::Update(sf::RenderWindow & window,float dt)
{
	lightMapTexture.clear(sf::Color(128, 128, 128));
	killDeadLights();
	for (int i = 0; i < lights.size(); ++i)
	{
		if (lights[i]->getAlive())
		{
			lights[i]->Update(dt);
			lightMapTexture.draw(lights[i]->getSprite(), sf::BlendAdd);
		}	
	}
}

void LightManager::killDeadLights()
{
	for (int i = 0; i < lights.size(); ++i)
	{
		if (!lights[i]->getAlive())
		{
			delete lights[i];
			lights[i] = nullptr;
			lights.erase(lights.begin() + i);
		}
	}
}
void LightManager::draw(sf::RenderWindow & window)
{
	window.draw(lightmap, sf::BlendMultiply);
	lightMapTexture.display();
}
void LightManager::AddLight(Light * _light)
{
	lights.push_back(_light);
}
LightManager::~LightManager(void)
{
}
