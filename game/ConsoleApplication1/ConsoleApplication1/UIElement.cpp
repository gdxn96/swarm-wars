#include "stdafx.h"
#include "UIElement.h"
#include <iostream>
#include <sstream>


UIElement::UIElement()
{

}

UIElement::UIElement(UI_TYPE type, Vector2D pos, Vector2D dimensions, string img1, string img2) :
	m_pos(pos),
	m_dimensions(dimensions),
	m_image(img1),
	m_image_selected (img2),
	m_alive(false),
	m_alpha(255),
	m_type(type),
	m_func(nullptr),
	m_anim("buttonStill", Vector2D(-1000,-1000))
{
	m_circle = Circle(m_pos, m_dimensions.x);
	m_anim.setFramesPerSecond(30);
	m_anim.SetLooping(true);
	m_anim.setRadius(dimensions.x);
	m_anim.setPosition(pos);
}

void UIElement::setTexture(sf::Texture * _texture)
{
	m_circle.setTexture(_texture);
}

void UIElement::appear(float dt)
{
	if (m_appear != NULL)
	{
		m_appear(dt);

		if (m_appearedCondition(dt) == true)
		{
			m_alive = true;
		}
	}
	else
		m_alive = true;
}

void UIElement::disappear(float dt)
{
	if (m_disappear != NULL)
	{
		m_disappear(dt);

		if (m_disappearedCondition(dt) == true)
		{
			m_alive = false;
		}
	}
	else
		m_alive = false;
}

void UIElement::draw(sf::RenderWindow& window)
{
	m_anim.update();
	
	//m_circle.setAlpha(m_alpha);
	//m_circle.draw(window);
	
	//Temporary Stuff
	sf::Font font;
	font.loadFromFile("stoNe.ttf");
	text = sf::Text(m_image.c_str(), font, 38);
	
	text.setColor(c+ sf::Color(0, 0, 0, m_alpha));
	if (!m_isLeft)
	{
		text.setPosition(m_pos.toSFMLVector() + sf::Vector2f(m_dimensions.x + 100, -20));
	}
	else
	{
		int i = std::strlen(m_image.c_str());
		text.setPosition(m_pos.toSFMLVector() + sf::Vector2f(-m_dimensions.x - (std::strlen(m_image.c_str())*25) - 100, -20));
	}
	window.draw(text);
	m_anim.draw(window);
}



void UIElement::invoke()
{
	m_func();
}

void UIElement::isTextLeft(bool isTextLeft)
{
	m_isLeft = isTextLeft;
}


bool UIElement::isAlive()
{
	return m_alive;
}

UI_TYPE UIElement::getType()
{
	return m_type;
}

UIElement* UIElement::getPrevious()
{
	return m_prev;
}

UIElement* UIElement::getNext()
{
	return m_next;
}



void UIElement::setPrevious(UIElement* previousElement)
{
	m_prev = previousElement;
}

void UIElement::setNext(UIElement* nextElement)
{
	m_next = nextElement;
}

void UIElement::setAlpha(float val)
{
	m_alpha = val;
}

void UIElement::setAnimation(string name)
{
	m_anim.changeAnimation(name);
}

void UIElement::setFunctionality(std::function<void()> function)		
{
	m_func = function;
}

void UIElement::setAppear(std::function<void(float dt)> function)
{
	m_appear = function;
}

void UIElement::setAppearCondition(std::function<bool(float dt)> condition)
{
	m_appearedCondition = condition;
}

void UIElement::setDisappear(std::function<void(float dt)> function)
{
	m_disappear = function;
}

void UIElement::setDisappearCondition(std::function<bool(float dt)> condition)
{
	m_disappearedCondition = condition;
}
void UIElement::setPosition(Vector2D position)
{
	m_pos = position;
	m_anim.setPosition(position);
}

void UIElement::setSize(float radius)
{
	m_circle.setRadius(radius);
	m_anim.setRadius(radius);
}


Vector2D UIElement::getPosition()
{
	return m_pos;
}

Animation * UIElement::getAnimation()
{
	return & m_anim;
}


// Test method
void UIElement::changeText(string text)
{
	std::string on = text + ": ON<";
	std::string off = text + ": OFF<";
	if (m_image.compare(off) != 0)
	{
		m_image = off;
	}
	else if (m_image.compare(on) != 0)
	{
		m_image = on;
	}
}
void UIElement::setVolume(float f,float  current,string text)
{
	std::string temp = text + " " + numberToString(current*100) +"%";
	if (current >= 1)
	{
		AudioManager::instance()->resetVolume();
	}
	m_image = temp;
}

template <class T>
std::string UIElement::numberToString(const T& t) {

	std::stringstream ss;
	ss << t;
	return ss.str();
}

// APPEAR/DISAPPEAR SEQUENCES
//--------------------------

//////////////////
// CHANGE ALPHA //
//////////////////
void UIElement::changeAlpha(float increment)
{
	m_alpha += increment;
}

bool UIElement::testAlpha(float alphaVal, float increment)
{
	if (abs(alphaVal - m_alpha) <= abs(increment))
	{
		m_alpha = alphaVal;
		return true;
	}

	return false;
}

void UIElement::setTextColor(sf::Color _c)
{
	c = _c;
}