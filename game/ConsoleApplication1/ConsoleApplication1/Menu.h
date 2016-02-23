#pragma once

#include "UIElement.h"
#include "SceneMgr.h"
#include "InputHandler.h"

using namespace std;


enum class MENUSTATE { LOADING, APPEARING, READY, DISAPPEARING };

class Menu
{
private:
	UIElement* m_head;
	UIElement* m_curr;
	UIElement* m_temp;
	short m_numElements;
	MENUSTATE m_state;
	bool once = false;

public:
	Menu();
	void addElement(UIElement* element);
	void setEnd();
	void update(float dt);
	void input();
	void draw(sf::RenderWindow& window);
	void previousElement();
	void nextElement();
	void invokeCurrentElement();
};