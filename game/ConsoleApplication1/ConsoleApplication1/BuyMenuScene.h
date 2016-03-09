#pragma once

#include "Scene.h"
#include "GameConstants.h"
#include "InputHandler.h"
#include "PulsingText.h"
#include "UnitController.h"
#include <functional>
#include "MenuItem.h"
#include "AudioMgr.h"
#include "Animation.h"
using namespace std;

class BuyMenu : public Scene
{
public:
	BuyMenu(UnitController * unitController, std::function<void()> repairBunkers);
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;

	int getItemIndex();

	void toggleActive();
	bool Active();

	void down();
	void up();

	void buyItem();
	void createMenuItems();

	void open();
	void close();

	//can be overrided
	//void exit();
	//void enter();

private:
	bool m_active;
	Vector2D m_menuSize;
	Vector2D m_menuPosition;

	vector<MenuItem> m_menuItems;
	MenuItem* m_currentItem;

	UnitController * m_unitController;
	sf::RectangleShape back;
	std::function<void()> fn_repairBunkers;
	sf::Texture * texture;
	Animation m_anim;
	PulsingText closeB;


};
