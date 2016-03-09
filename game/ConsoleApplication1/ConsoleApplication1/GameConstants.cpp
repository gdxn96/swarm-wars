#include "stdafx.h"
#include "GameConstants.h"

//actual static variable values defined here
float const GameConstants::TOWER_RADIUS = 110;
float const GameConstants::TOWER_HEALTH = 1000;

float const GameConstants::PLAYER_RADIUS = 4;
float const GameConstants::WALK_RADIUS = GameConstants::TOWER_RADIUS + GameConstants::PLAYER_RADIUS + 25;
float const GameConstants::PLAYER_SPEED = 0.55f; // rads / second



float const GameConstants::PI = std::acos(-1);

int const GameConstants::NUMBER_PYLONS = 20;

float const GameConstants::POINTER_RADIUS = GameConstants::PLAYER_RADIUS + 1;
Vector2D const GameConstants::WINDOW_SIZE = Vector2D(1920, 1080);
Vector2D const GameConstants::WINDOW_CENTRE = Vector2D(GameConstants::WINDOW_SIZE.x / 2, GameConstants::WINDOW_SIZE.y / 2);


float const GameConstants::BUNKER_SIZE_WIDTH = GameConstants::PI / 8; //width in radians, defined by angle
float const GameConstants::BUNKER_SIZE_HEIGHT = 25; 
float const GameConstants::BUNKER_SIZE_INNER = GameConstants::WALK_RADIUS + GameConstants::PLAYER_RADIUS + 25;
float const GameConstants::BUNKER_SIZE_OUTER = GameConstants::BUNKER_SIZE_INNER + GameConstants::BUNKER_SIZE_HEIGHT;
float const GameConstants::BUNKER_HEALTH = 100;

float const GameConstants::BUNKER_REPAIR_COST = 1000;
int const GameConstants::CQB_UNIT_COST = 550;
int const GameConstants::ASSAULT_UNIT_COST = 700;
int const GameConstants::SNIPER_UNIT_COST = 450;

float const GameConstants::EXPERENCE_AMOUNT = 5;
int const GameConstants::CREDIT_AMOUNT = 10;





// weapon stuff
//AK Stuff
float const WeaponStats::AK_DMG = 50;
float const WeaponStats::AK_RANGE = 500;
float const WeaponStats::AK_FOV = GameConstants::PI / 12;
float const WeaponStats::AK_FIRE_RATE = 20;

float const WeaponStats::AK1_DMG = 25;
float const WeaponStats::AK1_RANGE = 430;
float const WeaponStats::AK1_FOV = GameConstants::PI / 12;
float const WeaponStats::AK1_FIRE_RATE = 17;

float const WeaponStats::AK2_DMG = 40;
float const WeaponStats::AK2_RANGE = 500;
float const WeaponStats::AK2_FOV = GameConstants::PI / 12;
float const WeaponStats::AK2_FIRE_RATE = 20;

float const WeaponStats::AK3_DMG = 60;
float const WeaponStats::AK3_RANGE = 530;
float const WeaponStats::AK3_FOV = GameConstants::PI / 12;
float const WeaponStats::AK3_FIRE_RATE = 25;

//Plasma gun stuff
float const WeaponStats::PLASMA_DMG = 90;
float const WeaponStats::PLASMA_RANGE = 300;
float const WeaponStats::PLASMA_FOV = GameConstants::PI / 8;
float const WeaponStats::PLASMA_FIRE_RATE = 15;

float const WeaponStats::PLASMA1_DMG = 50;
float const WeaponStats::PLASMA1_RANGE = 200;
float const WeaponStats::PLASMA1_FOV = GameConstants::PI / 8;
float const WeaponStats::PLASMA1_FIRE_RATE = 7;

float const WeaponStats::PLASMA2_DMG = 70;
float const WeaponStats::PLASMA2_RANGE = 300;
float const WeaponStats::PLASMA2_FOV = GameConstants::PI / 8;
float const WeaponStats::PLASMA2_FIRE_RATE = 12;

float const WeaponStats::PLASMA3_DMG = 95;
float const WeaponStats::PLASMA3_RANGE = 380;
float const WeaponStats::PLASMA3_FOV = GameConstants::PI / 8;
float const WeaponStats::PLASMA3_FIRE_RATE = 17;

//sniper
float const WeaponStats::SNIPER_DMG = 300;
float const WeaponStats::SNIPER_RANGE = 600;
float const WeaponStats::SNIPER_FOV = GameConstants::PI / 62;
float const WeaponStats::SNIPER_FIRE_RATE = 3;

float const WeaponStats::SNIPER1_DMG = 100;
float const WeaponStats::SNIPER1_RANGE = 300;
float const WeaponStats::SNIPER1_FOV = GameConstants::PI / 62;
float const WeaponStats::SNIPER1_FIRE_RATE = 1;

float const WeaponStats::SNIPER2_DMG = 200;
float const WeaponStats::SNIPER2_RANGE = 450;
float const WeaponStats::SNIPER2_FOV = GameConstants::PI / 62;
float const WeaponStats::SNIPER2_FIRE_RATE = 2;

float const WeaponStats::SNIPER3_DMG = 300;
float const WeaponStats::SNIPER3_RANGE = 600;
float const WeaponStats::SNIPER3_FOV = GameConstants::PI / 62;
float const WeaponStats::SNIPER3_FIRE_RATE = 4;

//shotgun
float const WeaponStats::SHOTGUN_DMG = 300;
float const WeaponStats::SHOTGUN_RANGE = 150;
float const WeaponStats::SHOTGUN_FOV = GameConstants::PI / 2;
float const WeaponStats::SHOTGUN_FIRE_RATE = 25;

//LMG
float const WeaponStats::LMG_DMG = 25;
float const WeaponStats::LMG_RANGE = 300;
float const WeaponStats::LMG_FOV = GameConstants::PI / 4;
float const WeaponStats::LMG_FIRE_RATE = 20;

//SMG
float const WeaponStats::SMG_DMG = 25;
float const WeaponStats::SMG_RANGE = 400;
float const WeaponStats::SMG_FOV = GameConstants::PI / 5;
float const WeaponStats::SMG_FIRE_RATE = 25;

//pistol
float const WeaponStats::PISTOL_DMG = 70;
float const WeaponStats::PISTOL_RANGE = 400;
float const WeaponStats::PISTOL_FOV = GameConstants::PI / 18;
float const WeaponStats::PISTOL_FIRE_RATE = 5;

float const WeaponStats::WEAPON_MAX_DMG = 300;
float const WeaponStats::WEAPON_MAX_RoF = 25;

//bullet stats
//Simple
float const BULLET_STATS::SIMPLE_SPEED = 250;// 	
std::string const BULLET_STATS::SIMPLE_ANIMATION_KEY = "bulletAnimation";// 	
float const BULLET_STATS::SIMPLE_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::SIMPLE_RADIUS = 10;// 
sf::Color const BULLET_STATS::SIMPLE_COLOR = sf::Color(255, 215, 0, 205);
const std::string BULLET_STATS::SIMPLE_AUDIO_NAME = "zum";

float const BULLET_STATS::SIMPLE1_SPEED = 250;// 	
std::string const BULLET_STATS::SIMPLE1_ANIMATION_KEY = "bulletAnimation";// 	
float const BULLET_STATS::SIMPLE1_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::SIMPLE1_RADIUS = 10;// 
sf::Color const BULLET_STATS::SIMPLE1_COLOR = sf::Color(255, 215, 0, 205);
const std::string BULLET_STATS::SIMPLE1_AUDIO_NAME = "zum";

float const BULLET_STATS::SIMPLE2_SPEED = 250;// 	
std::string const BULLET_STATS::SIMPLE2_ANIMATION_KEY = "bulletAnimation";// 	
float const BULLET_STATS::SIMPLE2_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::SIMPLE2_RADIUS = 10;// 
sf::Color const BULLET_STATS::SIMPLE2_COLOR = sf::Color(255, 215, 0, 205);
const std::string BULLET_STATS::SIMPLE2_AUDIO_NAME = "zum";

float const BULLET_STATS::SIMPLE3_SPEED = 250;// 	
std::string const BULLET_STATS::SIMPLE3_ANIMATION_KEY = "bulletAnimation";// 	
float const BULLET_STATS::SIMPLE3_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::SIMPLE3_RADIUS = 10;// 
sf::Color const BULLET_STATS::SIMPLE3_COLOR = sf::Color(255, 215, 0, 205);
const std::string BULLET_STATS::SIMPLE3_AUDIO_NAME = "zum";
				   
//PLASMA		   
float const BULLET_STATS::PLASMA_SPEED = 150;// 	
std::string const BULLET_STATS::PLASMA_ANIMATION_KEY = "plasmaAnimation";// 	
float const BULLET_STATS::PLASMA_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::PLASMA_RADIUS = 15;// 
sf::Color const BULLET_STATS::PLASMA_COLOR = sf::Color(238, 130, 238, 205);
const std::string BULLET_STATS::PLASMA_AUDIO_NAME = "plasma";

float const BULLET_STATS::PLASMA1_SPEED = 150;// 	
std::string const BULLET_STATS::PLASMA1_ANIMATION_KEY = "plasmaAnimation";// 	
float const BULLET_STATS::PLASMA1_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::PLASMA1_RADIUS = 15;// 
sf::Color const BULLET_STATS::PLASMA1_COLOR = sf::Color(238, 130, 238, 205);
const std::string BULLET_STATS::PLASMA1_AUDIO_NAME = "plasma";

float const BULLET_STATS::PLASMA2_SPEED = 150;// 	
std::string const BULLET_STATS::PLASMA2_ANIMATION_KEY = "plasmaAnimation";// 	
float const BULLET_STATS::PLASMA2_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::PLASMA2_RADIUS = 15;// 
sf::Color const BULLET_STATS::PLASMA2_COLOR = sf::Color(238, 130, 238, 205);
const std::string BULLET_STATS::PLASMA2_AUDIO_NAME = "plasma";

float const BULLET_STATS::PLASMA3_SPEED = 150;// 	
std::string const BULLET_STATS::PLASMA3_ANIMATION_KEY = "plasmaAnimation";// 	
float const BULLET_STATS::PLASMA3_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::PLASMA3_RADIUS = 15;// 
sf::Color const BULLET_STATS::PLASMA3_COLOR = sf::Color(238, 130, 238, 205);
const std::string BULLET_STATS::PLASMA3_AUDIO_NAME = "plasma";

//sniper
float const BULLET_STATS::SNIPER_SPEED = 450;
std::string const BULLET_STATS::SNIPER_ANIMATION_KEY = "plasmaAnimation";
float const BULLET_STATS::SNIPER_ANIMATION_SPEED = 20;
float const BULLET_STATS::SNIPER_RADIUS = 15;
const sf::Color BULLET_STATS::SNIPER_COLOR = sf::Color(255, 0, 0, 205);
const std::string BULLET_STATS::SNIPER_AUDIO_NAME = "sniper";

float const BULLET_STATS::SNIPER1_SPEED = 450;
std::string const BULLET_STATS::SNIPER1_ANIMATION_KEY = "plasmaAnimation";
float const BULLET_STATS::SNIPER1_ANIMATION_SPEED = 20;
float const BULLET_STATS::SNIPER1_RADIUS = 15;
const sf::Color BULLET_STATS::SNIPER1_COLOR = sf::Color(255, 0, 0, 205);
const std::string BULLET_STATS::SNIPER1_AUDIO_NAME = "sniper";

float const BULLET_STATS::SNIPER2_SPEED = 450;
std::string const BULLET_STATS::SNIPER2_ANIMATION_KEY = "plasmaAnimation";
float const BULLET_STATS::SNIPER2_ANIMATION_SPEED = 20;
float const BULLET_STATS::SNIPER2_RADIUS = 15;
const sf::Color BULLET_STATS::SNIPER2_COLOR = sf::Color(255, 0, 0, 205);
const std::string BULLET_STATS::SNIPER2_AUDIO_NAME = "sniper";

float const BULLET_STATS::SNIPER3_SPEED = 450;
std::string const BULLET_STATS::SNIPER3_ANIMATION_KEY = "plasmaAnimation";
float const BULLET_STATS::SNIPER3_ANIMATION_SPEED = 20;
float const BULLET_STATS::SNIPER3_RADIUS = 15;
const sf::Color BULLET_STATS::SNIPER3_COLOR = sf::Color(255, 0, 0, 205);
const std::string BULLET_STATS::SNIPER3_AUDIO_NAME = "sniper";

//lmg
float const BULLET_STATS::LMG_SPEED = 300;
std::string const BULLET_STATS::LMG_ANIMATION_KEY = "blueBulletAnimation";
float const BULLET_STATS::LMG_ANIMATION_SPEED = 20;
float const BULLET_STATS::LMG_RADIUS = 10;
const sf::Color BULLET_STATS::LMG_COLOR = sf::Color(0, 191, 255, 205);
const std::string BULLET_STATS::LMG_AUDIO_NAME = "zun";

//smg
float const BULLET_STATS::SMG_SPEED = 300;
std::string const BULLET_STATS::SMG_ANIMATION_KEY = "blueBulletAnimation";
float const BULLET_STATS::SMG_ANIMATION_SPEED = 20;
float const BULLET_STATS::SMG_RADIUS = 15;
const sf::Color BULLET_STATS::SMG_COLOR = sf::Color(0, 255, 0, 205);
const std::string BULLET_STATS::SMG_AUDIO_NAME = "zun";

//pistol
float const BULLET_STATS::PISTOL_SPEED = 350;
std::string const BULLET_STATS::PISTOL_ANIMATION_KEY = "blueBulletAnimation";
float const BULLET_STATS::PISTOL_ANIMATION_SPEED = 20;
float const BULLET_STATS::PISTOL_RADIUS = 15;
const sf::Color BULLET_STATS::PISTOL_COLOR = sf::Color(255, 255, 255, 205);
const std::string BULLET_STATS::PISTOL_AUDIO_NAME = "pistol";

//shotgun
float const BULLET_STATS::SHOTGUN_SPEED = 200;// defined in GameConstants.cpp	
std::string const BULLET_STATS::SHOTGUN_ANIMATION_KEY = "blueBulletAnimation";// defined in GameConstants.cpp	
float const BULLET_STATS::SHOTGUN_ANIMATION_SPEED = 20;// defined in GameConstants.cpp
float const BULLET_STATS::SHOTGUN_RADIUS = 15;// defined in GameConstants.cpp
const sf::Color BULLET_STATS::SHOTGUN_COLOR = sf::Color(13, 0, 255, 205);;// defined in GameConstants.cpp
const std::string BULLET_STATS::SHOTGUN_AUDIO_NAME = "zum";


//ENEMY_STATS
float const ENEMY_STATS::ENEMY1_RADIUS = 5;
float const ENEMY_STATS::ENEMY1_SPEED = 40;
float const ENEMY_STATS::ENEMY1_DAMAGE_PER_SECOND = 5;
float const ENEMY_STATS::ENEMY1_HEALTH = 100;
std::string const ENEMY_STATS::ENEMY1_ANIMATION_KEY = "bigBossAnimation";

float const ENEMY_STATS::ENEMY2_RADIUS = 10;
float const ENEMY_STATS::ENEMY2_SPEED = 30;
float const ENEMY_STATS::ENEMY2_DAMAGE_PER_SECOND = 2.5;
float const ENEMY_STATS::ENEMY2_HEALTH = 200;
std::string const ENEMY_STATS::ENEMY2_ANIMATION_KEY = "bugAnimation";

float const ENEMY_STATS::BOSS_RADIUS = 100;
float const ENEMY_STATS::BOSS_SPEED = 30;
float const ENEMY_STATS::BOSS_DAMAGE_PER_SECOND = 15;
float const ENEMY_STATS::BOSS_HEALTH = 5000;
std::string const ENEMY_STATS::BOSS_ANIMATION_KEY = "boss";


//WAVE_STATS
// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE1_ENEMY1_SPAWN_INTERVAL = 1 / 0.2f;
float const WAVE_CONSTANTS::WAVE1_ENEMY2_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE1_BOSS_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE1_NUMBER_ENEMIES = 20;
float const WAVE_CONSTANTS::WAVE1_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE2_ENEMY1_SPAWN_INTERVAL = 1.0f / 0.5f;
float const WAVE_CONSTANTS::WAVE2_ENEMY2_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE2_BOSS_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE2_NUMBER_ENEMIES = 30;
float const WAVE_CONSTANTS::WAVE2_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE3_ENEMY1_SPAWN_INTERVAL = 1.0f / 0.5f;
float const WAVE_CONSTANTS::WAVE3_ENEMY2_SPAWN_INTERVAL = 1.0f / 0.1f;
float const WAVE_CONSTANTS::WAVE3_BOSS_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE3_NUMBER_ENEMIES = 40;
float const WAVE_CONSTANTS::WAVE3_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE4_ENEMY1_SPAWN_INTERVAL = 1 / 0.3f;
float const WAVE_CONSTANTS::WAVE4_ENEMY2_SPAWN_INTERVAL = 1 / 0.4f;
float const WAVE_CONSTANTS::WAVE4_BOSS_SPAWN_INTERVAL = std::numeric_limits<float>::max();;
float const WAVE_CONSTANTS::WAVE4_NUMBER_ENEMIES = 50;
float const WAVE_CONSTANTS::WAVE4_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE5_ENEMY1_SPAWN_INTERVAL = 1.0f / 0.1f;
float const WAVE_CONSTANTS::WAVE5_ENEMY2_SPAWN_INTERVAL = 1.0f / 0.6f;
float const WAVE_CONSTANTS::WAVE5_BOSS_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE5_NUMBER_ENEMIES = 60;
float const WAVE_CONSTANTS::WAVE5_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE6_ENEMY1_SPAWN_INTERVAL = 1.0f / 0.7f;
float const WAVE_CONSTANTS::WAVE6_ENEMY2_SPAWN_INTERVAL = 1.0f / 0.7f;
float const WAVE_CONSTANTS::WAVE6_BOSS_SPAWN_INTERVAL = std::numeric_limits<float>::max();
float const WAVE_CONSTANTS::WAVE6_NUMBER_ENEMIES = 70;
float const WAVE_CONSTANTS::WAVE6_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE7_ENEMY1_SPAWN_INTERVAL = 1.0f / 0.1f;
float const WAVE_CONSTANTS::WAVE7_ENEMY2_SPAWN_INTERVAL = 1.0f / 0.1f;
float const WAVE_CONSTANTS::WAVE7_BOSS_SPAWN_INTERVAL = 1.0f / 0.5f;
float const WAVE_CONSTANTS::WAVE7_NUMBER_ENEMIES = 80;
float const WAVE_CONSTANTS::WAVE7_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE8_ENEMY1_SPAWN_INTERVAL = std::numeric_limits<float>::max();;
float const WAVE_CONSTANTS::WAVE8_ENEMY2_SPAWN_INTERVAL = std::numeric_limits<float>::max();;
float const WAVE_CONSTANTS::WAVE8_BOSS_SPAWN_INTERVAL = 1.0f / 0.5f;
float const WAVE_CONSTANTS::WAVE8_NUMBER_ENEMIES = 90;
float const WAVE_CONSTANTS::WAVE8_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE9_ENEMY1_SPAWN_INTERVAL = 1.0f / 0.1f;
float const WAVE_CONSTANTS::WAVE9_ENEMY2_SPAWN_INTERVAL = 1.0f / 0.1f;
float const WAVE_CONSTANTS::WAVE9_BOSS_SPAWN_INTERVAL = 1.0 / 0.7f;
float const WAVE_CONSTANTS::WAVE9_NUMBER_ENEMIES = 100;
float const WAVE_CONSTANTS::WAVE9_PYLONS_TO_KILL = 2;

// spawn interval = 1 / enemiesPerSecond (WATCH OUT FOR INTEGER DIVISION)
// if you want none of an enemy type to appear set it = std::numeric_limits<float>::max()
float const WAVE_CONSTANTS::WAVE10_ENEMY1_SPAWN_INTERVAL = 1;
float const WAVE_CONSTANTS::WAVE10_ENEMY2_SPAWN_INTERVAL = 1;
float const WAVE_CONSTANTS::WAVE10_BOSS_SPAWN_INTERVAL = 1;
float const WAVE_CONSTANTS::WAVE10_NUMBER_ENEMIES = 150;
float const WAVE_CONSTANTS::WAVE10_PYLONS_TO_KILL = 2;

sf::Font GameConstants::font = sf::Font();
sf::Font GameConstants::COOL_FONT = sf::Font();