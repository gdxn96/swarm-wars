#pragma once

#include "Menu.h"
#include "AudioMgr.h"
#include "Polygon.h"
#include "AssetLoader.h"
#include <functional>

using namespace std;

class SelectColorScene : public Scene
{
public:
	SelectColorScene();
	void createUIElements();
	void update(float dt) override;
	void draw(sf::RenderWindow &window) override;
	void updateInput() override;
	//can be overrided
	//void exit();
	//void enter();

private:
	Menu m_menu;
	//std::function<void()> func;
	/*UIElement element*/;
	sf::Texture * bgTexture;
	sf::RectangleShape bgSprite;
};
