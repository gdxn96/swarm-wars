#include "stdafx.h" 
#include "Scene.h"

using namespace std;


Scene::Scene(Scenes title) : m_title(title), alive(false)
{
}

void Scene::enter()
{
	alive = true;
}

void Scene::exit()
{
	alive = false;
}

const Scenes Scene::getTitle()
{
	return m_title;
}
