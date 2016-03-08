#pragma once
#include "Vector2D.h"
#include <cmath>
#include <vector>

// will be used for static game constants
// NO MAGIC NUMBERS, use this

enum class UNIT_RANK { A, B, C, D, E, F, G };
enum class ENEMY {ENEMY1, ENEMY2, BOSS};

class WAVE_CONSTANTS
{
public :
	static float const WAVE1_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE1_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE1_BOSS_SPAWN_INTERVAL;
	static float const WAVE1_NUMBER_ENEMIES;
	static float const WAVE1_PYLONS_TO_KILL;

	static float const WAVE2_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE2_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE2_BOSS_SPAWN_INTERVAL;
	static float const WAVE2_NUMBER_ENEMIES;
	static float const WAVE2_PYLONS_TO_KILL;

	static float const WAVE3_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE3_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE3_BOSS_SPAWN_INTERVAL;
	static float const WAVE3_NUMBER_ENEMIES;
	static float const WAVE3_PYLONS_TO_KILL;

	static float const WAVE4_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE4_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE4_BOSS_SPAWN_INTERVAL;
	static float const WAVE4_NUMBER_ENEMIES;
	static float const WAVE4_PYLONS_TO_KILL;

	static float const WAVE5_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE5_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE5_BOSS_SPAWN_INTERVAL;
	static float const WAVE5_NUMBER_ENEMIES;
	static float const WAVE5_PYLONS_TO_KILL;

	static float const WAVE6_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE6_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE6_BOSS_SPAWN_INTERVAL;
	static float const WAVE6_NUMBER_ENEMIES;
	static float const WAVE6_PYLONS_TO_KILL;

	static float const WAVE7_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE7_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE7_BOSS_SPAWN_INTERVAL;
	static float const WAVE7_NUMBER_ENEMIES;
	static float const WAVE7_PYLONS_TO_KILL;

	static float const WAVE8_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE8_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE8_BOSS_SPAWN_INTERVAL;
	static float const WAVE8_NUMBER_ENEMIES;
	static float const WAVE8_PYLONS_TO_KILL;

	static float const WAVE9_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE9_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE9_BOSS_SPAWN_INTERVAL;
	static float const WAVE9_NUMBER_ENEMIES;
	static float const WAVE9_PYLONS_TO_KILL;

	static float const WAVE10_ENEMY1_SPAWN_INTERVAL;
	static float const WAVE10_ENEMY2_SPAWN_INTERVAL;
	static float const WAVE10_BOSS_SPAWN_INTERVAL;
	static float const WAVE10_NUMBER_ENEMIES;
	static float const WAVE10_PYLONS_TO_KILL;
};

class ENEMY_STATS
{
public:
	static float const ENEMY1_RADIUS; // defined in GameConstants.cpp
	static float const ENEMY1_SPEED; // defined in GameConstants.cpp
	static float const ENEMY1_DAMAGE_PER_SECOND; // defined in GameConstants.cpp
	static float const ENEMY1_HEALTH; // defined in GameConstants.cpp
	static std::string const ENEMY1_ANIMATION_KEY; // defined in GameConstants.cpp

	static float const ENEMY2_RADIUS; // defined in GameConstants.cpp
	static float const ENEMY2_SPEED; // defined in GameConstants.cpp
	static float const ENEMY2_DAMAGE_PER_SECOND; // defined in GameConstants.cpp
	static float const ENEMY2_HEALTH; // defined in GameConstants.cpp
	static std::string const ENEMY2_ANIMATION_KEY; // defined in GameConstants.cpp

	static float const BOSS_RADIUS; // defined in GameConstants.cpp
	static float const BOSS_SPEED; // defined in GameConstants.cpp
	static float const BOSS_DAMAGE_PER_SECOND; // defined in GameConstants.cpp
	static float const BOSS_HEALTH; // defined in GameConstants.cpp
	static std::string const BOSS_ANIMATION_KEY; // defined in GameConstants.cpp
};

class GameConstants {
public:
	static sf::Font font;
	static sf::Font COOL_FONT;
	static float const EXPERENCE_AMOUNT;
	static int const CREDIT_AMOUNT;

	static int const CQB_UNIT_COST;
	static int const ASSAULT_UNIT_COST;
	static int const SNIPER_UNIT_COST;

	//radius in which players can walk about the centre of the map
	static float const TOWER_RADIUS; // defined in GameConstants.cpp	
	static float const TOWER_HEALTH; // defined in GameConstants.cpp
	static int const NUMBER_PYLONS; // defined in GameConstants.cpp

	static float const WALK_RADIUS; // defined in GameConstants.cpp	
	static float const PLAYER_RADIUS; // defined in GameConstants.cpp	
	static float const PLAYER_SPEED; // defined in GameConstants.cpp

	

	static float const BUNKER_SIZE_OUTER; // defined in GameConstants.cpp
	static float const BUNKER_SIZE_INNER; // defined in GameConstants.cpp
	static float const BUNKER_SIZE_WIDTH; // defined in GameConstants.cpp
	static float const BUNKER_SIZE_HEIGHT; // defined in GameConstants.cpp

	static float const BUNKER_HEALTH; // defined in GameConstants.cpp
	static float const GameConstants::BUNKER_REPAIR_COST;
	

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

	static float const AK1_DMG;// defined in GameConstants.cpp	
	static float const AK1_RANGE;// defined in GameConstants.cpp	
	static float const AK1_FOV;// defined in GameConstants.cpp	
	static float const AK1_FIRE_RATE;// defined in GameConstants.cpp

	static float const AK2_DMG;// defined in GameConstants.cpp	
	static float const AK2_RANGE;// defined in GameConstants.cpp	
	static float const AK2_FOV;// defined in GameConstants.cpp	
	static float const AK2_FIRE_RATE;// defined in GameConstants.cpp

	static float const AK3_DMG;// defined in GameConstants.cpp	
	static float const AK3_RANGE;// defined in GameConstants.cpp	
	static float const AK3_FOV;// defined in GameConstants.cpp	
	static float const AK3_FIRE_RATE;// defined in GameConstants.cpp



	//Plasma gun stuff
	static float const PLASMA_DMG;// defined in GameConstants.cpp	
	static float const PLASMA_RANGE;// defined in GameConstants.cpp	
	static float const PLASMA_FOV;// defined in GameConstants.cpp	
	static float const PLASMA_FIRE_RATE;// defined in GameConstants.cpp

	static float const PLASMA1_DMG;// defined in GameConstants.cpp	
	static float const PLASMA1_RANGE;// defined in GameConstants.cpp	
	static float const PLASMA1_FOV;// defined in GameConstants.cpp	
	static float const PLASMA1_FIRE_RATE;// defined in GameConstants.cpp

	static float const PLASMA2_DMG;// defined in GameConstants.cpp	
	static float const PLASMA2_RANGE;// defined in GameConstants.cpp	
	static float const PLASMA2_FOV;// defined in GameConstants.cpp	
	static float const PLASMA2_FIRE_RATE;// defined in GameConstants.cpp

	static float const PLASMA3_DMG;// defined in GameConstants.cpp	
	static float const PLASMA3_RANGE;// defined in GameConstants.cpp	
	static float const PLASMA3_FOV;// defined in GameConstants.cpp	
	static float const PLASMA3_FIRE_RATE;// defined in GameConstants.cpp

	//sniper
	static float const SNIPER_DMG;// defined in GameConstants.cpp	
	static float const SNIPER_RANGE;// defined in GameConstants.cpp	
	static float const SNIPER_FOV;// defined in GameConstants.cpp	
	static float const SNIPER_FIRE_RATE;// defined in GameConstants.cpp

	static float const SNIPER1_DMG;// defined in GameConstants.cpp	
	static float const SNIPER1_RANGE;// defined in GameConstants.cpp	
	static float const SNIPER1_FOV;// defined in GameConstants.cpp	
	static float const SNIPER1_FIRE_RATE;// defined in GameConstants.cpp

	static float const SNIPER2_DMG;// defined in GameConstants.cpp	
	static float const SNIPER2_RANGE;// defined in GameConstants.cpp	
	static float const SNIPER2_FOV;// defined in GameConstants.cpp	
	static float const SNIPER2_FIRE_RATE;// defined in GameConstants.cpp

	static float const SNIPER3_DMG;// defined in GameConstants.cpp	
	static float const SNIPER3_RANGE;// defined in GameConstants.cpp	
	static float const SNIPER3_FOV;// defined in GameConstants.cpp	
	static float const SNIPER3_FIRE_RATE;// defined in GameConstants.cpp

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

	static float const WEAPON_MAX_DMG;// defined in GameConstants.cpp	
	static float const WEAPON_MAX_RoF;// defined in GameConstants.cpp	
};

class BULLET_STATS
{
public:
	//Simple
	static float const SIMPLE_SPEED;// defined in GameConstants.cpp	
	static std::string const SIMPLE_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SIMPLE_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SIMPLE_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SIMPLE_COLOR;// defined in GameConstants.cpp
	static const std::string SIMPLE_AUDIO_NAME;// defined in GameConstants.cpp

	static float const SIMPLE1_SPEED;// defined in GameConstants.cpp	
	static std::string const SIMPLE1_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SIMPLE1_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SIMPLE1_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SIMPLE1_COLOR;// defined in GameConstants.cpp
	static const std::string SIMPLE1_AUDIO_NAME;// defined in GameConstants.cpp

	static float const SIMPLE2_SPEED;// defined in GameConstants.cpp	
	static std::string const SIMPLE2_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SIMPLE2_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SIMPLE2_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SIMPLE2_COLOR;// defined in GameConstants.cpp
	static const std::string SIMPLE2_AUDIO_NAME;// defined in GameConstants.cpp

	static float const SIMPLE3_SPEED;// defined in GameConstants.cpp	
	static std::string const SIMPLE3_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SIMPLE3_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SIMPLE3_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SIMPLE3_COLOR;// defined in GameConstants.cpp
	static const std::string SIMPLE3_AUDIO_NAME;// defined in GameConstants.cpp

	//PLASMA
	static float const PLASMA_SPEED;// defined in GameConstants.cpp	
	static std::string const PLASMA_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const PLASMA_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PLASMA_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PLASMA_COLOR;// defined in GameConstants.cpp
	static const std::string PLASMA_AUDIO_NAME;// defined in GameConstants.cpp

	static float const PLASMA1_SPEED;// defined in GameConstants.cpp	
	static std::string const PLASMA1_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const PLASMA1_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PLASMA1_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PLASMA1_COLOR;// defined in GameConstants.cpp
	static const std::string PLASMA1_AUDIO_NAME;// defined in GameConstants.cpp

	static float const PLASMA2_SPEED;// defined in GameConstants.cpp	
	static std::string const PLASMA2_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const PLASMA2_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PLASMA2_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PLASMA2_COLOR;// defined in GameConstants.cpp
	static const std::string PLASMA2_AUDIO_NAME;// defined in GameConstants.cpp

	static float const PLASMA3_SPEED;// defined in GameConstants.cpp	
	static std::string const PLASMA3_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const PLASMA3_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PLASMA3_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PLASMA3_COLOR;// defined in GameConstants.cpp
	static const std::string PLASMA3_AUDIO_NAME;// defined in GameConstants.cpp

	//sniper
	static float const SNIPER_SPEED;// defined in GameConstants.cpp	
	static std::string const SNIPER_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SNIPER_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SNIPER_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SNIPER_COLOR;// defined in GameConstants.cpp
	static const std::string SNIPER_AUDIO_NAME;// defined in GameConstants.cpp

	static float const SNIPER1_SPEED;// defined in GameConstants.cpp	
	static std::string const SNIPER1_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SNIPER1_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SNIPER1_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SNIPER1_COLOR;// defined in GameConstants.cpp
	static const std::string SNIPER1_AUDIO_NAME;// defined in GameConstants.cpp

	static float const SNIPER2_SPEED;// defined in GameConstants.cpp	
	static std::string const SNIPER2_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SNIPER2_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SNIPER2_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SNIPER2_COLOR;// defined in GameConstants.cpp
	static const std::string SNIPER2_AUDIO_NAME;// defined in GameConstants.cpp

	static float const SNIPER3_SPEED;// defined in GameConstants.cpp	
	static std::string const SNIPER3_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SNIPER3_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SNIPER3_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SNIPER3_COLOR;// defined in GameConstants.cpp
	static const std::string SNIPER3_AUDIO_NAME;// defined in GameConstants.cpp

	//lmg
	static float const LMG_SPEED;// defined in GameConstants.cpp	
	static std::string const LMG_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const LMG_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const LMG_RADIUS;// defined in GameConstants.cpp
	static const sf::Color LMG_COLOR;// defined in GameConstants.cpp
	static const std::string LMG_AUDIO_NAME;// defined in GameConstants.cpp

	//smg
	static float const SMG_SPEED;// defined in GameConstants.cpp	
	static std::string const SMG_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SMG_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SMG_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SMG_COLOR;// defined in GameConstants.cpp
	static const std::string SMG_AUDIO_NAME;// defined in GameConstants.cpp

	//pistol
	static float const PISTOL_SPEED;// defined in GameConstants.cpp	
	static std::string const PISTOL_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const PISTOL_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const PISTOL_RADIUS;// defined in GameConstants.cpp
	static const sf::Color PISTOL_COLOR;// defined in GameConstants.cpp
	static const std::string PISTOL_AUDIO_NAME;// defined in GameConstants.cpp

	//shotgun
	static float const SHOTGUN_SPEED;// defined in GameConstants.cpp	
	static std::string const SHOTGUN_ANIMATION_KEY;// defined in GameConstants.cpp	
	static float const SHOTGUN_ANIMATION_SPEED;// defined in GameConstants.cpp
	static float const SHOTGUN_RADIUS;// defined in GameConstants.cpp
	static const sf::Color SHOTGUN_COLOR;// defined in GameConstants.cpp
	static const std::string SHOTGUN_AUDIO_NAME;// defined in GameConstants.cpp


};
