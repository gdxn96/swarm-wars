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

#include "SpriteSheetManager.h"
#include "Vector2D.h"

using namespace sf;
using namespace std;


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Swarm-wars");
	sf::Texture mySpriteSheet;

	mySpriteSheet.loadFromFile("assets/dude.png");

	SpriteSheetManager Animation = SpriteSheetManager(mySpriteSheet, 6, 4, Vector2D(150, 150));
	Animation.setAnimationNameToIndex(0, "blood pop");
	Animation.setAnimationNameToIndex(1, "running");
	Animation.setRunningAnimation("running");
	Animation.setIsLooping(true);
	Animation.setRotation(70);
	Animation.setScale(Vector2D(2, 2));
	Animation.willDie = false;
	

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
		Animation.Update();
		


		//prepare frame
		window.clear();

		Animation.Draw(window);

		//draw frame items

		// Finally, display rendered frame on screen 
		window.display();

	} //loop back for next frame

	return EXIT_SUCCESS;
}