#include "stdafx.h"
#include "GameOverScene.h"


GameOverScene::GameOverScene() : Scene(Scenes::GAME_LOSE)
{
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");

	bgSprite.setTexture(bgTexture);

	bgSprite.setPosition(0, 0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
}

void GameOverScene::updateInput()
{
	if (InputHandler::getInstance()->isPressed(InputHandler::A))
	{
		SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	}
}

void GameOverScene::update(float dt)
{	
}

void GameOverScene::draw(sf::RenderWindow &window)
{
	
	window.draw(bgSprite);
	m_menu.draw(window);
}


void GameOverScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, GameConstants::WINDOW_CENTRE, Vector2D(50, 50), ">>You Lose!\nPress A to return to \n Main Menu<<", "exit2");

	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);
}