#pragma once

using namespace std;

//to add a scene, simply add a new enum to this list and create a new object 
//inheriting from "Scene"
enum class Scenes { SPLASH, MAINMENU, GAME };
#include "Scene.h"
#include <vector>


class Scene;
class SceneManager
{
public:
	
	static SceneManager * getInstance();

	SceneManager();

	//update the current scene
	void Update();

	//switch to a scene defined by the Scenes enum ie "Scenes::GAME"
	void switchTo(Scenes scene);

	//simple getter which tells you the current scene, may not be needed
	const Scene * getCurrentScene();

	//adds a scene object to the scene list
	void addScene(Scene* newScene);

private:
	Scene* m_currScene;
	vector<Scene*> m_scenes;

	static SceneManager * instance;

};