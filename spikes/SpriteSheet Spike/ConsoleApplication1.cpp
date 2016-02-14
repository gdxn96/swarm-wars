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

#include "AnimationManager.h"
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
	//load the spritesheet
	mySpriteSheet.loadFromFile("assets/dude.png");
	//create the animation manager object(texture , coulmn amount, row amount,position,scale)
	AnimationManager Animation = AnimationManager(mySpriteSheet, 6, 4, Vector2D(150, 150),Vector2D(1,1));
	//sets a name to a row to call later. these must be set or the animation
	//manager wont be able to refrence that row
	Animation.setAnimationNameToIndex(0, "blood pop");//sets the name "blood pop" to row 0
	Animation.setAnimationNameToIndex(1, "running");//sets the name "running" to row 1
	Animation.setRunningAnimation("running");//sets the starting animation to running
	Animation.setIsLooping(true);//sets if the animation is looping
	Animation.setRotation(70);//sets the rotation of the object
	Animation.setScale(Vector2D(2, 2));//set the scale of the object
	Animation.willDie = false;// sets if the object will die or not
				  // if its dead dont draw/destroy
	

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
		//update the animation object
		Animation.Update();
		


		//prepare frame
		window.clear();
		//draw the animation object
		Animation.Draw(window);

		//draw frame items

		// Finally, display rendered frame on screen 
		window.display();

	} //loop back for next frame

	return EXIT_SUCCESS;
}
