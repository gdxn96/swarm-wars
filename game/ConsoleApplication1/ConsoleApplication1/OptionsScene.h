#pragma once

#include "Menu.h"

using namespace std;

class OptionsScene : public Scene
{
public:
	OptionsScene();
	void createUIElements();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;

	//can be overrided
	//void exit();
	//void enter();

private:
	Menu m_menu;
	//std::function<void()> func;
	/*UIElement element*/;

};
