#pragma once
#include "Unit.h"
#include "OrderPointer.h"

#include <vector>
#include <iostream>
#include "WeaponFactory.h"
#include "InputHandler.h"
#include "Animation.h"
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

private:
	vector<Unit*> m_units;
	Unit * m_currentUnit;
	OrderPointer m_orderPointer;
	WeaponFactory * m_weaponFactory;
	Animation m_anim;
};


