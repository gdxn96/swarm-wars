#pragma once
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 

enum class UNIT_STATE { MOVING, WAITING };
class Unit
{
public:

	Unit();
	void update(float dt);
	void draw(sf::RenderWindow & window);
	void moveToAngle(float targetAngle);



private:
	float m_angle;
	Vector2D m_direction;
	Vector2D m_position;


};

