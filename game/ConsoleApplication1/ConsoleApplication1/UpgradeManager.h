#pragma once
#include "UpgradeElement.h"
#include <vector>
#include "GameConstants.h"


class UpgradeManager
{
public:
	UpgradeManager();
	void NotifyNewUnit(Unit * unit);
	void NotifyLevelUp(Unit* unit);
	void removeDuplicateUpgrades(Unit* unit);
	UpgradeElement * getUpgradeByUnit(Unit * unit);
	void update(float dt, Unit* currentUnit);
	void updateInput();
	void draw(sf::RenderWindow &window);
	WeaponType& getWeaponType(UNIT_RANK);
	std::string& getWeaponKey(WeaponType);
	UpgradeElement * getCurrentUpgrade();
private:
	std::vector<std::pair<UNIT_RANK,WeaponType>> m_weaponRanks;
	std::vector<std::pair<WeaponType, std::string>> m_weaponTextures;
	std::vector<UpgradeElement*> m_upgrades;
	UpgradeElement * m_currentUpgrade;
	
};