#pragma once
#include "SceneMgr.h"
#include <iostream>
using namespace std;
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include "GameConstants.h"


class Scene
{
public:
	
	Scene(Scenes title);

	//called automatically when a scene becomes active, used in sceneMgr
	virtual void enter();

	//called automatically when a scene becomes inactive, used in sceneMgr
	virtual void exit();
	
	//simple method that returns the title of the scene, used in sceneMgr
	const Scenes getTitle();

	virtual void update(float dt) = 0;
	virtual void updateInput() = 0;
	virtual void draw(sf::RenderWindow &window) = 0;

protected:
	Scenes m_title;

};

