#include "stdafx.h"
#include "LoadScene.h"
#include "AssetLoader.h"
#include "AudioMgr.h"

LoadScene::LoadScene() :
Scene(Scenes::LOAD),
text("name", Vector2D(GameConstants::WINDOW_CENTRE.x - 125, GameConstants::WINDOW_CENTRE.y + 15), 85, 3, "")
{
	bgShape.setSize(sf::Vector2f(250, 30));
	fgShape.setSize(sf::Vector2f(250, 30));

	bgShape.setFillColor(sf::Color(105, 106, 250, 255));
	fgShape.setFillColor(sf::Color(135, 206, 250, 255));
	fgShape.setOutlineColor(sf::Color(255, 215, 0, 255));
	fgShape.setOutlineThickness(2);

	bgShape.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x - 125, GameConstants::WINDOW_CENTRE.y - 15).toSFMLVector());
	fgShape.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x - 125, GameConstants::WINDOW_CENTRE.y - 15).toSFMLVector());
}

void LoadScene::update(float dt)
{
	float s = a->getNumToLoad();

	float percentAmount = (a->getNumLoaded() / static_cast<float>(a->getNumToLoad()));
	fgShape.setSize(sf::Vector2f(250*percentAmount, 30));
	text.setText(a->getLoadingAsset());
	text.update(dt);
}

void LoadScene::updateInput()
{

}


void LoadScene::draw(sf::RenderWindow &window)
{
	text.draw(window);
	window.draw(bgShape);
	window.draw(fgShape);
}