#include "stdafx.h"
#include "BuyMenuScene.h"
#include "AssetLoader.h"

BuyMenu::BuyMenu(UnitController * unitController, std::function<void()> repairBunkers) :
Scene(Scenes::OPTIONS), 
fn_repairBunkers(repairBunkers),
m_menuSize(GameConstants::WINDOW_SIZE * 0.9f), 
m_menuPosition(Vector2D() + GameConstants::WINDOW_SIZE * 0.05f),
m_unitController(unitController),
back(m_menuSize.toSFMLVector()),
texture(AssetLoader::getInstance()->findTextureByKey("hex")),
m_anim("BButtonAnimation", m_menuPosition + m_menuSize - (Vector2D(m_menuSize.x/2,50))),
closeB(">CLOSE<", m_menuPosition + m_menuSize - (Vector2D(m_menuSize.x / 2 + 80, 20)),80,6)
{
	m_anim.setFramesPerSecond(30);
	m_anim.setSize(Vector2D(80, 80));
	createMenuItems();
}

void BuyMenu::open()
{
	m_active = true;
}

void BuyMenu::close()
{
	m_active = false;
}

void BuyMenu::createMenuItems()
{
	for (int i = 0; i < 4; i++)
	{
		Vector2D innerMenuPosition = m_menuPosition + (m_menuSize * 0.05f);
		Vector2D innerMenuSize = m_menuSize * 0.9f;

		float height = innerMenuSize.h / 5;
		float gapBetween = height / 4;
		float width = innerMenuSize.w;
		float x = innerMenuPosition.x;
		float y = innerMenuPosition.y + ((height + gapBetween) * i);
		m_menuItems.push_back(MenuItem(Vector2D(x, y), Vector2D(width, height)));
	}

	m_currentItem = &m_menuItems.front();
	m_currentItem->setSelected(true);

	m_menuItems[SNIPER_UNIT].setAnimKey("sniperShooting");
	m_menuItems[SNIPER_UNIT].setCost(GameConstants::SNIPER_UNIT_COST);
	m_menuItems[SNIPER_UNIT].setTextField("BUY SNIPER UNIT");

	m_menuItems[BUNKER_REPAIR].setAnimKey("yellow");
	m_menuItems[BUNKER_REPAIR].setCost(GameConstants::BUNKER_REPAIR_COST);
	m_menuItems[BUNKER_REPAIR].setTextField("FIX BUNKERS");

	m_menuItems[CQB_UNIT].setAnimKey("tankShooting");
	m_menuItems[CQB_UNIT].setCost(GameConstants::CQB_UNIT_COST);
	m_menuItems[CQB_UNIT].setTextField("BUY CQB UNIT");

	m_menuItems[ASSAULT_UNIT].setAnimKey("scoutShooting");
	m_menuItems[ASSAULT_UNIT].setCost(GameConstants::ASSAULT_UNIT_COST);
	m_menuItems[ASSAULT_UNIT].setTextField("BUY ASSAULT UNIT");
}

bool BuyMenu::Active()
{
	return m_active;
}

void BuyMenu::updateInput()
{
	/////////////////////////////////temp/////////////////////////////////////////
	if (InputHandler::getInstance()->isPressed(InputHandler::DPAD_LEFT))
	{
		this->toggleActive();
	}
	//////////////////////////////////////////////////////////////////////////////
	if (InputHandler::getInstance()->isPressed(InputHandler::DPAD_DOWN))
	{
		down();
		AudioManager::instance()->PlayGameSound("select", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
	}
	if (InputHandler::getInstance()->isPressed(InputHandler::DPAD_UP))
	{
		up();
		AudioManager::instance()->PlayGameSound("select", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
	}
	if (InputHandler::getInstance()->isPressed(InputHandler::A))
	{
		buyItem();
	}
	if (InputHandler::getInstance()->isPressed(InputHandler::B))
	{
		close();
	}
}

int BuyMenu::getItemIndex()
{
	int buyIndex = -1;
	for (int i = 0; i < m_menuItems.size(); i++)
	{
		if (&m_menuItems[i] == m_currentItem)
		{
			buyIndex = i;
			break;
		}
	}

	return buyIndex;

}

void BuyMenu::buyItem()
{
	int buyIndex = getItemIndex();
	
	switch (buyIndex)
	{
	case SNIPER_UNIT:
		// buy sniper
		if (m_unitController->canBuyUnit(UNIT_TYPE::SNIPER))
		{
			m_unitController->buyUnit(UNIT_TYPE::SNIPER);
			AudioManager::instance()->PlayGameSound("click", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		else
		{
			AudioManager::instance()->PlayGameSound("denied", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		break;
	case CQB_UNIT:
		//buy shotgun
		if (m_unitController->canBuyUnit(UNIT_TYPE::CQB))
		{
			m_unitController->buyUnit(UNIT_TYPE::CQB);
			AudioManager::instance()->PlayGameSound("click", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		else
		{
			AudioManager::instance()->PlayGameSound("denied", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		break;
	case ASSAULT_UNIT:
		//buy assault rifle
		if (m_unitController->canBuyUnit(UNIT_TYPE::ASSAULT))
		{
			m_unitController->buyUnit(UNIT_TYPE::ASSAULT);
			AudioManager::instance()->PlayGameSound("click", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		else
		{
			AudioManager::instance()->PlayGameSound("denied", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		break;
	case BUNKER_REPAIR:
		// reset bunkers
		if (m_unitController->getTotalCreditAmount() > GameConstants::BUNKER_REPAIR_COST)
		{
			m_unitController->getCurrentUnit()->addCredits(-GameConstants::BUNKER_REPAIR_COST);
			AudioManager::instance()->PlayGameSound("click", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
			fn_repairBunkers();
		}
		else
		{
			AudioManager::instance()->PlayGameSound("denied", false, 0.3f, GameConstants::WINDOW_CENTRE, 1);
		}
		break;
	}
}

void BuyMenu::down()
{
	bool found = false;
	for (auto& item : m_menuItems)
	{
		if (found)
		{
			m_currentItem = &item;
			found = false;
			break;
		}
		if (m_currentItem == &item)
		{
			found = true;
			item.setSelected(false);
		}
	}

	if (found)
	{
		m_currentItem->setSelected(false);
		m_currentItem = &m_menuItems.front();
	}

	m_currentItem->setSelected(true);
}

void BuyMenu::up()
{
	bool found = false;
	MenuItem* prevItem = nullptr;
	for (auto& item : m_menuItems)
	{
		if (m_currentItem == &item && prevItem != nullptr)
		{
			found = true;
			m_currentItem->setSelected(false);
			m_currentItem = prevItem;
			break;
		}

		prevItem = &item;
	}
	if (!found)
	{
		m_menuItems.front().setSelected(false);
		m_currentItem = &m_menuItems.back();
	}

	m_currentItem->setSelected(true);
}

void BuyMenu::update(float dt)
{
	if (m_active)
	{
		for (auto& item : m_menuItems)
		{
			item.update(dt);
		}
	}

	m_anim.update(dt);
	closeB.update(dt);
}

void BuyMenu::toggleActive()
{
	m_active = !m_active;
}

void BuyMenu::draw(sf::RenderWindow &window)
{
	if (m_active)
	{
		
		back.setPosition(m_menuPosition.toSFMLVector());

			if (!m_unitController->canBuyUnit(UNIT_TYPE::SNIPER))
			{
				m_menuItems[SNIPER_UNIT].setColor(sf::Color(255, 0, 0, 40));
			}
			else
			{
				m_menuItems[SNIPER_UNIT].setColor(sf::Color(0, 191, 255, 40));
			}

			if (!m_unitController->canBuyUnit(UNIT_TYPE::CQB))
			{
				m_menuItems[CQB_UNIT].setColor(sf::Color(255, 0, 0, 40));
			}
			else
			{
				m_menuItems[CQB_UNIT].setColor(sf::Color(0, 191, 255, 40));
			}

			if (!m_unitController->canBuyUnit(UNIT_TYPE::ASSAULT))
			{
				m_menuItems[ASSAULT_UNIT].setColor(sf::Color(255, 0, 0, 40));
			}
			else
			{
				m_menuItems[ASSAULT_UNIT].setColor(sf::Color(0, 191, 255, 40));
			}

			if (m_unitController->getTotalCreditAmount() < GameConstants::BUNKER_REPAIR_COST)
			{
				m_menuItems[BUNKER_REPAIR].setColor(sf::Color(255, 0, 0, 40));
			}
			else
			{
				m_menuItems[BUNKER_REPAIR].setColor(sf::Color(0, 191, 255, 40));
			}
		back.setFillColor(sf::Color(255, 255, 255, 200));
		back.setOutlineColor(sf::Color(0, 191, 255, 180));
		back.setOutlineThickness(3);
		back.setTexture(texture);
		window.draw(back);
		m_anim.draw(window);
		closeB.draw(window);
		for (auto& menuItem : m_menuItems)
		{
			menuItem.draw(window);
		}
	}
}
