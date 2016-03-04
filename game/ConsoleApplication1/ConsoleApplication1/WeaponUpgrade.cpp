#include "stdafx.h"
#include "WeaponUpgrade.h"


WeaponUpgrade::WeaponUpgrade()
{
}

WeaponUpgrade::WeaponUpgrade(Vector2D _position, Vector2D _size):
m_topShape(_size.toSFMLVector()),
m_bottomShape(_size.toSFMLVector()),
m_position(_position),
m_cellWidth(_size.x),
m_cellHeight(_size.y),
m_offsetHeight(60),
m_offsetWidth(60),
m_offsetedPosition(_position + Vector2D(m_offsetWidth, -m_offsetHeight)),
m_weaponNameBottom(">Name<", m_position, 80, 6, "stoNe.tff"),
m_weaponNameTop(">Name<",m_position,80,6,"stoNe.tff"),
m_topDMGbar(m_position,Vector2D(0.5f,0.5f),WeaponStats::WEAPON_MAX_DMG),
m_topRoFBar(m_position,Vector2D(0.5f, 0.5f), WeaponStats::WEAPON_MAX_RoF),
m_bottomDMGbar(m_position, Vector2D(0.5f, 0.5f), WeaponStats::WEAPON_MAX_DMG),
m_bottomRoFBar(m_position, Vector2D(0.5f, 0.5f), WeaponStats::WEAPON_MAX_RoF),
m_topButtonAnimation("YButtonAnimation",m_position),
m_bottomButtonAnimation("AButtonAnimation",m_position),
m_currentWeapon(nullptr)
{
	m_topShape.setPosition(m_offsetedPosition.toSFMLVector());
	m_bottomShape.setPosition(Vector2D(m_offsetedPosition + Vector2D(0, m_cellHeight)).toSFMLVector());

	m_topShape.setFillColor(sf::Color(255, 255, 255, 12));
	m_topShape.setOutlineColor(sf::Color(135, 206, 250, 255));
	m_topShape.setOutlineThickness(2);
	m_topShape.setSize(_size.toSFMLVector());

	m_bottomShape.setFillColor(sf::Color(255, 255, 255, 12));
	m_bottomShape.setOutlineColor(sf::Color(135, 206, 250, 255));
	m_bottomShape.setOutlineThickness(2);
	m_bottomShape.setSize(_size.toSFMLVector());

	m_topButtonAnimation.setFramesPerSecond(20);
	m_topButtonAnimation.SetLooping(true);
	m_topButtonAnimation.setRadius(m_cellWidth/3);

	m_bottomButtonAnimation.setFramesPerSecond(20);
	m_bottomButtonAnimation.SetLooping(true);
	m_bottomButtonAnimation.setRadius(m_cellWidth / 3);
}
void WeaponUpgrade::setCurrentWeapon(Weapon * _weapon)
{
	m_currentWeapon = _weapon;
}


void WeaponUpgrade::update(float dt)
{
	updateInput(dt);
	if (m_isActive)
	{
		
		m_offsetedPosition = m_position + Vector2D(m_offsetWidth, -m_offsetHeight);
		m_topShape.setPosition(m_offsetedPosition.toSFMLVector());
		m_bottomShape.setPosition(Vector2D(m_offsetedPosition + Vector2D(0, m_cellHeight)).toSFMLVector());
		
		m_weaponNameTop.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth + 10, m_cellWidth - 10)));
		m_weaponNameTop.setText(m_currentWeapon->getName());
		m_weaponNameTop.setColor(sf::Color(135, 206, 250, 255));
		m_weaponNameTop.update(dt);

		m_weaponNameBottom.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth + 10, (m_cellHeight)+50)));
		m_weaponNameBottom.setText(name);
		m_weaponNameBottom.setColor(sf::Color(135, 206, 250, 255));
		m_weaponNameBottom.update(dt);

		m_topDMGbar.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth + 10, 10)));
		m_topRoFBar.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth + 10, 50)));
		m_bottomDMGbar.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth + 10, (m_cellHeight ) + 10)));
		m_bottomRoFBar.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth + 10, (m_cellHeight ) + 50)));

		m_topDMGbar.update();
		m_topRoFBar.update();
		m_bottomDMGbar.update();
		m_bottomRoFBar.update();

		m_topButtonAnimation.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth / 3, -m_cellWidth/3)));
		m_bottomButtonAnimation.setPosition(Vector2D(m_offsetedPosition + Vector2D(m_cellWidth / 3, m_cellWidth*2 +m_cellWidth/3)));

		m_topButtonAnimation.update(dt);
		m_bottomButtonAnimation.update(dt);
	}
	setWeaponStats();

}
void WeaponUpgrade::updateInput(float dt)
{
	InputHandler* input = InputHandler::getInstance();
	
}
void WeaponUpgrade::setWeaponStats()
{
	if (m_currentWeapon != nullptr || m_currentWeapon != NULL || m_currentWeapon != 0)
	{
		m_topDMGbar.setCurrentAmount(m_currentWeapon->getDamage());
		m_topRoFBar.setCurrentAmount(m_currentWeapon->getRoF());
	}
}

void WeaponUpgrade::setRank(UNIT_RANK  _rank)
{
	m_rank = _rank;
	if (m_rank == UNIT_RANK::A)
	{

	}
	else if (m_rank == UNIT_RANK::B)
	{
		m_bottomDMGbar.setCurrentAmount(WeaponStats::PLASMA_DMG);
		m_bottomRoFBar.setCurrentAmount(WeaponStats::PLASMA_FIRE_RATE);
		name = ">PLASMA<";
	}
	else if (m_rank == UNIT_RANK::C)
	{
		m_bottomDMGbar.setCurrentAmount(WeaponStats::LMG_DMG);
		m_bottomRoFBar.setCurrentAmount(WeaponStats::LMG_FIRE_RATE);
		name = ">LMG<";
	}
	else if (m_rank == UNIT_RANK::D)
	{
		m_bottomDMGbar.setCurrentAmount(WeaponStats::AK_DMG);
		m_bottomRoFBar.setCurrentAmount(WeaponStats::AK_FIRE_RATE);
		name = ">AK<";
	}
	else if (m_rank == UNIT_RANK::E)
	{
		m_bottomDMGbar.setCurrentAmount(WeaponStats::SHOTGUN_DMG);
		m_bottomRoFBar.setCurrentAmount(WeaponStats::SHOTGUN_FIRE_RATE);
		name = ">SHOTGUN<";
	}
	else if (m_rank == UNIT_RANK::F)
	{
		m_bottomDMGbar.setCurrentAmount(WeaponStats::SMG_DMG);
		m_bottomRoFBar.setCurrentAmount(WeaponStats::SMG_FIRE_RATE);
		name = ">SMG<";
	}
	else if (m_rank == UNIT_RANK::G)
	{
		m_bottomDMGbar.setCurrentAmount(WeaponStats::SNIPER_DMG);
		m_bottomRoFBar.setCurrentAmount(WeaponStats::SNIPER_FIRE_RATE);
		name = ">SNIPER<";
	}
}


void WeaponUpgrade::setIsActive(bool _isActive)
{
	m_isActive = _isActive;
}

void WeaponUpgrade::draw(sf::RenderWindow & window)
{
	if (m_isActive)
	{
		window.draw(m_topShape);
		window.draw(m_bottomShape);
		sf::Vertex line[] =
		{
			sf::Vertex(m_position.toSFMLVector()),
			sf::Vertex(m_offsetedPosition.toSFMLVector())
		};
		for (auto & v : line)
		{
			v.color = sf::Color(135, 206, 250, 255);
		}
		window.draw(line, 2, sf::Lines);
		m_topDMGbar.draw(window);
		m_topRoFBar.draw(window);
		m_bottomDMGbar.draw(window);
		m_bottomRoFBar.draw(window);
		

		m_topButtonAnimation.draw(window);
		m_bottomButtonAnimation.draw(window);

		m_weaponNameBottom.draw(window);
		m_weaponNameTop.draw(window);
	}
}
void WeaponUpgrade::setPosition(Vector2D _postion)
{
	m_position = _postion;
}


WeaponUpgrade::~WeaponUpgrade()
{
}