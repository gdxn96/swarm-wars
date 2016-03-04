#include "stdafx.h"
#include "UpgradeManager.h"

UpgradeManager::UpgradeManager() : 
m_weaponRanks(vector<std::pair<UNIT_RANK, WeaponType>>(
{
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::A, WeaponType::PISTOL),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::B, WeaponType::PLASMA),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::C, WeaponType::LMG),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::D, WeaponType::AK),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::E, WeaponType::SHOTGUN),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::F, WeaponType::SMG),
	std::pair<UNIT_RANK, WeaponType>(UNIT_RANK::G, WeaponType::SNIPER)
})),
m_weaponTextures(vector<std::pair<WeaponType, std::string>>(
{
	std::pair<WeaponType, std::string>(WeaponType::PLASMA, "plasma"),
	std::pair<WeaponType, std::string>(WeaponType::AK, "ak"),
	std::pair<WeaponType, std::string>(WeaponType::LMG, "lmg"),
	std::pair<WeaponType, std::string>(WeaponType::PISTOL, "pistol"),
	std::pair<WeaponType, std::string>(WeaponType::SHOTGUN, "shotgun"),
	std::pair<WeaponType, std::string>(WeaponType::SMG, "smg"),
	std::pair<WeaponType, std::string>(WeaponType::SNIPER, "sniper")
}
))
{
}

void UpgradeManager::updateInput()
{
	m_currentUpgrade->updateInput();
}


std::string& UpgradeManager::getWeaponKey(WeaponType weapon)
{
	for (auto& weaponTexture : m_weaponTextures)
	{
		if (weaponTexture.first == weapon)
		{
			return weaponTexture.second;
		}
	}
}

void UpgradeManager::NotifyLevelUp(Unit* unit)
{
	removeDuplicateUpgrades(unit);
	WeaponType type = getWeaponType(unit->getRank());
	std::string uiKey = getWeaponKey(type);
	m_upgrades.push_back(new UpgradeElement(unit, type, uiKey));
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

WeaponType& UpgradeManager::getWeaponType(UNIT_RANK rank)
{
	for (auto& weaponRank : m_weaponRanks)
	{
		if (weaponRank.first == rank)
		{
			return weaponRank.second;
		}
	}
}