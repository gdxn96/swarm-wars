#pragma once

#include "Scene.h"
#include "GameConstants.h"
#include "InputHandler.h"
#include "PulsingText.h"
#include "UnitController.h"
#include <functional>
using namespace std;

enum { SNIPER_UNIT = 0, CQB_UNIT = 1, ASSAULT_UNIT = 2, BUNKER_REPAIR = 3 };

class MenuItem
{
public:
	MenuItem(Vector2D pos, Vector2D size) : 
		m_position(pos), 
		m_size(size), 
		m_selected(false), 
		m_anim("yellow", m_position + Vector2D(m_size.w / 4 * 1, m_size.y / 2)),
		m_costText("", m_position + Vector2D(m_size.w / 4 * 3, m_size.y / 2), 80, 6),
		m_descText("", m_position + Vector2D(m_size.w / 4 * 2, m_size.y / 2), 80, 6)

	{

	}

	void setSelected(bool selected)
	{
		m_selected = selected;
	}

	bool getSelected()
	{
		return m_selected;
	}
	void update(float dt)
	{
		m_costText.update(dt);
		m_descText.update(dt);
		m_anim.update(dt);
	}
	void draw(sf::RenderWindow& window)
	{
		sf::RectangleShape bounds;
		bounds = sf::RectangleShape(m_size.toSFMLVector());

		bounds.setPosition(m_position.toSFMLVector());
		if (m_selected)
		{
			bounds.setOutlineColor(sf::Color::Red);
			bounds.setOutlineThickness(3);
		}

		window.draw(bounds);
		m_anim.draw(window);
		//m_costText.draw(window);
	//	m_descText.draw(window);

	}

	void setCost(int cost)
	{
		m_costText.setText("Cost : " + to_string(cost));
	}

	void setAnimKey(string animKey)
	{
		m_anim.changeAnimation(animKey);
	}

	void setTextField(string text)
	{
		m_descText.setText(text);
	}


private:
	Vector2D m_position;
	Vector2D m_size;
	string m_itemName;
	int m_cost;
	bool m_selected;
	Animation m_anim;
	PulsingText m_costText, m_descText;


};

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

	std::function<void()> fn_repairBunkers;



};
