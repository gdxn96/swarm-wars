#pragma once
#include "Unit.h"
#include "OrderPointer.h"

#include <vector>
#include <iostream>
#include "WeaponFactory.h"
#include "InputHandler.h"
#include "UpgradeManager.h"
using namespace std;

// class that controls the units on screen
// also monitors controller input to tell the currently selected unit what to do
class UnitController
{
public:
	UnitController();

	void init();
	void update(float dt);
	void draw(sf::RenderWindow & window);
	void switchUnit();
	vector<Unit*> getUnits();

	void updateRanks();
	bool checkExperienceRankMatch(UNIT_RANK rank, float experience);
	void addUnit(float startAngle = 0, bool isPlayer = false);

	Unit* getUnitById(string id);

private:
	vector<Unit*> m_units;
	Unit * m_currentUnit;
	OrderPointer m_orderPointer;
	WeaponFactory * m_weaponFactory;
	UpgradeManager m_upgradeMgr;

	const std::vector<std::pair<UNIT_RANK, int>> EXP_RANKS;
	int m_incrementingId;

	
};


