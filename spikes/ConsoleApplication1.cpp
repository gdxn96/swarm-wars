//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include "Enemy.h"

using namespace sf;
using namespace std;


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Swarm-wars");
	window.setFramerateLimit(60);

	//Variables
	float enemySpd = 3;
	sf::Color red = sf::Color(255, 0, 0, 255);
	int index = 0;
	vector<sf::Vector2f> nodes;
	nodes.push_back(sf::Vector2f(-60, -60));	// Hard-coded values since unit 
	nodes.push_back(sf::Vector2f(30, 300));		// manager will be responsible 
	nodes.push_back(sf::Vector2f(200, 400));	// for creation of nodes later
	nodes.push_back(sf::Vector2f(400, 300));

	Enemy enemy(nodes.at(index), enemySpd, red);




	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && 
				(Event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		//prepare frame
		window.clear();

		//UPDATE & DRAW
		if (enemy.atTargetNode())
		{
			index++;	//next node

			//If not at final node in path
			if (!enemy.atFinalNode())
			{
				if (index < nodes.capacity())
				{
					enemy.setTargetNode(nodes.at(index));
					enemy.update();
				}
				else 
				{
					enemy.setAtFinalNode(true);
				}
			}
			
		}

		
		enemy.draw(&window);

		// Finally, display rendered frame on screen 
		window.display();

	} //loop back for next frame

	return EXIT_SUCCESS;
}