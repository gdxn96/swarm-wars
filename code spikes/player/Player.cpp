#include "stdafx.h"
#include "Player.h"


Player::Player(int _controllerID, sf::Texture & _texture) : animation(SpriteSheetManager(_texture, 16,4,Vector2D(100,100),Vector2D(1,1)))
{
	position = Vector2D(100,100);
	animation.setAnimationNameToIndex(0,"running");
	animation.setAnimationNameToIndex(1,"idle");
	animation.setIsLooping(true);
	animation.setRotation(90);
	animation.setScale(Vector2D(1,1));
}
void Player::Update()
{
	inputHandler.HandleInput();
	animation.Update();
	rotation = inputHandler.getRightThumbByAngle();
	animation.setRotation(rotation + 90);
	animation.setPosition(position);
}
void Player::Draw(sf::RenderWindow & _window)
{
	animation.Draw(_window);
}

Player::~Player(void)
{
}
