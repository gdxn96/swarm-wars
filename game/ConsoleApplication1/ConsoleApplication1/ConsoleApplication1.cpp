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
#include "OptionsScene.h"
#include "GameConstants.h"
#include "HelpScene.h"
#include "SelectColorScene.h"
#include "LoadScene.h"
#include <time.h>
#include "AssetLoader.h"
#include "AudioMgr.h"
#include "LightManager.h"

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
	AssetLoader::getInstance()->addAnimationToCache("enemyAnimation", "assets/alien_sheet.png", "assets/test.json");
	AssetLoader::getInstance()->addAnimationToCache("shootingAssaltAnimation", "assets/ShootingAssaultAnimation.png", "assets/assalt.json");
	AssetLoader::getInstance()->addAnimationToCache("walingAssaltAnimation", "assets/WalkingAssaultAnimation.png", "assets/assaultWalking.json");
	AssetLoader::getInstance()->addAnimationToCache("blueBulletAnimation", "assets/blueBullet.png", "assets/blue.json");
	AssetLoader::getInstance()->addAnimationToCache("walkingLeaderAnimation", "assets/LeaderWalkinAnimation.png", "assets/LeaderWalkingAnimation.json");
	AssetLoader::getInstance()->addAnimationToCache("shootingLeaderAnimation", "assets/LeaderShootingAnimation.png", "assets/LeaderShootingAnimation.json");
	AssetLoader::getInstance()->addAnimationToCache("pylonAnimation", "assets/pylonSheet.png", "assets/pylon.json");
	AssetLoader::getInstance()->addAnimationToCache("bulletAnimation", "assets/bullet.png", "assets/bullet.json");
	AssetLoader::getInstance()->addAnimationToCache("plasmaAnimation", "assets/plasma.png", "assets/bullet.json");
	AssetLoader::getInstance()->addAnimationToCache("towerAnimation", "assets/towerAnimation.png", "assets/tower.json");
	AssetLoader::getInstance()->addAnimationToCache("bugAnimation", "assets/bugAnimation.png", "assets/bugAnimation.json");
	AssetLoader::getInstance()->addAnimationToCache("buttonActive", "assets/buttonActive.png", "assets/buttonActive.json");
	AssetLoader::getInstance()->addAnimationToCache("buttonStill", "assets/buttonStill.png", "assets/buttonActive.json");
	AssetLoader::getInstance()->addSoundToCache("background", "./GameSounds/loop.wav", AudioManager::instance()->FMODsys, true);
	AssetLoader::getInstance()->addSoundToCache("plasma", "./GameSounds/plasma.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("zum", "./GameSounds/zum.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("zun", "./GameSounds/zun.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("miss", "./GameSounds/miss.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("oof", "./GameSounds/off.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("yes", "./GameSounds/yes.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("lmg", "./GameSounds/lmg.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("pistol", "./GameSounds/pistol.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("sniper", "./GameSounds/sniper.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("shell", "./GameSounds/shell.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("Ok3", "./GameSounds/Ok3.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("Ok4", "./GameSounds/Ok4.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("select", "./GameSounds/select.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("click", "./GameSounds/click.wav", AudioManager::instance()->FMODsys, false);
	AssetLoader::getInstance()->addSoundToCache("menuSong", "./GameSounds/menuSong.wav", AudioManager::instance()->FMODsys, true);
	AssetLoader::getInstance()->addTextureToCache("spotLight", "assets/biglight.png");
	AssetLoader::getInstance()->addTextureToCache("starLight", "assets/starLight.png");
	AssetLoader::getInstance()->addTextureToCache("pointLight", "assets/spotLight.png");
	AssetLoader::getInstance()->addTextureToCache("excludeLight", "assets/excludeLight.png");
	AssetLoader::getInstance()->addTextureToCache("bumpLight", "assets/bumpLight.png");
	AssetLoader::getInstance()->addTextureToCache("floor", "assets/floor.png");
	AssetLoader::getInstance()->addTextureToCache("BGbar", "assets/BGbar.png");
	AssetLoader::getInstance()->addTextureToCache("FGBar", "assets/FGBar.png");
	AssetLoader::getInstance()->addTextureToCache("bunker", "assets/bunker.png");//UnitControllerUI
	AssetLoader::getInstance()->addTextureToCache("UnitControllerUI", "assets/UnitControllerUI.png");
	AssetLoader::getInstance()->addAnimationToCache("staticAnimation", "assets/staticAnimation.png", "assets/staticAnimation.json");
	AssetLoader::getInstance()->addAnimationToCache("selectorAnimation", "assets/selectorAnimation.png", "assets/selectorAnimation.json");
	AssetLoader::getInstance()->addAnimationToCache("greenWeaponAnimation", "assets/greenWeaponAnimation.png", "assets/greenWeaponAnimation.json");
	AssetLoader::getInstance()->addAnimationToCache("blueWeaponAnimation", "assets/blueWeaponAnimation.png", "assets/blueWeaponAnimation.json");
	AssetLoader::getInstance()->addTextureToCache("RankA", "assets/rank/a.png");
	AssetLoader::getInstance()->addTextureToCache("RankB", "assets/rank/b.png");
	AssetLoader::getInstance()->addTextureToCache("RankC", "assets/rank/c.png");
	AssetLoader::getInstance()->addTextureToCache("RankD", "assets/rank/d.png");
	AssetLoader::getInstance()->addTextureToCache("RankE", "assets/rank/e.png");
	AssetLoader::getInstance()->addTextureToCache("RankF", "assets/rank/f.png");
	AssetLoader::getInstance()->addTextureToCache("RankG", "assets/rank/g.png");
	AssetLoader::getInstance()->addTextureToCache("button", "assets/button.png");
	AssetLoader::getInstance()->addTextureToCache("bgMenu", "assets/bgMenu.png");
	AssetLoader::getInstance()->addTextureToCache("buttonClick", "assets/button Click.png");
	AssetLoader::getInstance()->addAnimationToCache("UiSolderAnimation", "assets/UiSolderAnimation.png", "assets/UiSolderAnimation.json");

	

}



int main()
{
	
	if (!GameConstants::font.loadFromFile("arial.ttf"))
	{
		cout << "err loading font" << endl;
	}

	srand(time(NULL));
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(GameConstants::WINDOW_SIZE.x, GameConstants::WINDOW_SIZE.y, 32), "Swarm-wars");
	window.setFramerateLimit(30);
	loadAssets();
	MainMenuScene * main = new MainMenuScene();
	main->setRenderWindow(&window);
	SceneManager::getInstance()->addScene(main);
	SceneManager::getInstance()->addScene(new GameScene());
	SceneManager::getInstance()->addScene(new SplashScene());
	SceneManager::getInstance()->addScene(new OptionsScene());
	SceneManager::getInstance()->addScene(new HelpScene());
	SceneManager::getInstance()->addScene(new SelectColorScene());
	SceneManager::getInstance()->switchTo(Scenes::MAINMENU);
	// create scenes
	LoadScene load = LoadScene();

	//add scenes to sceneMgr
	SceneManager::getInstance()->addScene(&load);

	//splash is first
	

	/*sf::Thread thread(&loadAssets);
	thread.launch();*/
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
		SceneManager::getInstance()->draw(window);

		// Finally, display rendered frame on screen
		LightManager::getInstance()->Update(window, dt);
		window.display();


		dt = deltaClock.restart().asSeconds();

	} //loop back for next frame

	return EXIT_SUCCESS;
}