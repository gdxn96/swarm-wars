#pragma once
#include "InputHandler.h"
#include "Vector2D.h"
#include "SpriteSheetManager.h"
#include <SFML\Graphics.hpp>
class Player
{
public:
	Player(int ControllerId, sf::Texture &);
	~Player(void);
	void Update();
	void Draw(sf::RenderWindow &);

private:
	InputHandler inputHandler;
	SpriteSheetManager animation;
	float rotation,speed,angleToRunToo;
	Vector2D scale,position,direction;
	sf::Texture texture;
};

