#pragma once
#include <SFML/Graphics.hpp>
#include "Light.h"
class LightManager
{
public:
	LightManager(sf::Vector2f,sf::Vector2f,sf::Color);
	~LightManager(void);
	void Update(sf::RenderWindow &,sf::Vector2f);
	void AddLight(sf::Vector2f,sf::Vector2f,  sf::Color,sf::Vector2f);
private:
	std::vector<Light> lights;
	sf::Texture lightTexture;
	sf::Sprite light;
	sf::RenderTexture lightMapTexture;
	sf::Sprite lightmap;
	sf::Sprite getLightMap();
};

