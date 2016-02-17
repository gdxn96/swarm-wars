#include "stdafx.h"
#include "OrderPointer.h"

using namespace sf;

OrderPointer::OrderPointer() : m_angle(0), m_radius(GameConstants::POINTER_RADIUS)
{
	update(0);
}


void OrderPointer::update(float rad)
{
	//normalize the angle passed in
	m_angle = NormalizeAngle(rad);
	
	//calculate the position corresponding to the angle, using the window-origin as centre
	Vector2D offset = Vector2D(GameConstants::WALK_RADIUS * cos(m_angle), 
		GameConstants::WALK_RADIUS * sin(m_angle));

	//get window centre
	Vector2D window_centre = GameConstants::WINDOW_CENTRE;

	//add the window centre and the offset to create the real position
	m_position = window_centre + offset;
}

float OrderPointer::NormalizeAngle(float angle)
{
	float PI = GameConstants::PI;
	while (angle <= -0) angle += 2 * PI;
	while (angle > 2 * PI) angle -= 2 * PI;
	return angle;
}


void OrderPointer::draw(RenderWindow & window)
{
	//this might hopefully be polished to something better
	// thats why all of the draw code is located here,
	// for easy modification/scrapping
	sf::CircleShape ptr = sf::CircleShape(m_radius);
	ptr.setFillColor(Color::Yellow);
	ptr.setOrigin(m_radius, m_radius);
	ptr.setPosition(m_position.toSFMLVector());

	if (m_angle != 2 * GameConstants::PI)
	window.draw(ptr);
}

// Get methods
float OrderPointer::getAngle()
{
	return m_angle;
}