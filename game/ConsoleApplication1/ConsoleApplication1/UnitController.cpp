#include "stdafx.h"
#include "UnitController.h"
#include "AudioMgr.h"

UnitController::UnitController() : 
EXP_RANKS(vector<std::pair<UNIT_RANK, int>>({
	std::pair<UNIT_RANK, int>(UNIT_RANK::A, 100),
	std::pair<UNIT_RANK, int>(UNIT_RANK::B, 200),
	std::pair<UNIT_RANK, int>(UNIT_RANK::C, 300),
	std::pair<UNIT_RANK, int>(UNIT_RANK::D, 400),
	std::pair<UNIT_RANK, int>(UNIT_RANK::E, 500),
	std::pair<UNIT_RANK, int>(UNIT_RANK::F, 600),
	std::pair<UNIT_RANK, int>(UNIT_RANK::G, MAXINT32)
})),
m_incrementingId(0)
{
}

void UnitController::updateInput()
{
	InputHandler * input = InputHandler::getInstance();

	float rightStickAngle = 0, leftStickAngle = 0;
	leftStickAngle = input->getThumbByRadian(InputHandler::LEFT_STICK);
	m_orderPointer.update(leftStickAngle,0);

	leftStickAngle = input->getThumbByRadian(InputHandler::RIGHT_STICK);
	m_currentUnit->setDirectionAngle(leftStickAngle);

	if (input->isPressed(InputHandler::LB))
	{
		AudioManager::instance()->PlayGameSound("yes", false, 0.1f, m_currentUnit->getPosition(), 0);
		switchUnit(true);
	}

	if (input->isPressed(InputHandler::RB))
	{
		AudioManager::instance()->PlayGameSound("yes", false, 0.1f, m_currentUnit->getPosition(), 0);
		switchUnit(false);
	}
	if (input->isPressed(InputHandler::A))
	{
		m_currentUnit->setTargetAngle(m_orderPointer.getAngle());
		AudioManager::instance()->PlayGameSound("Ok3", false, 0.1f, m_currentUnit->getPosition(), 0);
	}

	if (m_currentUnit->isPlayer())
	{
		m_currentUnit->setTargetAngle(m_orderPointer.getAngle());
	}

	float rightTriggerAmount;
	if (InputHandler::getInstance()->getTriggerPressed(InputHandler::RIGHT_TRIGGER, rightTriggerAmount))
	{
		if (rightTriggerAmount > 0.5f && m_currentUnit->isPlayer())
		{
			m_currentUnit->fireWeapon();
			InputHandler::getInstance()->setVibration(0.2f, 0.0f);
		}
		else
		{
			InputHandler::getInstance()->setVibration(0.0f, 0.0f);
		}
		

	}
	if (InputHandler::getInstance()->isPressed(InputHandler::Y))
	{
		m_currentUnit->getWeaponUpgrade()->setIsActive(false);
	}
	else if (InputHandler::getInstance()->isPressed(InputHandler::X))
	{
		m_currentUnit->getWeaponUpgrade()->setIsActive(false);
	}
	m_upgradeMgr.updateInput();

}

void UnitController::init()
{
	m_units.clear();
	addUnit(0, UNIT_TYPE::PLAYER);
	m_currentUnit = m_units[0];
	m_currentUnit->setSelected(true);
}

void UnitController::addUnit(float startAngle, UNIT_TYPE unitType)
{
	Unit * newUnit = new Unit(std::to_string(m_incrementingId++));
	newUnit->setUnitType(unitType);
	m_units.push_back(newUnit);
	m_upgradeMgr.NotifyNewUnit(newUnit);
}

bool UnitController::canBuyUnit(UNIT_TYPE type)
{
	/////////////////////////////////////////////////////////////////////
	bool canAfford = false;

	switch (type)
	{
	case UNIT_TYPE::ASSAULT:
		canAfford = getTotalCreditAmount() > GameConstants::ASSAULT_UNIT_COST;
		break;
	case UNIT_TYPE::SNIPER:
		canAfford = getTotalCreditAmount() > GameConstants::SNIPER_UNIT_COST;
		break;
	case UNIT_TYPE::CQB:
		canAfford = getTotalCreditAmount() > GameConstants::CQB_UNIT_COST;
		break;
	}

	return canAfford;
	/////////////////////////////////////////////////////////////////////
}

void UnitController::buyUnit(UNIT_TYPE unitType)
{
	addUnit(0, unitType);
	
	switch (unitType)
	{
	case UNIT_TYPE::ASSAULT:
		m_units[0]->addCredits(-GameConstants::ASSAULT_UNIT_COST);
		break;
	case UNIT_TYPE::SNIPER:
		m_units[0]->addCredits(-GameConstants::SNIPER_UNIT_COST);
		break;
	case UNIT_TYPE::CQB:
		m_units[0]->addCredits(-GameConstants::CQB_UNIT_COST);
		break;
	}

	AudioManager::instance()->PlayGameSound("Awesome", false, 1, m_units[0]->getPosition(), 0);
}

Unit* UnitController::getUnitById(string id)
{
	for (auto& unit : m_units)
	{
		if (unit->getId() == id)
		{
			return unit;
		}
	}
}

void UnitController::update(float dt)
{
	for (int i = 0; i < m_units.size(); i++)
	{
		m_units[i]->update(dt);
	}
	updateRanks();
	m_upgradeMgr.update(dt, m_currentUnit);
	m_orderPointer.update(dt);
}

Unit * UnitController::getCurrentUnit()
{
	return m_currentUnit;
}

bool UnitController::checkExperienceRankMatch(UNIT_RANK _rank, float experience)
{
	bool matches = false;
	for (auto& rank : EXP_RANKS)
	{
		if (experience < rank.second && _rank == rank.first) // experience is an upper limit
		{
			matches = true;
			break;
		}
	}


	return matches;
}

void UnitController::updateRanks()
{
	int temp = 0;
	for (Unit * unit : m_units)
	{
		if (!checkExperienceRankMatch(unit->getRank(), unit->getExperience()))
		{
			UNIT_RANK prevRank = EXP_RANKS[EXP_RANKS.size() - 1].first;
			
			for (auto& rank : EXP_RANKS)
			{
				if (prevRank == unit->getRank())
				{
					unit->setRank(rank.first);
					if (m_upgradeMgr.NotifyLevelUp(unit))
					{
						//call upgrade UI draw animation

						
						unit->setWeaponActiveUI(true);
						AudioManager::instance()->PlayGameSound("upgrades", false, 0.8f, unit->getPosition(), 0);
					}
					unit->maxRank = rank.second;
					break;
				}
				prevRank = rank.first;
			}
		}
		if (unit->getExperience() < 600)
		{
			float percentLeft = std::abs(unit->maxRank - unit->getExperience() - 100);
			unit->setXPBar(percentLeft);
		}
		temp += unit->getCredits();
	}
	m_totalUnitsCredit = temp;
}

int UnitController::getTotalCreditAmount()
{
	return m_totalUnitsCredit;
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

void UnitController::drawUI(sf::RenderWindow & window)
{
	m_upgradeMgr.draw(window);
}

void UnitController::switchUnit(bool left)
{
	if (!left)
	{
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
		cout << lastIndex << endl;
	}
	else
	{
		m_currentUnit->setSelected(false);
		int lastIndex = -1;
		for (int i = m_units.size() - 1; i != -1; i--)
		{
			if (m_currentUnit == m_units[i])
			{
				lastIndex = i;
				cout << i << endl;
			}
		}
		if (lastIndex == 0)
		{
			m_currentUnit = m_units[m_units.size() - 1];
		}
		else
		{
			m_currentUnit = m_units[lastIndex - 1];
		}
		m_currentUnit->setSelected(true);
		cout << lastIndex << endl;
	}
}