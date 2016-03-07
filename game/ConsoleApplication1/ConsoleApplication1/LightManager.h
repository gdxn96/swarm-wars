#pragma once
#include <SFML/Graphics.hpp>
#include "Light.h"
#include "Vector2D.h"
#include "Bullet.h"
class LightManager
{
public:
	static LightManager * getInstance();
	~LightManager(void);
	void Update(sf::RenderWindow &,float);
	void AddLight(Light * light);

	void draw(sf::RenderWindow &);
	std::vector<Light *> lights;
	void clear();
	void killDeadLights();
private:
	LightManager();
	static LightManager * instance;
	sf::Texture * lightTexture;
	sf::Sprite light;
	sf::RenderTexture lightMapTexture;
	sf::Sprite lightmap;
	float timeUntillChange;
	float const TIME_UNTIL_CHANGE;
	float alpha = 255;
};

