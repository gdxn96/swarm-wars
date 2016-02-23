#include "stdafx.h"
#include "SelectColorScene.h"


SelectColorScene::SelectColorScene() : Scene(Scenes::SELECT), m_anim("red", Vector2D(-1000,-1000))
{
	m_menu = Menu();
	createUIElements();
	bgTexture = AssetLoader::getInstance()->findTextureByKey("bgMenu");
	m_anim.setFramesPerSecond(20);
	m_anim.SetLooping(true);
	m_anim.setRadius(400);
	bgSprite.setTexture(bgTexture);
	m_anim.setPosition(Vector2D(GameConstants::WINDOW_CENTRE.x, 490));
	bgSprite.setPosition(0, 0);
	bgSprite.setSize(Vector2D(GameConstants::WINDOW_SIZE).toSFMLVector());
}





void SelectColorScene::update(float dt)
{
	m_menu.update(dt);
	if (colorIndex == 0)
	{
		m_anim.changeAnimation("red");
	}
	else if (colorIndex == 1)
	{
		m_anim.changeAnimation("walingAssaltAnimation");//green
	}
	else if (colorIndex == 2)
	{
		m_anim.changeAnimation("yellow");
	}
	else if (colorIndex == 3)
	{
		m_anim.changeAnimation("white");
	}
	
	m_anim.update();
}

void SelectColorScene::draw(sf::RenderWindow &window)
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
	m_anim.draw(window);
}
void SelectColorScene::updateInput()
{
	m_menu.input();
}

void SelectColorScene::setIndex(int i)
{
	colorIndex = i;
}


void SelectColorScene::createUIElements()
{

	UIElement* element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x, 490), Vector2D(50, 50), ">CONTINUE<", "play2");
	
	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x -300 , 270), Vector2D(50, 50), ">SELECT COLOR<", "options2");
	element->setFunctionality([&, element](){ element->toggleColor(">SELECT COLOR<"); setIndex(element->getIndex()); SceneManager::getInstance()->playerColorIndex = element->getIndex(); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(false);
	m_menu.addElement(element);

	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x+170 , 660), Vector2D(50, 50), ">CONTINUE<", "options2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::GAME); });						// set functionality for element click
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });										// set how element appears on screen
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });			// set the condition that must be met when button is fully on screen
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });									// set how element should disappear
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	element->isTextLeft(false);
	m_menu.addElement(element);


	m_menu.setEnd();
	element = new UIElement(UI_TYPE::BUTTON, Vector2D(GameConstants::WINDOW_CENTRE.x - 170, 660), Vector2D(50, 50), ">BACK<", "exit2");
	element->setFunctionality([&](){ SceneManager::getInstance()->switchTo(Scenes::MAINMENU); });
	element->setAlpha(0);
	element->setAppear([element](float dt){ element->changeAlpha(510 * dt); });
	element->setAppearCondition([element](float dt)->bool{ return element->testAlpha(255, 255 * dt); });
	element->setDisappear([element](float dt){ element->changeAlpha(-510 * dt); });
	element->setDisappearCondition([element](float dt)->bool{ return element->testAlpha(0, -255 * dt); });
	element->setSize(150);
	m_menu.addElement(element);
	element->isTextLeft(true);
	m_menu.setEnd();
}

/*color of player unit,
audio volume
toggle on off
effect, music

back
*/