#include "stdafx.h"
#include "UpgradeElement.h"

UpgradeElement::UpgradeElement(Unit * unit) 
	:	m_parentUnit(unit), 
		m_alive(true),
		m_anim("staticAnimation", Vector2D(-100,-100)),
		m_bgAnim("staticAnimation", Vector2D(-100, -100)),
		UIText(">UPGRADE<", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 210)), 50, 6),
		dmg(">DMG< : ", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 100)), 255, 0),
		fireRate(">Fire Rate< : ", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 70)), 255, 0),
		Name(">Weapon< : ", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 40)), 255, 0)
{
	string uiElementKey = "default";
	m_key = uiElementKey;
	m_icon.addPoint(GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(GameConstants::WINDOW_CENTRE.x, 0));
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(0, GameConstants::WINDOW_CENTRE.y));
	animationInit();
	dmg.setColor(sf::Color(255, 215, 0, 255));
	fireRate.setColor(sf::Color(255, 215, 0, 255));
	Name.setColor(sf::Color(255, 215, 0, 255));
	f.loadFromFile("stoNe.ttf");
}

UpgradeElement::UpgradeElement(Unit* unit, WeaponType weapon, string uiElementKey) 
	:	m_alive(true), 
		m_parentUnit(unit), 
		m_weaponType(weapon),
		m_key(uiElementKey),
		m_anim("staticAnimation", Vector2D(-100, -100)),
		m_bgAnim("staticAnimation", Vector2D(-100, -100)),
		UIText(">UPGRADE<", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 210)), 50, 6),
		dmg(">DMG< : ", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 100)), 255, 0),
		fireRate(">Fire Rate< : ", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 70)), 255, 0),
		Name(">Weapon< : ", Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 40)), 255,0)
{
	m_icon.addPoint(GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(GameConstants::WINDOW_CENTRE.x, 0));
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + GameConstants::WINDOW_CENTRE);
	m_icon.addPoint(GameConstants::WINDOW_CENTRE + Vector2D(0, GameConstants::WINDOW_CENTRE.y));
	animationInit();
	dmg.setColor(sf::Color(255, 215, 0, 255));
	fireRate.setColor(sf::Color(255, 215, 0, 255));
	Name.setColor(sf::Color(255, 215, 0, 255));
	f.loadFromFile("stoNe.ttf");
}

void UpgradeElement::animationInit()
{
	m_anim.setFramesPerSecond(30);
	m_anim.SetLooping(true);
	m_anim.setSize(250, 170);
	m_anim.setPosition(GameConstants::WINDOW_SIZE - Vector2D(250,170)/2);
	m_bgAnim.setFramesPerSecond(30);
	m_bgAnim.SetLooping(true);
	m_bgAnim.setSize(250, 170);
	m_bgAnim.setPosition(GameConstants::WINDOW_SIZE - Vector2D(250, 170) / 2);
	bg.setFillColor(sf::Color(255, 255, 255, 12));
	bg.setOutlineColor(sf::Color(135, 206, 250, 255));
	bg.setOutlineThickness(2);
	bg.setSize(sf::Vector2f(250, 170));
	bg.setPosition(Vector2D(GameConstants::WINDOW_SIZE - Vector2D(250, 170)).toSFMLVector());
}

void UpgradeElement::accept()
{
	//upgrade weapon
	m_parentUnit->setWeapon(WeaponFactory::getInstance()->getNewWeapon(m_weaponType));
	kill();
}

Unit* UpgradeElement::getParentUnit()
{
	return m_parentUnit;
}

void UpgradeElement::kill()
{
	m_alive = false;
}

bool UpgradeElement::isAlive()
{
	return m_alive;
}

void UpgradeElement::update(float dt)
{
	m_anim.update(dt);
	m_bgAnim.update(dt);
	UIText.update(dt);
	dmg.update(dt);
	fireRate.update(dt);
	Name.update(dt);
}

void UpgradeElement::updateInput()
{
	if (m_key != "default")
	{
		InputHandler* input = InputHandler::getInstance();
		if (input->isPressed(InputHandler::Y))
		{
			kill();
		}
		else if (input->isPressed(InputHandler::X))
		{
			accept();
		}
	}
}


void UpgradeElement::draw(sf::RenderWindow&window)
{
	std::string name = m_anim.getName();
	if (m_key == "default")
	{
		changeUI("UiSolderAnimation", Vector2D(190, 155), Vector2D(100, 85));
		UIText.setText(">STATS<");
		dmg.setText("");
		fireRate.setText("");
		Name.setText("" );
	}
	else if (m_key == "plasma")
	{
		changeUI("greenWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");	
		dmg.setText(">DMG< : " + numberToString(WeaponStats::PLASMA_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::PLASMA_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}
	else if (m_key == "ak")
	{
		changeUI("greenWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");
		dmg.setText(">DMG< : " + numberToString(WeaponStats::AK_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::AK_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}
	else if (m_key == "lmg")
	{
		changeUI("greenWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");
		dmg.setText(">DMG< : " + numberToString(WeaponStats::LMG_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::LMG_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}
	else if (m_key == "pistol")
	{
		changeUI("greenWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");
		dmg.setText(">DMG< : " + numberToString(WeaponStats::PISTOL_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::PISTOL_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}
	else if (m_key == "shotgun")
	{
		changeUI("greenWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");
		dmg.setText(">DMG< : " + numberToString(WeaponStats::SHOTGUN_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::SHOTGUN_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}
	else if (m_key == "smg")
	{
		changeUI("blueWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");
		dmg.setText(">DMG< : " + numberToString(WeaponStats::SMG_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::SMG_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}
	else if (m_key == "sniper")
	{
		changeUI("greenWeaponAnimation", Vector2D(190, 145), Vector2D(140, 85));
		UIText.setText(">UPGRADE<");
		dmg.setText(">DMG< : " + numberToString(WeaponStats::SNIPER_DMG));
		fireRate.setText(">RoF< : " + numberToString(WeaponStats::SNIPER_FIRE_RATE));
		Name.setText(">GUN< : " + m_key);
	}

	a.setFont(f);
	a.setString(m_key);
	//window.draw(a);
	window.draw(bg);
	m_anim.draw(window);
	dmg.draw(window);
	fireRate.draw(window);
	Name.draw(window);
	m_bgAnim.draw(window);
	UIText.draw(window);
}

void UpgradeElement::changeUI(string name, Vector2D position, Vector2D size)
{
	m_anim.setSize(size);
	m_anim.setPosition(GameConstants::WINDOW_SIZE - position);
	m_anim.changeAnimation(name);
}

