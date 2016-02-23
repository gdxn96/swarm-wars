#include "stdafx.h"
#include "Menu.h"
#include "AssetLoader.h"
#include "AudioMgr.h"

Menu::Menu() :
	m_head(nullptr),
	m_curr(nullptr),
	m_temp(nullptr),
	m_numElements(0),
	m_state(MENUSTATE::LOADING)
{
	//
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
	if (!once){
		//AudioManager::instance()->PlayGameSound("menuSong", false, 1, Vector2D(0, 0), 1);
		once = true;
	}
	
	
	if (m_state == MENUSTATE::READY)
	{
		if (input->isPressed(InputHandler::DPAD_DOWN))
		{
			AudioManager::instance()->PlayGameSound("select", false, 0.3f, m_curr->getPosition(), 1);
			nextElement();
			
		}
		else if (input->isPressed(InputHandler::DPAD_UP))
		{
			AudioManager::instance()->PlayGameSound("select", false, 0.3f, m_curr->getPosition(), 1);
			previousElement();
			
		}
		else if (input->isPressed(InputHandler::DPAD_RIGHT))
		{
			AudioManager::instance()->PlayGameSound("select", false, 0.3f, m_curr->getPosition(), 1);
			previousElement();

		}
		else if (input->isPressed(InputHandler::DPAD_LEFT))
		{
			AudioManager::instance()->PlayGameSound("select", false, 0.3f, m_curr->getPosition(), 1);
			previousElement();

		}
		else if (input->isPressed(InputHandler::A))
		{
			AudioManager::instance()->PlayGameSound("click", false, 0.3f, m_curr->getPosition(), 1);
			m_curr->invoke();
		}
	}
}

void Menu::draw(sf::RenderWindow& window)
{
	m_curr->setTexture(AssetLoader::getInstance()->findTextureByKey("button"));
	if (m_numElements > 0)
	{
		m_temp = m_head;
		
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_temp == m_curr)
			{
				m_temp->setAnimation("buttonActive");
				m_temp->getAnimation()->setFramesPerSecond(21);
				m_temp->setTextColor(sf::Color(255, 215, 0, 255));
				m_temp->draw(window);
				
					//rgb(238,130,238)plasma// norma gold rgb(255,215,0)// blue rgb(0,191,255)
			}
			else
			{
				m_temp->setAnimation("buttonStill");
				m_temp->getAnimation()->setFramesPerSecond(10);
				m_temp->setTextColor(sf::Color(20, 191, 255, 255));
				m_temp->draw(window);

			}

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