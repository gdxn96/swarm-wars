#pragma once
#include "Vector2D.h"
#include <cmath>

// will be used for static game constants
// NO MAGIC NUMBERS, use this
class GameConstants {
public:
	//radius in which players can walk about the centre of the map
	static int const WALK_RADIUS; // defined in GameConstants.cpp	
	static float const PLAYER_RADIUS; // defined in GameConstants.cpp	
	static float const PLAYER_SPEED; // defined in GameConstants.cpp

	static float const PI; // defined in GameConstants.cpp	
	static float const POINTER_RADIUS;// defined in GameConstants.cpp	

	static Vector2D const WINDOW_CENTRE;// defined in GameConstants.cpp	
	static Vector2D const WINDOW_SIZE;// defined in GameConstants.cpp	

};

class WeaponStats 
{
public:
	//AK Stuff
	static int const AK_DMG;// defined in GameConstants.cpp	
	static int const AK_RANGE;// defined in GameConstants.cpp	

	//Plasma gun stuff
	static int const PLASMA_DMG;// defined in GameConstants.cpp	
	static int const PLASMA_RANGE;// defined in GameConstants.cpp	
};