#pragma once

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp"



class Enemy
{
private:
	sf::Vector2f m_pos;
	sf::Vector2f m_targetNode;
	sf::Vector2f m_dir;
	float m_speed;
	float m_radius;
	//True when waiting for new target node
	bool m_atTargetNode;
	//True when finished path
	bool m_atFinalNode;
	sf::CircleShape m_shape;

public:
	Enemy();
	Enemy(sf::Vector2f, float, sf::Color);
	void update();
	void draw(sf::RenderWindow*);
	void updatePos();
	sf::Vector2f normalise(sf::Vector2f);		// Using these methods until
	float length(sf::Vector2f);					// incorporating Vector class
	sf::Vector2f getPos();
	bool atTargetNode();
	bool atFinalNode();
	void setTargetNode(sf::Vector2f);
	void setAtFinalNode(bool);
};