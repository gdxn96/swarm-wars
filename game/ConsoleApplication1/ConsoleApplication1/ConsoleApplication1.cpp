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
#include "OptionsScene.h"
#include "GameConstants.h"
#include "HelpScene.h"
#include "SelectColorScene.h"
#include "LoadScene.h"
#include <time.h>
#include "AssetLoader.h"
#include "AudioMgr.h"
#include "LightManager.h"
#include "GameOverScene.h"
#include "GameWinScene.h"

#define _USE_MATH_DEFINES

using namespace sf;
using namespace std;


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// Don't edit this file, edit the individual scene files (George)
//   ____          U  ___ u      _   _          _____      
//  |  _"\          \/"_ \/     | \ |"|        |_ " _|     
// /| | | |         | | | |    <|  \| |>         | |       
// U| |_| |\    .-,_| |_| |    U| |\  |u        /| |\      
//  |____/ u     \_)-\___/      |_| \_|        u |_|U      
//   |||_             \\        ||   \\,-.     _// \\_     
//  (__)_)           (__)       (_")  (_/     (__) (__)    
// U _____ u      ____                          _____      
// \| ___"|/     |  _"\           ___          |_ " _|     
//  |  _|"      /| | | |         |_"_|           | |       
//  | |___      U| |_| |\         | |           /| |\      
//  |_____|      |____/ u       U/| |\u        u |_|U      
//  <<   >>       |||_       .-,_|___|_,-.     _// \\_     
// (__) (__)     (__)_)       \_)-' '-(_/     (__) (__) 
////////////////////////////////////////////////////////////


void loadAssets()
{

	AssetLoader::getInstance()->loadAnimations("./loadFiles/loadAnimations.txt");
	AssetLoader::getInstance()->loadTextures("./loadFiles/loadTextures.txt");
	AssetLoader::getInstance()->loadSounds("./loadFiles/loadSounds.txt", AudioManager::instance()->FMODsys);

	AssetLoader::getInstance()->loadAssetQueue();

	SceneManager::getInstance()->addScene(new GameScene());
	SceneManager::getInstance()->addScene(new GameOverScene());
	SceneManager::getInstance()->addScene(new GameWinScene());
	SceneManager::getInstance()->addScene(new OptionsScene());
	SceneManager::getInstance()->addScene(new HelpScene());
	SceneManager::getInstance()->addScene(new SelectColorScene());
	SceneManager::getInstance()->addScene(new MainMenuScene());
	SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
}



int main()
{
	
	if (!GameConstants::font.loadFromFile("arial.ttf") || !GameConstants::COOL_FONT.loadFromFile("stoNe.ttf"))
	{
		cout << "err loading font" << endl;
	}

	srand(time(NULL));
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y, 32), "Swarm-wars",sf::Style::Fullscreen);
	//window.setFramerateLimit(120);
	//loadAssets();
	
	
	// create scenes
	LoadScene load = LoadScene();

	//add scenes to sceneMgr
	SceneManager::getInstance()->addScene(&load);

	SceneManager::getInstance()->switchTo(Scenes::LOAD);
	
	//splash is first
	

	sf::Thread thread(&loadAssets);
	thread.launch();
	//MainMenuScene * main = new MainMenuScene();
	//main->setRenderWindow(&window);
	
	AudioManager::instance()->Update();
	
	
	


	sf::Clock deltaClock; // used to calculate dt
	float dt = 0; // floating point dt as seconds

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
		
		SceneManager::getInstance()->update(dt);
		SceneManager::getInstance()->updateInput();
		InputHandler::getInstance()->update();
		//prepare frame
		window.clear(sf::Color(0,0,0));

		//draw frame items
		LightManager::getInstance()->Update(window, dt);
		SceneManager::getInstance()->draw(window);

		// Finally, display rendered frame on screen
		
		window.display();


		dt = deltaClock.restart().asSeconds();

	} //loop back for next frame

	return EXIT_SUCCESS;
}