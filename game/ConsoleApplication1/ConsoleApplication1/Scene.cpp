#include "stdafx.h" 
#include "Scene.h"

using namespace std;


Scene::Scene(Scenes title) : m_title(title)
{
}

void Scene::enter()
{
}

void Scene::exit()
{
}

const Scenes Scene::getTitle()
{
	return m_title;
}
