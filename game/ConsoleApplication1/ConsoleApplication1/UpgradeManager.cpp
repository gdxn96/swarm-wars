#include "stdafx.h"
#include "UpgradeManager.h"

UpgradeManager::UpgradeManager() : 
	m_PLAYER_WeaponRanks(vector<std::pair<UNIT_RANK, WeaponType>>(
	{
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::A, WeaponType::PISTOL),
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::PLASMA),
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::LMG),
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::D, WeaponType::AK),
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::E, WeaponType::SHOTGUN),
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::F, WeaponType::SMG),
		std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::G, WeaponType::SNIPER)
	})),
	m_SNIPER_WeaponRanks(vector<std::pair<UNIT_RANK, WeaponType>>(
	{
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::A, WeaponType::SNIPER1),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::D, WeaponType::SNIPER2),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::G, WeaponType::SNIPER3)
	})),
	m_CQB_WeaponRanks(vector<std::pair<UNIT_RANK, WeaponType>>(
	{
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::A, WeaponType::PLASMA1),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::D, WeaponType::PLASMA2),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::G, WeaponType::PLASMA3)
	})),
	m_ASSAULT_WeaponRanks(vector<std::pair<UNIT_RANK, WeaponType>>(
	{
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::A, WeaponType::AK1),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::D, WeaponType::AK2),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::NULL_WEAPON),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::G, WeaponType::AK3)
	})),
	m_weaponTextures(vector<std::pair<WeaponType, std::string>>(
	{
	std::pair<WeaponType, std::string>(WeaponType::PLASMA, "plasma"),
	std::pair<WeaponType, std::string>(WeaponType::AK, "ak"),
	std::pair<WeaponType, std::string>(WeaponType::LMG, "lmg"),
	std::pair<WeaponType, std::string>(WeaponType::PISTOL, "pistol"),
	std::pair<WeaponType, std::string>(WeaponType::SHOTGUN, "shotgun"),
	std::pair<WeaponType, std::string>(WeaponType::SMG, "smg"),
	std::pair<WeaponType, std::string>(WeaponType::SNIPER, "sniper"),
	std::pair<WeaponType, std::string>(WeaponType::SNIPER1, "sniper"),
	std::pair<WeaponType, std::string>(WeaponType::SNIPER2, "sniper"),
	std::pair<WeaponType, std::string>(WeaponType::SNIPER3, "sniper"),
	std::pair<WeaponType, std::string>(WeaponType::AK1, "ak"),
	std::pair<WeaponType, std::string>(WeaponType::AK2, "ak"),
	std::pair<WeaponType, std::string>(WeaponType::AK3, "ak"),
	std::pair<WeaponType, std::string>(WeaponType::PLASMA1, "plasma"),
	std::pair<WeaponType, std::string>(WeaponType::PLASMA2, "plasma"),
	std::pair<WeaponType, std::string>(WeaponType::PLASMA3, "plasma")
	}))
{
}

void UpgradeManager::updateInput()
{
	m_currentUpgrade->updateInput();
}


const std::string& UpgradeManager::getWeaponKey(WeaponType weapon)
{
	for (auto& weaponTexture : m_weaponTextures)
	{
		if (weaponTexture.first == weapon)
		{
			return weaponTexture.second;
		}
	}
}

bool UpgradeManager::NotifyLevelUp(Unit* unit)
{
	bool newWeapon = false;
	removeDuplicateUpgrades(unit);
	UNIT_RANK rank = unit->getRank();
	UNIT_TYPE type = unit->getType();
	WeaponType weaponType = WeaponType::NULL_WEAPON;

	switch (type)
	{
	case UNIT_TYPE::ASSAULT:
		weaponType = getWeaponType(rank, m_ASSAULT_WeaponRanks);
		break;
	case UNIT_TYPE::SNIPER:
		weaponType = getWeaponType(rank, m_SNIPER_WeaponRanks);
		break;
	case UNIT_TYPE::CQB:
		weaponType = getWeaponType(rank, m_CQB_WeaponRanks);
		break;
	case UNIT_TYPE::PLAYER:
		weaponType = getWeaponType(rank, m_PLAYER_WeaponRanks);
		break;

	}
	
	

	if (weaponType != WeaponType::NULL_WEAPON)
	{
		std::string uiKey = getWeaponKey(weaponType);
		m_upgrades.push_back(new UpgradeElement(unit, weaponType, uiKey));
		newWeapon = true;
	}
	return newWeapon;
}

void UpgradeManager::removeDuplicateUpgrades(Unit* unit)
{
	UpgradeElement* upgrade = getUpgradeByUnit(unit);
	upgrade->kill();
}

UpgradeElement * UpgradeManager::getUpgradeByUnit(Unit * unit)
{
	UpgradeElement * pUpgrade = nullptr;
	for (int i = 0; i < m_upgrades.size(); i++)
	{
		UpgradeElement* upgrade = m_upgrades[i];
		if (upgrade->getParentUnit() == unit)
		{
			pUpgrade = upgrade;
		}
	}

	return pUpgrade;
}

UpgradeElement * UpgradeManager::getCurrentUpgrade()
{
	return m_currentUpgrade;
}

void UpgradeManager::NotifyNewUnit(Unit * unit)
{
	UpgradeElement * newUpgrade = new UpgradeElement(unit);
	m_upgrades.push_back(newUpgrade);

	if (m_currentUpgrade == nullptr)
	{
		m_currentUpgrade = newUpgrade;
	}
}

void UpgradeManager::update(float dt, Unit* currentUnit)
{
	for (int i = 0; i < m_upgrades.size(); i++)
	{
		UpgradeElement* upgrade = m_upgrades[i];
		Unit * parent = upgrade->getParentUnit();
		if (!upgrade->isAlive())
		{
			delete upgrade;
			m_upgrades.erase(m_upgrades.begin() + i);

			if (getUpgradeByUnit(parent) == nullptr)
			{
				m_upgrades.push_back(new UpgradeElement(parent));
			}
			
			continue;
		}
	}
	
	if (getUpgradeByUnit(currentUnit) != m_currentUpgrade)
	{
		m_currentUpgrade = getUpgradeByUnit(currentUnit);
	}
	
	m_currentUpgrade->update(dt);
}

void UpgradeManager::draw(sf::RenderWindow &window)
{
	m_currentUpgrade->draw(window);
}

WeaponType& UpgradeManager::getWeaponType(UNIT_RANK rank, std::vector<std::pair<UNIT_RANK, WeaponType>> weaponRanks)
{
	WeaponType returnValue = WeaponType::NULL_WEAPON;
	for (auto& weaponRank : weaponRanks)
	{
		if (weaponRank.first == rank)
		{
			returnValue = weaponRank.second;
			break;
		}
	}

	return returnValue;
}