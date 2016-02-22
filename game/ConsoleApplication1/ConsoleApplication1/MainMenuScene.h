#pragma once

#include "Menu.h"

using namespace std;

class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	void createUIElements();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;

	//can be overrided
	//void exit();
	//void enter();

private:
	Menu m_menu;
};
