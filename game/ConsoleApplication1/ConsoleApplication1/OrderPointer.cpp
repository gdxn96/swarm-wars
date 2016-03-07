#include "stdafx.h"
#include "OrderPointer.h"

using namespace sf;

OrderPointer::OrderPointer() : m_angle(0), m_radius(GameConstants::POINTER_RADIUS), m_anim("arrows", Vector2D(-111,-111))
{
	update(0,0);
	m_anim.setFramesPerSecond(20);
	m_anim.SetLooping(true);
	m_anim.setRadius(m_radius * 30);
	m_anim.setPosition(m_position);
}


void OrderPointer::update(float rad,float dt)
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
	m_anim.setPosition(m_position);
	
}
void OrderPointer::update( float dt)
{
	m_anim.update(dt);
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
	ptr.setFillColor(Color::Red);
	ptr.setOrigin(m_radius, m_radius);
	ptr.setPosition(m_position.toSFMLVector());

	if (m_angle != 2 * GameConstants::PI)
	{
		window.draw(ptr);
		m_anim.draw(window);
	}
}

// Get methods
float OrderPointer::getAngle()
{
	return m_angle;
}