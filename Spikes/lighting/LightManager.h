#pragma once
#include <SFML/Graphics.hpp>
#include "Light.h"
class LightManager
{
public:
	LightManager(void);
	~LightManager(void);
	void Update(sf::RenderWindow & ,sf::Vector2f);
	void AddLight(Light);
private:
	sf::RenderTexture lightMapTexture;
	sf::Sprite lightmap;
	sf::Sprite loadedSprite;
	sf::Texture lightTexture;
	std::vector<Light> lights;
};

