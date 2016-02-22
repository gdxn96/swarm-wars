#include "stdafx.h"
#include "UIElement.h"



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
	m_func(nullptr)
{
	m_circle = Circle(m_pos, m_dimensions.x);
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

void UIElement::draw(sf::RenderWindow& window, sf::Color color)
{
	m_circle.draw(window, color + sf::Color(0, 0, 0, m_alpha));

	//Temporary Stuff
	sf::Font font;
	font.loadFromFile("arial.ttf");
	sf::Text text(m_image.c_str(), font, 38);
	text.setColor(sf::Color(255,0,0,m_alpha));
	text.setPosition(m_pos.toSFMLVector() + sf::Vector2f(60, -20));
	window.draw(text);
}



void UIElement::invoke()
{
	m_func();
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





// Test method
void UIElement::changeText()
{
	if (m_image != "Checkbox on")
	{
		m_image = "Checkbox on";
	}
	else
	{
		m_image = "Checkbox off";
	}
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