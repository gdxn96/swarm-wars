#include "stdafx.h"
#include "Bolt.h"


Bolt::Bolt(Pylon* left, Pylon* right) : 
m_alive(true), 
m_nodeLeft(left), 
m_nodeRight(right)
{
}

void Bolt::update(float dt)
{
	if (m_nodeLeft->getAlive() && m_nodeRight->getAlive())
	{

	}
	else
	{
		kill();
	}
}

void Bolt::draw(sf::RenderWindow& window)
{
	if (m_alive)
	{

		sf::Vertex line[] =
		{
			sf::Vertex(m_nodeLeft->getPosition().toSFMLVector()),
			sf::Vertex(m_nodeRight->getPosition().toSFMLVector())
		};

		window.draw(line, 2, sf::Lines);
	}
	
}

void Bolt::kill()
{
	m_alive = false;
}
