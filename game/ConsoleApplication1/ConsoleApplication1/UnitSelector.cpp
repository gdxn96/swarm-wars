#include "stdafx.h"
#include "UnitSelector.h"
UnitSelector::UnitSelector()
{

}

UnitSelector::UnitSelector(vector<Unit *> _m_currentUnits) :
UnitSizeSmall(60, 60),
UnitSizeLarge(120, 120),
DisplaySize(180, 200),
m_position(GameConstants::WINDOW_SIZE - Vector2D(DisplaySize.x + (UnitSizeSmall.x * 4), DisplaySize.y)),
UnitOne(UnitSizeSmall.toSFMLVector()),
UnitTwo(UnitSizeSmall.toSFMLVector()),
UnitThree(UnitSizeSmall.toSFMLVector()),
UnitFour(UnitSizeSmall.toSFMLVector()),
Display(DisplaySize.toSFMLVector()),
m_currentUnits(_m_currentUnits)
{
	/*f::RectangleShape UnitOne, UnitTwo, UnitThree, UnitFour, Display;
	int m_currentSelected;
	Vector2D m_position, UnitSizeSmall, UnitSizeLarge, DisplaySize;*/
	//LightManager::getInstance()->AddLight("excludeLight", m_position.toSFMLVector(), sf::Vector2f(0.19f, 0.19f), sf::Color(238, 130, 238, 105), m_direction * m_speed, this, "spotLight");
	UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	Display.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x, GameConstants::WINDOW_SIZE.y - DisplaySize.y).toSFMLVector());
	UnitOne.setSize(UnitSizeSmall.toSFMLVector());
	UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
	UnitThree.setSize(UnitSizeSmall.toSFMLVector());
	UnitFour.setSize(UnitSizeSmall.toSFMLVector());
	Display.setSize(DisplaySize.toSFMLVector());
	Display.setFillColor(sf::Color::Red);
	UnitOne.setTexture(AssetLoader::getInstance()->findTextureByKey("UnitControllerUI"));
	UnitTwo.setTexture(AssetLoader::getInstance()->findTextureByKey("UnitControllerUI"));
	UnitThree.setTexture(AssetLoader::getInstance()->findTextureByKey("UnitControllerUI"));
	UnitFour.setTexture(AssetLoader::getInstance()->findTextureByKey("UnitControllerUI"));
}

void UnitSelector::update(float dt)
{
	if (m_currentSelected == 0)
	{
		UnitOne.setSize(UnitSizeLarge.toSFMLVector());
		UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeLarge.y).toSFMLVector());
		//UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		Display.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x, GameConstants::WINDOW_SIZE.y - DisplaySize.y).toSFMLVector());
		//UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		UnitThree.setSize(UnitSizeSmall.toSFMLVector());
		UnitFour.setSize(UnitSizeSmall.toSFMLVector());
	}
	else if (m_currentSelected == 1)
	{
		UnitTwo.setSize(UnitSizeLarge.toSFMLVector());
		UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeLarge.y).toSFMLVector());
		UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		//UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		Display.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x, GameConstants::WINDOW_SIZE.y - DisplaySize.y).toSFMLVector());
		UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		//UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		UnitThree.setSize(UnitSizeSmall.toSFMLVector());
		UnitFour.setSize(UnitSizeSmall.toSFMLVector());
	}
	else if (m_currentSelected == 2)
	{
		UnitThree.setSize(UnitSizeLarge.toSFMLVector());
		UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeLarge.y).toSFMLVector());
		UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		//UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		Display.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x, GameConstants::WINDOW_SIZE.y - DisplaySize.y).toSFMLVector());
		UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		//UnitThree.setSize(UnitSizeSmall.toSFMLVector());
		UnitFour.setSize(UnitSizeSmall.toSFMLVector());

	}
	else if (m_currentSelected == 3)
	{
		UnitFour.setSize(UnitSizeLarge.toSFMLVector());
		UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeLarge.y).toSFMLVector());
		UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		//UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		Display.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x, GameConstants::WINDOW_SIZE.y - DisplaySize.y).toSFMLVector());
		UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		UnitThree.setSize(UnitSizeSmall.toSFMLVector());
		//UnitFour.setSize(UnitSizeSmall.toSFMLVector());
	}
	for (int i = 0; i < m_currentUnits.size(); i++)
	{
		if (m_currentUnits[i]->getSelected())
		{
			m_currentSelected = i;
		}
	}
}

void UnitSelector::toggleSelected()
{
	
}

void UnitSelector::draw(sf::RenderWindow & window)
{
	window.draw(UnitOne);
	window.draw(UnitTwo);
	window.draw(UnitThree);
	window.draw(UnitFour);
	window.draw(Display);
}

UnitSelector::~UnitSelector()
{
}
