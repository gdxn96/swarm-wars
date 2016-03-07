#pragma once
#include "Unit.h"
#include "OrderPointer.h"

#include <vector>
#include <iostream>
#include "WeaponFactory.h"
#include "InputHandler.h"
#include "Animation.h"
#include "UpgradeManager.h"

using namespace std;

// class that controls the units on screen
// also monitors controller input to tell the currently selected unit what to do
class UnitController
{
public:
	UnitController();
	int playerColorIndex = 0;
	void init();
	void update(float dt);
	void draw(sf::RenderWindow & window);
	void switchUnit(bool);
	vector<Unit*> getUnits();
	void updateInput();

	void updateRanks();
	bool checkExperienceRankMatch(UNIT_RANK rank, float experience);
	void addUnit(float startAngle = 0, bool isPlayer = false);
	int getTotalCreditAmount();
	Unit* getUnitById(string id);
	void drawUI(RenderWindow &);

	void checkCanByUnit();
	void buyUnit();

	Unit * getCurrentUnit();
private:
	vector<Unit*> m_units;
	Unit * m_currentUnit;
	OrderPointer m_orderPointer;
	WeaponFactory * m_weaponFactory;
	int max = 100;
	UpgradeManager m_upgradeMgr;
	int m_totalUnitsCredit;

	const std::vector<std::pair<UNIT_RANK, int>> EXP_RANKS;
	int m_incrementingId;
};


