#include "stdafx.h"
#include "UpgradeElement.h"

UpgradeElement::UpgradeElement(Unit * unit) 
	:	m_parentUnit(unit), 
		m_alive(true)
{
	string uiElementKey = "default";
	m_key = uiElementKey;
	m_icon.addPoint(GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(GameConstants::WINDOW_CENTRE.x, 0));
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(0, GameConstants::WINDOW_CENTRE.y));

}

UpgradeElement::UpgradeElement(Unit* unit, WeaponType weapon, string uiElementKey) 
	:	m_alive(true), 
		m_parentUnit(unit), 
		m_weaponType(weapon),
		m_key(uiElementKey)
{
	m_icon.addPoint(GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(GameConstants::WINDOW_CENTRE.x, 0));
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(0, GameConstants::WINDOW_CENTRE.y));
}

void UpgradeElement::accept()
{
	m_parentUnit->setWeapon(WeaponFactory::getInstance()->getNewWeapon(m_weaponType));
	kill();
}

Unit* UpgradeElement::getParentUnit()
{
	return m_parentUnit;
}

void UpgradeElement::kill()
{
	m_alive = false;
}

bool UpgradeElement::isAlive()
{
	return m_alive;
}

void UpgradeElement::update(float dt)
{
	if (m_key != "default")
	{
		InputHandler* input = InputHandler::getInstance();
		if (input->isPressed(InputHandler::B))
		{
			kill();
		}
		else if (input->isPressed(InputHandler::X))
		{
			accept();
		}
	}
	
}


void UpgradeElement::draw(sf::RenderWindow&window)
{
	if (m_key == "default")
	{
		m_icon.draw(window, sf::Color::Cyan);
		
	}
	else
	{
		m_icon.draw(window, sf::Color::Red);
	}

	sf::Text a;
	a.setFont(GameConstants::font);
	a.setString(m_key);
	window.draw(a);
	
}