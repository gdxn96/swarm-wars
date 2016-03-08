#include "stdafx.h"
#include "UnitSelector.h"

UnitSelector::UnitSelector() :
UnitSizeSmall(70, 60),
UnitSizeLarge(140, 120),
DisplaySize(250, 170),
m_position(GameConstants::WINDOW_SIZE - Vector2D(DisplaySize.x + (UnitSizeSmall.x * 4), DisplaySize.y)),
UnitOne(UnitSizeSmall.toSFMLVector()),
UnitTwo(UnitSizeSmall.toSFMLVector()),
UnitThree(UnitSizeSmall.toSFMLVector()),
UnitFour(UnitSizeSmall.toSFMLVector()),
Display(DisplaySize.toSFMLVector()),
number(">UNIT<", Vector2D(250, 210), 255, 0)
{
	/*f::RectangleShape UnitOne, UnitTwo, UnitThree, UnitFour, Display;
	int m_currentSelected;
	Vector2D m_position, UnitSizeSmall, UnitSizeLarge, DisplaySize;*/
	//LightManager::getInstance()->AddLight("excludeLight", m_position.toSFMLVector(), sf::Vector2f(0.19f, 0.19f), sf::Color(238, 130, 238, 105), m_direction * m_speed, this, "spotLight");
	UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	UnitTwo.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 3), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	UnitThree.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 2), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
	UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());

	UnitOne.setSize(UnitSizeSmall.toSFMLVector());
	UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
	UnitThree.setSize(UnitSizeSmall.toSFMLVector());
	UnitFour.setSize(UnitSizeSmall.toSFMLVector());
	
	UnitOne.setFillColor(sf::Color(255, 255, 255, 12));
	UnitOne.setOutlineColor(sf::Color(135, 206, 250, 255));
	UnitOne.setOutlineThickness(2);

	UnitTwo.setFillColor(sf::Color(255, 255, 255, 12));
	UnitTwo.setOutlineColor(sf::Color(135, 206, 250, 255));
	UnitTwo.setOutlineThickness(2);

	UnitThree.setFillColor(sf::Color(255, 255, 255, 12));
	UnitThree.setOutlineColor(sf::Color(135, 206, 250, 255));
	UnitThree.setOutlineThickness(2);

	UnitFour.setFillColor(sf::Color(255, 255, 255, 12));
	UnitFour.setOutlineColor(sf::Color(135, 206, 250, 255));
	UnitFour.setOutlineThickness(2);

	number.setColor(sf::Color(255, 215, 0, 255));
}

void UnitSelector::setPosition(Vector2D pos)
{
	UnitOne.setPosition(Vector2D(pos.x - DisplaySize.x - (UnitSizeSmall.x * 4), pos.y - UnitSizeSmall.y).toSFMLVector());
	UnitTwo.setPosition(Vector2D(pos.x - DisplaySize.x - (UnitSizeSmall.x * 3), pos.y - UnitSizeSmall.y).toSFMLVector());
	UnitThree.setPosition(Vector2D(pos.x - DisplaySize.x - (UnitSizeSmall.x * 2), pos.y - UnitSizeSmall.y).toSFMLVector());
	UnitFour.setPosition(Vector2D(pos.x - DisplaySize.x - (UnitSizeSmall.x), pos.y - UnitSizeSmall.y).toSFMLVector());
	position = pos;

}
void UnitSelector::update(float dt)
{
	
	if (m_currentSelected == 0)
	{
		UnitOne.setSize(UnitSizeLarge.toSFMLVector());
		UnitOne.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x * 4), GameConstants::WINDOW_SIZE.y - UnitSizeLarge.y).toSFMLVector());
		UnitOne.setOutlineColor(sf::Color(255, 215, 0, 255));
		number.setText(">player<");
		number.setPosition(Vector2D(UnitOne.getPosition().x, UnitOne.getPosition().y - 40));

		UnitTwo.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 3), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitThree.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 2), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitFour.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x), position.y - UnitSizeSmall.y).toSFMLVector());

		UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		UnitThree.setSize(UnitSizeSmall.toSFMLVector());
		UnitFour.setSize(UnitSizeSmall.toSFMLVector());

		UnitTwo.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitThree.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitFour.setOutlineColor(sf::Color(135, 206, 250, 255));
	}
	else if (m_currentSelected == 1)
	{
		UnitTwo.setSize(UnitSizeLarge.toSFMLVector());
		UnitTwo.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 3), position.y - UnitSizeLarge.y).toSFMLVector());
		UnitTwo.setOutlineColor(sf::Color(255, 215, 0, 255));
		number.setText(">unit 1<");
		number.setPosition(Vector2D(UnitTwo.getPosition().x, UnitTwo.getPosition().y - 40));


		UnitOne.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 4), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitThree.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 2), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitFour.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		UnitThree.setSize(UnitSizeSmall.toSFMLVector());
		UnitFour.setSize(UnitSizeSmall.toSFMLVector());

		UnitOne.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitThree.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitFour.setOutlineColor(sf::Color(135, 206, 250, 255));
	}
	else if (m_currentSelected == 2)
	{
		UnitThree.setSize(UnitSizeLarge.toSFMLVector());
		UnitThree.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 2), position.y - UnitSizeLarge.y).toSFMLVector());
		UnitThree.setOutlineColor(sf::Color(255, 215, 0, 255));
		number.setText(">unit 2<");
		number.setPosition(Vector2D(UnitThree.getPosition().x, UnitThree.getPosition().y - 40));


		UnitOne.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 4), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitTwo.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 3), position.y - UnitSizeSmall.y).toSFMLVector());
		
		UnitFour.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x), position.y - UnitSizeSmall.y).toSFMLVector());
		Display.setPosition(Vector2D(position.x - DisplaySize.x, position.y - DisplaySize.y).toSFMLVector());
		UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		
		UnitFour.setSize(UnitSizeSmall.toSFMLVector());

		UnitOne.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitTwo.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitFour.setOutlineColor(sf::Color(135, 206, 250, 255));

	}
	else if (m_currentSelected == 3)
	{
		UnitFour.setSize(UnitSizeLarge.toSFMLVector());
		UnitFour.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x), position.y - UnitSizeLarge.y).toSFMLVector());
		UnitFour.setOutlineColor(sf::Color(255, 215, 0, 255));
		number.setText(">unit 4<");
		number.setPosition(Vector2D(UnitFour.getPosition().x, UnitFour.getPosition().y-40));



		UnitTwo.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 3), position.y - UnitSizeSmall.y).toSFMLVector());
		UnitThree.setPosition(Vector2D(position.x - DisplaySize.x - (UnitSizeSmall.x * 2), position.y - UnitSizeSmall.y).toSFMLVector());
		//UnitFour.setPosition(Vector2D(GameConstants::WINDOW_SIZE.x - DisplaySize.x - (UnitSizeSmall.x), GameConstants::WINDOW_SIZE.y - UnitSizeSmall.y).toSFMLVector());
		Display.setPosition(Vector2D(position.x - DisplaySize.x, position.y - DisplaySize.y).toSFMLVector());
		UnitOne.setSize(UnitSizeSmall.toSFMLVector());
		UnitTwo.setSize(UnitSizeSmall.toSFMLVector());
		UnitThree.setSize(UnitSizeSmall.toSFMLVector());

		UnitOne.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitThree.setOutlineColor(sf::Color(135, 206, 250, 255));
		UnitTwo.setOutlineColor(sf::Color(135, 206, 250, 255));
		//UnitFour.setSize(UnitSizeSmall.toSFMLVector());
	}
	for (int i = 0; i < m_currentUnits.size(); i++)
	{
		if (m_currentUnits[i]->getSelected())
		{
			m_currentSelected = i;
		}
	}
	number.update(dt);
}
void UnitSelector::updateUnits(vector<Unit *> _m_currentUnits)
{
	m_currentUnits = _m_currentUnits;
}
void UnitSelector::toggleSelected()
{
	
}

void UnitSelector::draw(sf::RenderWindow & window)
{
	/*window.draw(UnitOne);
	window.draw(UnitTwo);
	window.draw(UnitThree);
	window.draw(UnitFour);
	number.draw(window);*/
}

UnitSelector::~UnitSelector()
{
}
