#include "stdafx.h"
#include "UnitController.h"

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

void UnitController::init()
{
	int numUnits = 2;

	addUnit(0, true);
	for (int i = 0; i < numUnits; i++)
	{
		addUnit(2 * GameConstants::PI / numUnits * i);
	}
	m_currentUnit = m_units[0];
	m_currentUnit->setSelected(true);
}

void UnitController::addUnit(float startAngle, bool isPlayer)
{
	Unit * newUnit = new Unit(startAngle, std::to_string(m_incrementingId++));
	newUnit->setIsPlayer(isPlayer);
	m_units.push_back(newUnit);
	m_upgradeMgr.NotifyNewUnit(newUnit);
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
	InputHandler * input = InputHandler::getInstance();

	float rightStickAngle = 0, leftStickAngle = 0;
	leftStickAngle = input->getThumbByRadian(InputHandler::LEFT_STICK);
	m_orderPointer.update(leftStickAngle);

	leftStickAngle = input->getThumbByRadian(InputHandler::RIGHT_STICK);
	m_currentUnit->setDirectionAngle(leftStickAngle);

	if (input->isPressed(InputHandler::RB))
	{
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
		{
			m_currentUnit->fireWeapon();
		}
	}

	for (int i = 0; i < m_units.size(); i++)
	{
		m_units[i]->update(dt);
	}
	updateRanks();
	m_upgradeMgr.update(dt, m_currentUnit);
	InputHandler::getInstance()->update();
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
					m_upgradeMgr.NotifyLevelUp(unit);
					break;
				}
				prevRank = rank.first;
			}
		}
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
	m_upgradeMgr.draw(window);
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