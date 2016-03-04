#include "stdafx.h"
#include "LightManager.h"
#include "AssetLoader.h"
LightManager * LightManager::instance = nullptr;

LightManager::LightManager() :
TIME_UNTIL_CHANGE(0.005f)
{
	timeUntillChange = TIME_UNTIL_CHANGE;
	lightMapTexture.create(1920, 1080); // Make a lightmap that can cover our screen
	lightmap.setTexture(lightMapTexture.getTexture());
	lightmap.setTextureRect(sf::IntRect(0, 0, 1920, 1080)); // What from the lightmap we will draw
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

void LightManager::updateLightByID(std::string name, Vector2D _position, Vector2D _scale, sf::Color _color)
{
	for (int i = 0; i < lights.size(); i++)
	{
		if (lights[i]->id == name)
		{
			//lights[i]->position = _position.toSFMLVector();
			lights[i]->scale = _scale.toSFMLVector();
			lights[i]->color = _color;
			
		}
	}
}
void LightManager::Update(sf::RenderWindow & window,float dt)
{
	timeUntillChange -= dt;
	for (int i = 0; i < lights.size(); i++)
	{
		lights[i]->Update(dt);
	}
	lightMapTexture.clear(sf::Color(80, 80, 80));
	for (int i = 0; i < lights.size(); ++i)
	{
		
		if (lights[i]->getAlive())
		{
			lightMapTexture.draw(lights[i]->GetSprite(), sf::BlendAdd);
			 // This blendmode is used so the black in our lightimage won't be drawn to the lightmap
		}
		else
		{
			delete lights[i];
			lights.erase(lights.begin() + i);
		}
	}
	for (int i = 0; i < lights.size(); ++i)
	{
		if (lights[i]->getParent() != nullptr && lights[i]->getParent()->getAlive() == false)
		{
			delete lights[i];
			lights.erase(lights.begin() + i);
		}
	}

	
	if (timeUntillChange <= 0)
	{
		alpha -= 12;
		for (int i = 0; i < lights.size(); ++i)
		{
			if (lights[i]->id == "line")
			{
				lights[i]->color.a = alpha;
			}
		}
		timeUntillChange = TIME_UNTIL_CHANGE;
	}

	if (alpha <= 0)
	{
		alpha = 255;
		for (int i = 0; i < lights.size(); ++i)
		{
			if (lights[i]->id == "line")
			{
				delete lights[i];
				lights.erase(lights.begin() + i);
			}
		}
	}
	 // Where on the backbuffer we will draw
	// This blendmode is used to add the darkness from the lightmap with the parts where we draw ur light image show up brighter
	// Display the backbuffer
	
}
void LightManager::draw(sf::RenderWindow & window)
{
	window.draw(lightmap, sf::BlendMultiply);
	lightMapTexture.display();
}
void LightManager::AddLight(std::string id, sf::Vector2f position, sf::Vector2f scale, sf::Color color, Vector2D _velocity,float rotation ,Bullet * _parent,string lightKey)
{
	lights.push_back(new Light(id, position, scale, color, _velocity,rotation,_parent,lightKey));
}
LightManager::~LightManager(void)
{
}
