#include "stdafx.h"
#include "UnitController.h"

UnitController::UnitController()
{
}

void UnitController::init()
{
	int numUnits = 2;
	m_units.push_back(new Unit());
	for (int i = 0; i < numUnits; i++)
	{
		m_units.push_back(new Unit(2 * GameConstants::PI / numUnits * i));
	}

	m_currentUnit = m_units[0];
	m_currentUnit->setSelected(true);

}

void UnitController::update(float dt)
{

	InputHandler * input = InputHandler::getInstance();

	float rightStickAngle = 0, leftStickAngle = 0;
	leftStickAngle = input->getThumbByRadian(InputHandler::LEFT_STICK);
	m_orderPointer.update(leftStickAngle);

	leftStickAngle = input->getThumbByRadian(InputHandler::RIGHT_STICK);
	m_currentUnit->setDirectionAngle(leftStickAngle);

	if (input->isPressed(InputHandler::B))
	{
		cout << "pressedfsdf unit" << endl;
		switchUnit();
	}
	if (input->isPressed(InputHandler::A))
	{
		m_currentUnit->setTargetAngle(m_orderPointer.getAngle());
	}
	
	if (m_currentUnit->isPlayer())
	{
		m_currentUnit->setTargetAngle(m_orderPointer.getAngle());
	}

	float rightTriggerAmount;
	if (InputHandler::getInstance()->getTriggerPressed(InputHandler::RIGHT_TRIGGER, rightTriggerAmount) )
	{
		if (rightTriggerAmount > 0.5f && m_currentUnit->isPlayer())
		m_currentUnit->fireWeapon();
	}

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
	for (int i = 0; i < m_units.size(); i++)
	{
		m_units[i]->draw(window);
	}
	m_orderPointer.draw(window);
}

void UnitController::switchUnit()
{
	cout << "switch unit" << endl;
	m_currentUnit->setSelected(false);
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
	m_currentUnit->setSelected(true);
}