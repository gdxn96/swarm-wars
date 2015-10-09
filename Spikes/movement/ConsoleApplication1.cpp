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


#include "Pointer.h"
#include "Character.h"

#include <iostream> 
#include <math.h>
#define _USE_MATH_DEFINES

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "SFML/Window/Keyboard.hpp"



////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 


int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(1280, 720, 32), "SFML First Program");

	//create a pointer
	Pointer pointer(10, 0.0005f, sf::Color(30, 78, 204, 255));

	//create characters
	Character characters[MAX_CHAR];
	characters[0] = Character(sergeant, 330);
	characters[1] = Character(soldier, 300);
	characters[2] = Character(soldier, 270);


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
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();


		}

		// prepare frame
		window.clear();




		// Draw and Update stuff
		//-----------------------

		//POINTER
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			pointer.move(-1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			pointer.move(1);
		}

		pointer.draw(window);


		//CHARACTERS
		for (int i = 0; i < MAX_CHAR; i++)
		{
			characters[i].update();
			characters[i].draw(window);
		}




		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}