#include "stdafx.h"
#include "GameScene.h"

GameScene::GameScene() : Scene(Scenes::GAME), m_unitController(UnitController())
{
	Vector2D window = GameConstants::WINDOW_SIZE;
	Vector2D centre = GameConstants::WINDOW_CENTRE;
	fullView.setViewport(sf::FloatRect(0, 0, 1, 1));
	fullView.setCenter(centre.toSFMLVector());
	zoomView.setCenter(centre.toSFMLVector());
	fullView.setSize(window.toSFMLVector());
	zoomView.setSize((window / 4).toSFMLVector());
	zoomView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	
}

void GameScene::update(float dt)
{
	m_unitController.update(dt);
}

void GameScene::pause()
{

}

void GameScene::draw(sf::RenderWindow &window)
{
	window.setView(zoomView);
	m_unitController.draw(window);

	window.setView(fullView);
	m_unitController.draw(window);

	//can obviously be deleted once you start working on the game
	sf::Text text("Game", font, 50);
	text.setColor(sf::Color::Red);
	window.draw(text);
}