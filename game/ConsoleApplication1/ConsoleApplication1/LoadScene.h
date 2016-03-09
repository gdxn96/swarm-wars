#pragma once

#include "Scene.h"
#include "PhysicsObject.h"
#include "AssetLoader.h"
#include "bar.h"
#include "PulsingText.h"

class LoadScene : public Scene
{
public:
	LoadScene();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;

	//can be overrided
	//void exit();
	//void enter();

private:
	int loadAssets();
	int amount;
	AssetLoader* a = AssetLoader::getInstance();
	sf::RectangleShape bgShape, fgShape;
	PulsingText text;
	sf::RectangleShape back;
	sf::Texture t,t2,t3;
};
