#pragma once
#include "Vector2D.h"
#include <cmath>

// will be used for static game constants
// NO MAGIC NUMBERS, use this
class GameConstants {
public:
	//radius in which players can walk about the centre of the map
	static float const TOWER_RADIUS; // defined in GameConstants.cpp	

	static float const WALK_RADIUS; // defined in GameConstants.cpp	
	static float const PLAYER_RADIUS; // defined in GameConstants.cpp	
	static float const PLAYER_SPEED; // defined in GameConstants.cpp

	static float const ENEMY1_RADIUS; // defined in GameConstants.cpp
	static float const ENEMY_SPAWN_INTERVAL; // defined in GameConstants.cpp
	static float const ENEMY1_SPEED; // defined in GameConstants.cpp
	static float const ENEMY1_DAMAGE_PER_SECOND; // defined in GameConstants.cpp
	static float const ENEMY1_HEALTH; // defined in GameConstants.cpp

	static float const ENEMY2_RADIUS; // defined in GameConstants.cpp
	static float const ENEMY2_SPEED; // defined in GameConstants.cpp
	static float const ENEMY2_DAMAGE_PER_SECOND; // defined in GameConstants.cpp
	static float const ENEMY2_HEALTH; // defined in GameConstants.cpp

	static float const BOSS_RADIUS; // defined in GameConstants.cpp
	static float const BOSS_SPEED; // defined in GameConstants.cpp
	static float const BOSS_DAMAGE_PER_SECOND; // defined in GameConstants.cpp
	static float const BOSS_HEALTH; // defined in GameConstants.cpp

	static float const BUNKER_SIZE_OUTER; // defined in GameConstants.cpp
	static float const BUNKER_SIZE_INNER; // defined in GameConstants.cpp
	static float const BUNKER_SIZE_WIDTH; // defined in GameConstants.cpp
	static float const BUNKER_SIZE_HEIGHT; // defined in GameConstants.cpp

	static float const BUNKER_HEALTH; // defined in GameConstants.cpp

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