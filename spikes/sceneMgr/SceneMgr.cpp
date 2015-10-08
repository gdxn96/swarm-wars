#include "stdafx.h" 
#include "SceneMgr.h"

SceneManager::SceneManager() : m_currScene(nullptr)
{

}

void SceneManager::Update()
{
	m_currScene->update();
	m_currScene->draw();
}

void SceneManager::switchTo(Scenes title)
{
	bool sceneFound = false;
	int i = 0;
	Scene* nextScene = nullptr;
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
			m_currScene->exit();
		}

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