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
#include "SceneMgr.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "SplashScene.h"
#define _USE_MATH_DEFINES

using namespace sf;
using namespace std;


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Swarm-wars");

	
	GameScene game = GameScene();
	SplashScene splash = SplashScene();
	MainMenuScene menu = MainMenuScene();

	SceneManager::getInstance()->addScene(&game);
	SceneManager::getInstance()->addScene(&splash);
	SceneManager::getInstance()->addScene(&menu);
	SceneManager::getInstance()->switchTo(Scenes::GAME);
	SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	SceneManager::getInstance()->switchTo(Scenes::SPLASH);

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

			/////////////////////////////////////////////////////////////////////////////////////////////////
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
			{
				SceneManager::getInstance()->switchTo(Scenes::GAME);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			{
				SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				SceneManager::getInstance()->switchTo(Scenes::SPLASH);
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////

		}

		SceneManager::getInstance()->Update();
		//prepare frame
		window.clear();

		//draw frame items
		//window.draw(myShape);

		// Finally, display rendered frame on screen 
		window.display();

	} //loop back for next frame

	return EXIT_SUCCESS;
}