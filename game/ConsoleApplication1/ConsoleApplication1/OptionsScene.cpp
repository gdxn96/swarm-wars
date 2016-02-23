#include "stdafx.h"
#include "OptionsScene.h"


OptionsScene::OptionsScene() : Scene(Scenes::OPTIONS)
{
	m_menu = Menu();
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");

	bgSprite.setTexture(bgTexture);

	bgSprite.setPosition(0, 0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
}



void OptionsScene::updateInput()
{
	m_menu.input();
}

void OptionsScene::update(float dt)
{
	m_menu.update(dt);
	
}

void OptionsScene::draw(sf::RenderWindow &window)
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


void OptionsScene::createUIElements()
{
	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, 150), Vector2D(50, 50), ">VOLUME<", "play2");
	element->setFunctionality([&, element](){
		AudioManager::instance()->setVolume(+0.1);
		element->setVolume(0.1, AudioManager::instance()->getVolume(),">VOLUME<"); 
	});					// set functionality for element click
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });										// set how element appears on screen
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });			// set the condition that must be met when button is fully on screen
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });									// set how element should disappear
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::CHECKBOX, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, 320), Vector2D(50, 50), ">TOGGLE EFFECT<", "options2");
	element->setFunctionality([&, element](){
	AudioManager::instance()->toggleFX();
	element->changeText(">TOGGLE EFFECT :"); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::CHECKBOX, Vector2D(GameConstants::WINDOW_CENTRE.x, 490), Vector2D(50, 50), ">TOGGLE MUSIC<", "help2");
	element->setFunctionality([element](){ element->changeText(">TOGGLE MUSIC<"); 
	AudioManager::instance()->toggleMusic(); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);

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