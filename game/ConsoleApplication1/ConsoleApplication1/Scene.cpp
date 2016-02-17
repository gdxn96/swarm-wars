#include "stdafx.h" 
#include "Scene.h"

using namespace std;


Scene::Scene(Scenes title) : m_title(title)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		cout << "err loading font" << endl;
	}
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
