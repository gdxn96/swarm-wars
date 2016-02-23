#pragma once

#include "Menu.h"
#include "AudioMgr.h"
#include "Polygon.h"
#include "AssetLoader.h"
#include <functional>
#include "Animation.h"

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
	void setIndex(int);
private:
	Menu m_menu;
	Animation m_anim;
	enum PLAYER_COLOR{ RED, WHITE, GREEN, YELLOW };
	int m_current;
	//std::function<void()> func;
	/*UIElement element*/;
	sf::Texture * bgTexture;
	sf::RectangleShape bgSprite;
	int colorIndex = 0;
};
