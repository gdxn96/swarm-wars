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
	void AddLight(std::string, sf::Vector2f position, sf::Vector2f scale, sf::Color color,Vector2D velocity,float rotation,Bullet * _parent,string lightKey);
	void updateLightByID(std::string name, Vector2D position, Vector2D scale , sf::Color);
	void draw(sf::RenderWindow &);
	std::vector<Light *> lights;
private:
	LightManager();
	static LightManager * instance;
	sf::Texture * lightTexture;
	sf::Sprite light;
	sf::RenderTexture lightMapTexture;
	sf::Sprite lightmap;
};

