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


//GLOBAL VARIABLES (FOR TESTING PURPOSES)
const int PATH_RADIUS = 200;
const float PI = std::acos(-1);


int main()
{
	// Create the main window 
	RenderWindow window(VideoMode(1280, 720, 32), "SFML First Program");


	//----------
	//Variables
	//----------
	float charRadius = 25;
	float ptrRadius = charRadius / 2.5f;

	float ptrSpd = 0.0005f;
	float charSpd = ptrSpd / 5;

	Color green = Color(50, 76, 24, 255);
	Color blue = Color(30, 78, 204, 255);
	Color yellow = Color(255, 255, 51, 255);

	Vector2f windowCentre = Vector2f(window.getSize().x / 2.0f,
									 window.getSize().y / 2.0f);



	//create objects
	Pointer pointer(ptrRadius, ptrSpd, blue, windowCentre);
	Character character(charRadius, charSpd, green, yellow, windowCentre);





	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == Event::Closed)
			{
				window.close();
			}

			// Escape key : exit 
			if ((Event.type == Event::KeyPressed) && 
				(Event.key.code == Keyboard::Escape))
			{
				window.close();
			}
		}


		// prepare frame
		window.clear();



		//Update stuff
		//-------------
		pointer.move();

		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			character.setTargetAngle(pointer.getAngle(), charSpd);
			character.setMove(true);
		}

		character.update();



		//Draw Stuff
		//-----------
		pointer.draw(window);
		character.draw(window);




		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}