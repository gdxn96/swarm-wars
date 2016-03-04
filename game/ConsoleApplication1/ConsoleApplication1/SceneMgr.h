#pragma once

using namespace std;

//to add a scene, simply add a new enum to this list and create a new object 
//inheriting from "Scene", examples of this are given as the GameScene, SplashScene, and MainMenuScene
enum class Scenes { SPLASH, MAINMENU, OPTIONS, GAME, LOAD ,SELECT,HELP, GAME_WIN, GAME_LOSE};

#include "Scene.h"
#include <vector>
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 


class Scene;
class SceneManager
{
public:
	
	static SceneManager * getInstance();

	SceneManager();

	//update the current scene
	void update(float dt);

	void draw(sf::RenderWindow & window);

	//switch to a scene defined by the Scenes enum ie "Scenes::GAME"
	void switchTo(Scenes scene);

	//simple getter which tells you the current scene, may not be needed
	const Scene * getCurrentScene();

	//adds a scene object to the scene list
	void addScene(Scene* newScene);

	void updateInput();
	int playerColorIndex = 0;
private:
	Scene* m_currScene;
	vector<Scene*> m_scenes;

	static SceneManager * instance;

};