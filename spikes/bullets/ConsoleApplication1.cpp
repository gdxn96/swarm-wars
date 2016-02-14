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
#include "BulletManager.h"
#include "Weapon.h"
#define _USE_MATH_DEFINES

using namespace sf;
using namespace std;


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 
void CheckForInput(float &x, float &y, bool & isSpace, bool &isLeft, bool &isRight, bool &isUp, bool &isDown, bool &isSwitch, Weapon& myWeapon)
{
	//simple input used for testing
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isSpace)
	{
		isSpace = true;
		myWeapon.fire(Vector2D(x, y), Vector2D(400, 300));
	}
	else
	{
		isSpace = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isLeft)
	{
		isLeft = true;
		x -= 5;
	}
	else
	{
		isLeft = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isRight)
	{
		isRight = true;
		x += 5;
	}
	else
	{
		isRight = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !isUp)
	{
		isUp = true;
		y += 5;
	}
	else
	{
		isUp = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !isDown)
	{
		isDown = true;
		y -= 5;
	}
	else
	{
		isDown = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isSwitch)
	{
		isSwitch = true;
		myWeapon.switchWeapon();
		cout << "Switched weapon" << endl;
	}
	else
	{
		isSwitch = false;
	}

	cout << "XDir: " << x << endl;
	cout << "YDir: " << y << endl;
}

int main()

{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Swarm-wars");
	window.setFramerateLimit(30);

	//create a weapon, ideally in player class
	Weapon myWeapon = Weapon();

	//maintain values like direction/initial position for the player
	//didn't use angles couldn't be arsed, you get the gist though
	float x = 1, y = -1;

	//input shit, ignore it
	bool isSpace = false, isLeft = false, isRight = false, isUp = false, isDown = false, isSwitch = false;


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

			CheckForInput(x, y, isSpace, isLeft, isRight, isUp, isDown, isSwitch, myWeapon);
		}		

		//in game update loop, update the bullets via the bulletMgr
		BulletManager::getInstance()->UpdateBullets();

		//prepare frame
		window.clear();

		//draw frame items

		//in game draw loop, draw the bullets via the bulletMgr
		BulletManager::getInstance()->drawBullets(&window);

		// Finally, display rendered frame on screen 
		window.display();

	} //loop back for next frame

	return EXIT_SUCCESS;
}