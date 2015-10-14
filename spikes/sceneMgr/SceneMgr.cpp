#include "stdafx.h" 
#include "SceneMgr.h"

SceneManager * SceneManager::instance = 0;

SceneManager::SceneManager() : m_currScene(nullptr)
{

}

void SceneManager::Update()
{
	//dynamic typing
	m_currScene->update();
	m_currScene->draw();
}

SceneManager * SceneManager::getInstance()
{
	//singleton getter
	if (instance == 0)
	{
		instance = new SceneManager();
	}
	return instance;
}

void SceneManager::switchTo(Scenes title)
{
	bool sceneFound = false;
	int i = 0;
	Scene* nextScene = nullptr;

	//checks if the scene is there, if it isn't, do nothing
	while (i < m_scenes.size() && !sceneFound)
	{
		if (m_scenes.at(i)->getTitle() == title)
		{
			sceneFound = true;
			nextScene = m_scenes.at(i);
		}
		i++;
	}

	if (sceneFound)
	{
		if (m_currScene != nullptr)
		{
			//exit the old scene 
			m_currScene->exit();
		}

		//enter the new scene
		m_currScene = nextScene;
		m_currScene->enter();
	}
	else
	{
		printf("scene not found");
	}
}

const Scene * SceneManager::getCurrentScene()
{
	return m_currScene;
}

void SceneManager::addScene(Scene* newScene)
{
	m_scenes.push_back(newScene);
}