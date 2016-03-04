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

private:
	Menu m_menu;
	sf::Texture * bgTexture;
	sf::RectangleShape bgSprite;
};
