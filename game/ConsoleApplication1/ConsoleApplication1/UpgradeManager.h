#pragma once
#include "UpgradeElement.h"
#include <vector>
#include "GameConstants.h"


class UpgradeManager
{
public:
	UpgradeManager();
	void NotifyLevelUp(Unit* unit);
	void update(float dt, Unit* currentUnit);
	void draw(sf::RenderWindow &window);
	void getWeaponType(UNIT_RANK);

private:
	std::vector<std::pair<UNIT_RANK,WeaponType>> m_unitRanks;
	std::vector<UpgradeElement*> m_upgrades;
	UpgradeElement * m_currentUpgrade;

};