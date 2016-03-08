#pragma once

#include "SceneMgr.h"
#include "Vector2D.h"
#include "Circle.h"
#include <functional>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "AudioMgr.h"

using namespace std;


enum class UI_TYPE { BUTTON, CHECKBOX };

class UIElement
{
private:
	UI_TYPE m_type;
	Vector2D m_pos;
	Vector2D m_dimensions;
	string m_image;																	// temporary placeholder
	string m_image_selected;														// placeholder 
	bool m_alive;
	float m_alpha;
	UIElement* m_prev;
	UIElement* m_next;

	//Callbacks
	std::function<void()> m_func;													// functionality callback
	std::function<void(float dt)> m_appear;											// functionality for how button is revealed/displayed
	std::function<bool(float dt)> m_appearedCondition;								// condition for when reveal sequence is finished
	std::function<void(float dt)> m_disappear;										// functionality for how button departs/disappears
	std::function<bool(float dt)> m_disappearedCondition;							// condition for when button depart is finished

	//temporary
	Circle m_circle;						
	bool m_isLeft;
	Animation m_anim;
	sf::Text text;
	sf::Color c;
	int index = 0;
public:
	void setAnimation(string);
	Animation * getAnimation();
	UIElement(UI_TYPE type, Vector2D pos, Vector2D dimensions, string img1, string img2);
	void appear(float dt);
	void disappear(float dt);
	void draw(sf::RenderWindow& window);
	void invoke();
	bool isAlive();
	UI_TYPE getType();
	UIElement* getPrevious();
	UIElement* getNext();
	void setPrevious(UIElement* previousElement);
	void setNext(UIElement* nextElement);
	void setEnd();

	void setPosition(Vector2D position);
	void setSize(float size);
	Vector2D getPosition();
	void isTextLeft(bool isLeft);
	void setTextColor(sf::Color);
	int getIndex();
	void setTexture(sf::Texture * texture);
	void setAlpha(float val);
	void setVolume(float, float ,string);
	void toggleColor(std::string);

	void setFunctionality(std::function<void()> function);
	void setAppear(std::function<void(float dt)> function);
	void setDisappear(std::function<void(float dt)> function);
	void setAppearCondition(std::function<bool(float dt)> condition);
	void setDisappearCondition(std::function<bool(float dt)> condition);

	void changeAlpha(float alphaVal);
	bool testAlpha(float alphaVal, float increment);
	void changeText(string);	//test function
};