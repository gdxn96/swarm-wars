#pragma once
#include "Vector2D.h"
#include <cmath>
#include <vector>

// will be used for static game constants
// NO MAGIC NUMBERS, use this

enum class UNIT_RANK { A, B, C, D, E, F, G };



class GameConstants {
public:
	static sf::Font font;
	static float const EXPERENCE_AMOUNT;
	static int const CREDIT_AMOUNT;

	//radius in which players can walk about the centre of the map
	static float const TOWER_RADIUS; // defined in GameConstants.cpp	
	static float const TOWER_HEALTH; // defined in GameConstants.cpp

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

	static const std::vector<std::pair<UNIT_RANK, int>> EXP_RANKS;

	static Vector2D const WINDOW_CENTRE;// defined in GameConstants.cpp	
	static Vector2D const WINDOW_SIZE;// defined in GameConstants.cpp	

};

class WeaponStats 
{
public:
	//AK Stuff
	static float const AK_DMG;// defined in GameConstants.cpp	
	static float const AK_RANGE;// defined in GameConstants.cpp	
	static float const AK_FOV;// defined in GameConstants.cpp	
	static float const AK_FIRE_RATE;// defined in GameConstants.cpp


	//Plasma gun stuff
	static float const PLASMA_DMG;// defined in GameConstants.cpp	
	static float const PLASMA_RANGE;// defined in GameConstants.cpp	
	static float const PLASMA_FOV;// defined in GameConstants.cpp	
	static float const PLASMA_FIRE_RATE;// defined in GameConstants.cpp

	//sniper
	static float const SNIPER_DMG;// defined in GameConstants.cpp	
	static float const SNIPER_RANGE;// defined in GameConstants.cpp	
	static float const SNIPER_FOV;// defined in GameConstants.cpp	
	static float const SNIPER_FIRE_RATE;// defined in GameConstants.cpp

	//shotgun
	static float const SHOTGUN_DMG;// defined in GameConstants.cpp	
	static float const SHOTGUN_RANGE;// defined in GameConstants.cpp	
	static float const SHOTGUN_FOV;// defined in GameConstants.cpp	
	static float const SHOTGUN_FIRE_RATE;// defined in GameConstants.cpp

	//LMG
	static float const LMG_DMG;// defined in GameConstants.cpp	
	static float const LMG_RANGE;// defined in GameConstants.cpp	
	static float const LMG_FOV;// defined in GameConstants.cpp	
	static float const LMG_FIRE_RATE;// defined in GameConstants.cpp

	//SMG
	static float const SMG_DMG;// defined in GameConstants.cpp	
	static float const SMG_RANGE;// defined in GameConstants.cpp	
	static float const SMG_FOV;// defined in GameConstants.cpp	
	static float const SMG_FIRE_RATE;// defined in GameConstants.cpp

	//pistol
	static float const PISTOL_DMG;// defined in GameConstants.cpp	
	static float const PISTOL_RANGE;// defined in GameConstants.cpp	
	static float const PISTOL_FOV;// defined in GameConstants.cpp	
	static float const PISTOL_FIRE_RATE;// defined in GameConstants.cpp
};

class BULLET_STATS
{
public:
	//Simple
	static float const SIMPLE_SPEED;// defined in GameConstants.cpp	
	static std::string const SIMPLE_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const SIMPLE_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SIMPLE_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SIMPLE_COLOR;// defined in GameConstants.cpp
	static const std::string SIMPLE_AUDIO_NAME;// defined in GameConstants.cpp

	//PLASMA
	static float const PLASMA_SPEED;// defined in GameConstants.cpp	
	static std::string const PLASMA_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const PLASMA_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PLASMA_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PLASMA_COLOR;// defined in GameConstants.cpp
	static const std::string PLASMA_AUDIO_NAME;// defined in GameConstants.cpp

	//sniper
	static float const SNIPER_SPEED;// defined in GameConstants.cpp	
	static std::string const SNIPER_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const SNIPER_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SNIPER_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SNIPER_COLOR;// defined in GameConstants.cpp
	static const std::string SNIPER_AUDIO_NAME;// defined in GameConstants.cpp

	//lmg
	static float const LMG_SPEED;// defined in GameConstants.cpp	
	static std::string const LMG_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const LMG_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const LMG_RADIUS;// defined in GameConstants.cpp
	static const sf::Color LMG_COLOR;// defined in GameConstants.cpp
	static const std::string LMG_AUDIO_NAME;// defined in GameConstants.cpp

	//smg
	static float const SMG_SPEED;// defined in GameConstants.cpp	
	static std::string const SMG_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const SMG_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SMG_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SMG_COLOR;// defined in GameConstants.cpp
	static const std::string SMG_AUDIO_NAME;// defined in GameConstants.cpp

	//pistol
	static float const PISTOL_SPEED;// defined in GameConstants.cpp	
	static std::string const PISTOL_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const PISTOL_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PISTOL_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PISTOL_COLOR;// defined in GameConstants.cpp
	static const std::string PISTOL_AUDIO_NAME;// defined in GameConstants.cpp

	//shotgun
	static float const SHOTGUN_SPEED;// defined in GameConstants.cpp	
	static std::string const SHOTGUN_TEXTURE_KEY;// defined in GameConstants.cpp	
	static float const SHOTGUN_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SHOTGUN_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SHOTGUN_COLOR;// defined in GameConstants.cpp
	static const std::string SHOTGUN_AUDIO_NAME;// defined in GameConstants.cpp


};
