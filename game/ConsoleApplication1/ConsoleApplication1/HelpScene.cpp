#include "stdafx.h"
#include "HelpScene.h"


HelpScene::HelpScene() : Scene(Scenes::HELP)
{
	m_menu = Menu();
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");

	bgSprite.setTexture(bgTexture);

	bgSprite.setPosition(0, 0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
}





void HelpScene::update(float dt)
{
	m_menu.update(dt);
}

void HelpScene::draw(sf::RenderWindow &window)
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
void HelpScene::updateInput()
{
	m_menu.input();
}


void HelpScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, 150), Vector2D(50, 50), ">VOLUME<", "play2");

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, 660), Vector2D(50, 50), ">BACK<", "exit2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::MAINMENU); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);
	m_menu.setEnd();
}

/*color of player unit,
audio volume
toggle on off
effect, music

back
*/