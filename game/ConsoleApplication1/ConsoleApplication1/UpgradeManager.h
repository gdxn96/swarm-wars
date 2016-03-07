#pragma once
#include "UpgradeElement.h"
#include <vector>
#include "GameConstants.h"


class UpgradeManager
{
public:
	UpgradeManager();
	void NotifyNewUnit(Unit * unit);
	bool NotifyLevelUp(Unit* unit);
	void removeDuplicateUpgrades(Unit* unit);
	UpgradeElement * getUpgradeByUnit(Unit * unit);
	void update(float dt, Unit* currentUnit);
	void updateInput();
	void draw(sf::RenderWindow &window);
	WeaponType& getWeaponType(UNIT_RANK, std::vector<std::pair<UNIT_RANK, WeaponType>> weapons);
	const std::string& getWeaponKey(WeaponType);
	UpgradeElement * getCurrentUpgrade();
private:
	const std::vector<std::pair<UNIT_RANK,WeaponType>> m_PLAYER_WeaponRanks;
	const std::vector<std::pair<UNIT_RANK, WeaponType>> m_SNIPER_WeaponRanks;
	const std::vector<std::pair<UNIT_RANK, WeaponType>> m_CQB_WeaponRanks;
	const std::vector<std::pair<UNIT_RANK, WeaponType>> m_ASSAULT_WeaponRanks;

	const std::vector<std::pair<WeaponType, std::string>> m_weaponTextures;
	std::vector<UpgradeElement*> m_upgrades;
	UpgradeElement * m_currentUpgrade;
	
};