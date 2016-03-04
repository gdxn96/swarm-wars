#include "stdafx.h"
#include "GameWinScene.h"


GameWinScene::GameWinScene() : Scene(Scenes::GAME_WIN)
{
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");

	bgSprite.setTexture(bgTexture);

	bgSprite.setPosition(0, 0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
}

void GameWinScene::updateInput()
{
	if (InputHandler::getInstance()->isPressed(InputHandler::A))
	{
		SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	}
}

void GameWinScene::update(float dt)
{
	m_menu.update(dt);
	
}

void GameWinScene::draw(sf::RenderWindow &window)
{
	window.draw(bgSprite);
	m_menu.draw(window);
}


void GameWinScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, GameConstants::WINDOW_CENTRE, Vector2D(50, 50), ">You Win!\nPress A to return to \n Main Menu<", "exit2");

	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);
}