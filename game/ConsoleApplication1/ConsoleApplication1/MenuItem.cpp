#include "stdafx.h"
#include "MenuItem.h"

MenuItem::MenuItem(Vector2D pos, Vector2D size) :
m_position(pos),
m_size(size),
m_selected(false),
m_anim("yellow", m_position + Vector2D(m_size.w / 4 * 1, m_size.y / 2)),
m_costText("text", m_position + Vector2D(m_size.w / 4 * 3, m_size.y / 2), 80, 6),
m_descText("text", m_position + Vector2D(m_size.w / 4 * 2, m_size.y / 2), 80, 6),
m_button("AButtonAnimation", m_position + Vector2D(m_size.w , m_size.y / 2))
{
	m_anim.setSize(Vector2D(m_size.h, m_size.h));
	m_button.setSize(Vector2D(80, 80));
	m_costText.setText("hi");
	m_descText.setText("hi");
}

void MenuItem::setSelected(bool selected)
{
	m_selected = selected;
}

bool MenuItem::getSelected()
{
	return m_selected;
}
void MenuItem::update(float dt)
{
	m_costText.update(dt);
	m_descText.update(dt);
	m_anim.update(dt);
	m_button.update(dt);
}
void MenuItem::draw(sf::RenderWindow& window)
{
	sf::RectangleShape bounds;
	bounds = sf::RectangleShape(m_size.toSFMLVector());

	bounds.setPosition(m_position.toSFMLVector());
	bounds.setFillColor(m_Color);
	if (m_selected)
	{
		bounds.setOutlineColor(sf::Color(255, 215, 0, 255));
		bounds.setOutlineThickness(3);
		m_button.draw(window);
	}

	window.draw(bounds);
	if (m_selected)
	{
		m_button.draw(window);
	}
	m_anim.draw(window);
	m_costText.draw(window);
	m_descText.draw(window);
}

void MenuItem::setCost(int cost)
{
	m_costText.setText("Cost : " + to_string(cost));
}

void MenuItem::setAnimKey(string animKey)
{
	m_anim.changeAnimation(animKey);
	if (animKey == "scoutShooting")
	{
		m_anim.setPosition(m_position + Vector2D(m_size.w / 4, m_size.y / 2 - m_size.h / 2));
	}
	else if (animKey == "sniperShooting")
	{
		m_anim.setPosition(m_position + Vector2D(m_size.w / 4, m_size.y / 2 - m_size.h / 2));
	}
	else if (animKey == "tankShooting")
	{
		m_anim.setPosition(m_position + Vector2D(m_size.w / 4, m_size.y / 2 - m_size.h / 2));
	}
	else if (animKey == "yellow")
	{
		m_anim.setPosition(m_position + Vector2D(m_size.w / 4, m_size.y / 2));
	}
}

void MenuItem::setTextField(string text)
{
	m_descText.setText(text);
}
void MenuItem::setColor(sf::Color c)
{
	m_Color = c;
}
