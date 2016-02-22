#include "stdafx.h"
#include "Menu.h"



Menu::Menu() :
	m_head(nullptr),
	m_curr(nullptr),
	m_temp(nullptr),
	m_numElements(0),
	m_state(MENUSTATE::LOADING)
{

}


void Menu::addElement(UIElement* element)
{
	m_curr = element;

	if (m_temp != nullptr)
	{
		m_temp->setNext(m_curr);
		m_curr->setPrevious(m_temp);
	}

	m_temp = m_curr;

	if (m_head == nullptr)
	{
		m_head = m_curr;
	}

	m_numElements++;
}

void Menu::setEnd()
{
	m_curr->setNext(m_head);
	m_head->setPrevious(m_curr);
	m_curr = m_head;
	m_state = MENUSTATE::APPEARING;
}


void Menu::update(float dt)
{
	m_temp = m_head;
	short count = 0;

	switch (m_state)
	{
	case MENUSTATE::APPEARING:
		for (int i = 0; i < m_numElements; i++)
		{
			if (!m_temp->isAlive())
				m_temp->appear(dt);
			else 
				count++;

			m_temp = m_temp->getNext();

			if (count == m_numElements) 
				m_state = MENUSTATE::READY;
		}
		break;

	case MENUSTATE::DISAPPEARING:
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_temp->isAlive())
				m_temp->disappear(dt);
			else
				count++;

			m_temp = m_temp->getNext();

			if (count == m_numElements)
				invokeCurrentElement();
		}
		break;
	}

}

void Menu::input()
{
	InputHandler* input = InputHandler::getInstance();

	if (m_state == MENUSTATE::READY)
	{
		if (input->isPressed(InputHandler::DPAD_DOWN))
		{
			nextElement();
		}
		else if (input->isPressed(InputHandler::DPAD_UP))
		{
			previousElement();
		}
		else if (input->isPressed(InputHandler::Y))
		{
			if (m_curr->getType() == UI_TYPE::CHECKBOX)
			{
				m_curr->invoke();
			}
			else
			{
				m_state = MENUSTATE::DISAPPEARING;
			}
		}
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	if (m_numElements > 0)
	{
		m_temp = m_head;

		for (int i = 0; i < m_numElements; i++)
		{
			if (m_temp == m_curr)
				m_temp->draw(window, sf::Color(9, 9, 99, 0));
			else
				m_temp->draw(window, sf::Color(0, 0, 0, 0));

			m_temp = m_temp->getNext();
		}
	}
}



void Menu::previousElement()
{
	if (m_curr != nullptr)
	{
		m_curr = m_curr->getPrevious();
	}
}

void Menu::nextElement()
{
	if (m_curr != nullptr)
	{
		m_curr = m_curr->getNext();
	}
}



void Menu::invokeCurrentElement()
{
	m_curr->invoke();
}