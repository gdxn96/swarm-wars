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

void Scene::updateInput()
{

}

const Scenes Scene::getTitle()
{
	return m_title;
}
