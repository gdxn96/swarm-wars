#include "stdafx.h"
#include "PauseScene.h"


PauseScene::PauseScene(std::function<void()> resumeCallback) : Scene(Scenes::OPTIONS),
m_resume(resumeCallback)
{
	m_menu = Menu();
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");

	bgSprite.setTexture(bgTexture);

	bgSprite.setPosition(0, 0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
}

void PauseScene::updateInput()
{
	m_menu.input();

	if (InputHandler::getInstance()->isPressed(InputHandler::START))
	{
		m_resume();
	}
}

void PauseScene::update(float dt)
{
	m_menu.update(dt);
	
}

void PauseScene::draw(sf::RenderWindow &window)
{
	sf::Event Event;
	while (window.pollEvent(Event))
	{

		// Escape key : exit 
		if (Event.key.code == sf::Keyboard::Space)
			SceneManager::getInstance()->switchTo(Scenes::GAME);
	}


	//can obviously be deleted once you start working on the scene
	sf::Text text("Options Menu", GameConstants::font, 50);
	text.setColor(sf::Color::Red);
	window.draw(bgSprite);
	m_menu.draw(window);
}


void PauseScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, 150), Vector2D(50, 50), ">RESUME<", "exit2");
	element->setFunctionality([&](){ m_resume(); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);

	

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, 320), Vector2D(50, 50), ">RESET<", "options2");
	element->setFunctionality([&](){
		SceneManager::getInstance()->switchTo(Scenes::MAINMENU); SceneManager::getInstance()->switchTo(Scenes::GAME); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, 490), Vector2D(50, 50), ">EXIT<", "help2");
	element->setFunctionality([element](){ SceneManager::getInstance()->switchTo(Scenes::MAINMENU); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);
	m_menu.setEnd();
}