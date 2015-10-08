#pragma once
#include "SceneList.h"
#include <iostream>
using namespace std;

class Scene
{
public:
	Scene(Scenes title);
	virtual void enter();
	virtual void update() = 0;
	virtual void exit();
	virtual void pause() = 0;
	virtual void draw() = 0;
	const Scenes getTitle();

protected:
	Scenes m_title;
	string m_name;
	bool alive;

};

