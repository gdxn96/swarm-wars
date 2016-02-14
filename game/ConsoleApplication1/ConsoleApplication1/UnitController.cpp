#include "stdafx.h"
#include "UnitController.h"

UnitController::UnitController()
{
}

void UnitController::init()
{
	int numUnits = 10;
	for (int i = 0; i < numUnits; i++)
	{
		m_units.push_back(new Unit(2 * GameConstants::PI / numUnits * i));
	}

	m_currentUnit = m_units[0];
}

void UnitController::update(float dt)
{
	for (int i = 0; i < m_units.size(); i++)
	{
		m_units[i]->update(dt);
	}


}

vector<Unit*> UnitController::getUnits()
{
	return m_units;
}

void UnitController::draw(sf::RenderWindow & window)
{
	// THIS STUFF NEEDS TO BE DONE WITH INPUTHANDLER SOON
	sf::Event Event;
	while (window.pollEvent(Event))
	{

		// Escape key : exit 
		if (Event.key.code == sf::Keyboard::Up)
			m_orderPointer.update(m_orderPointer.getAngle() + 0.5f);
		else if (Event.key.code == sf::Keyboard::Down)
			m_orderPointer.update(m_orderPointer.getAngle() - 0.5f);
		else if (Event.key.code == sf::Keyboard::Space)
			m_currentUnit->setTargetAngle(m_orderPointer.getAngle());
		else if (Event.key.code == sf::Keyboard::S)
			switchUnit();
		else if (Event.key.code == sf::Keyboard::F)
			m_currentUnit->changeState(UNIT_STATE::FIRING);

	}

	for (int i = 0; i < m_units.size(); i++)
	{
		m_units[i]->draw(window);
	}
	m_orderPointer.draw(window);
}

void UnitController::switchUnit()
{
	cout << "switch unit" << endl;
	int lastIndex = -1;
	for (int i = 0; i < m_units.size(); i++)
	{
		if (m_currentUnit == m_units[i])
		{
			lastIndex = i;
		}
	}

	if (lastIndex == m_units.size() - 1)
	{
		m_currentUnit = m_units[0];
	}
	else
	{
		m_currentUnit = m_units[lastIndex + 1];
	}
}