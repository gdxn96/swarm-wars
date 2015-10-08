#pragma once

using namespace std;
#include "Scene.h"
#include <vector>
#include "SceneList.h"

class SceneManager
{
public:
	SceneManager();
	void Update();
	void switchTo(Scenes scene);
	const Scene * getCurrentScene();
	void addScene(Scene* newScene);

private:
	Scene* m_currScene;
	vector<Scene*> m_scenes;

};