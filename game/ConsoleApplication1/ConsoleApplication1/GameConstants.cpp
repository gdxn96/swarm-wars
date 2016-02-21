#include "stdafx.h"
#include "GameConstants.h"

//actual static variable values defined here
float const GameConstants::TOWER_RADIUS = 110;
float const GameConstants::TOWER_HEALTH = 10000;
float const GameConstants::PLAYER_RADIUS = 4;
float const GameConstants::WALK_RADIUS = GameConstants::TOWER_RADIUS + GameConstants::PLAYER_RADIUS + 25;
float const GameConstants::PLAYER_SPEED = 0.55f; // rads / second

float const GameConstants::EXPERENCE_AMOUNT = 10;
int const GameConstants::CREDIT_AMOUNT = 10;

float const GameConstants::PI = std::acos(-1);

float const GameConstants::ENEMY1_RADIUS = 18; 
float const GameConstants::ENEMY1_SPEED = 50; 
float const GameConstants::ENEMY1_DAMAGE_PER_SECOND = 5; 
float const GameConstants::ENEMY1_HEALTH = 100; 

float const GameConstants::ENEMY2_RADIUS = 10; 
float const GameConstants::ENEMY2_SPEED = 30; 
float const GameConstants::ENEMY2_DAMAGE_PER_SECOND = 2.5; 
float const GameConstants::ENEMY2_HEALTH = 200; 

 float const GameConstants::BOSS_RADIUS = 100; 
 float const GameConstants::BOSS_SPEED = 50; 
 float const GameConstants::BOSS_DAMAGE_PER_SECOND = 100; 
 float const GameConstants::BOSS_HEALTH = 5000; 

float enemiesPerSecond = 1.5f;

float const GameConstants::ENEMY_SPAWN_INTERVAL = 1.0f / enemiesPerSecond; 

float const GameConstants::POINTER_RADIUS = GameConstants::PLAYER_RADIUS + 1;
Vector2D const GameConstants::WINDOW_SIZE = Vector2D(1600, 900);
Vector2D const GameConstants::WINDOW_CENTRE = Vector2D(GameConstants::WINDOW_SIZE.x / 2, GameConstants::WINDOW_SIZE.y / 2);


float const GameConstants::BUNKER_SIZE_WIDTH = GameConstants::PI / 8; //width in radians, defined by angle
float const GameConstants::BUNKER_SIZE_HEIGHT = 25; 
float const GameConstants::BUNKER_SIZE_INNER = GameConstants::WALK_RADIUS + GameConstants::PLAYER_RADIUS + 25;
float const GameConstants::BUNKER_SIZE_OUTER = GameConstants::BUNKER_SIZE_INNER + GameConstants::BUNKER_SIZE_HEIGHT;
float const GameConstants::BUNKER_HEALTH = 100;


// weapon stuff

//AK Stuff
float const WeaponStats::AK_DMG = 50;
float const WeaponStats::AK_RANGE = 500;
float const WeaponStats::AK_FOV = GameConstants::PI / 10;
float const WeaponStats::AK_FIRE_RATE = 20;



//Plasma gun stuff
float const WeaponStats::PLASMA_DMG = 90;
float const WeaponStats::PLASMA_RANGE = 300;
float const WeaponStats::PLASMA_FOV = GameConstants::PI / 8;
float const WeaponStats::PLASMA_FIRE_RATE = 15;

//sniper
float const WeaponStats::SNIPER_DMG = 300;
float const WeaponStats::SNIPER_RANGE = 600;
float const WeaponStats::SNIPER_FOV = GameConstants::PI / 62;
float const WeaponStats::SNIPER_FIRE_RATE = 3;

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

//Simple
float const BULLET_STATS::SIMPLE_SPEED = 250;// 	
std::string const BULLET_STATS::SIMPLE_TEXTURE_KEY = "bulletAnimation";// 	
float const BULLET_STATS::SIMPLE_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::SIMPLE_RADIUS = 10;// 
sf::Color const BULLET_STATS::SIMPLE_COLOR = sf::Color(255, 215, 0, 205);
const std::string BULLET_STATS::SIMPLE_AUDIO_NAME = "zum";
				   
//PLASMA		   
float const BULLET_STATS::PLASMA_SPEED = 150;// 	
std::string const BULLET_STATS::PLASMA_TEXTURE_KEY = "plasmaAnimation";// 	
float const BULLET_STATS::PLASMA_ANIMATION_SPEED = 20;// 
float const BULLET_STATS::PLASMA_RADIUS = 15;// 
sf::Color const BULLET_STATS::PLASMA_COLOR = sf::Color(238, 130, 238, 205);
const std::string BULLET_STATS::PLASMA_AUDIO_NAME = "plasma";

//sniper
float const BULLET_STATS::SNIPER_SPEED = 450;
std::string const BULLET_STATS::SNIPER_TEXTURE_KEY = "plasmaAnimation";
float const BULLET_STATS::SNIPER_ANIMATION_SPEED = 20;
float const BULLET_STATS::SNIPER_RADIUS = 15;
const sf::Color BULLET_STATS::SNIPER_COLOR = sf::Color(255, 0, 0, 205);
const std::string BULLET_STATS::SNIPER_AUDIO_NAME = "sniper";

//lmg
float const BULLET_STATS::LMG_SPEED = 300;
std::string const BULLET_STATS::LMG_TEXTURE_KEY = "blueBulletAnimation";
float const BULLET_STATS::LMG_ANIMATION_SPEED = 20;
float const BULLET_STATS::LMG_RADIUS = 10;
const sf::Color BULLET_STATS::LMG_COLOR = sf::Color(0, 191, 255, 205);
const std::string BULLET_STATS::LMG_AUDIO_NAME = "zun";

//smg
float const BULLET_STATS::SMG_SPEED = 300;
std::string const BULLET_STATS::SMG_TEXTURE_KEY = "blueBulletAnimation";
float const BULLET_STATS::SMG_ANIMATION_SPEED = 20;
float const BULLET_STATS::SMG_RADIUS = 15;
const sf::Color BULLET_STATS::SMG_COLOR = sf::Color(0, 255, 0, 205);
const std::string BULLET_STATS::SMG_AUDIO_NAME = "zun";

//pistol
float const BULLET_STATS::PISTOL_SPEED = 350;
std::string const BULLET_STATS::PISTOL_TEXTURE_KEY = "blueBulletAnimation";
float const BULLET_STATS::PISTOL_ANIMATION_SPEED = 20;
float const BULLET_STATS::PISTOL_RADIUS = 15;
const sf::Color BULLET_STATS::PISTOL_COLOR = sf::Color(255, 255, 255, 205);
const std::string BULLET_STATS::PISTOL_AUDIO_NAME = "pistol";

//shotgun
float const BULLET_STATS::SHOTGUN_SPEED = 200;// defined in GameConstants.cpp	
std::string const BULLET_STATS::SHOTGUN_TEXTURE_KEY = "blueBulletAnimation";// defined in GameConstants.cpp	
float const BULLET_STATS::SHOTGUN_ANIMATION_SPEED = 20;// defined in GameConstants.cpp
float const BULLET_STATS::SHOTGUN_RADIUS = 15;// defined in GameConstants.cpp
const sf::Color BULLET_STATS::SHOTGUN_COLOR = sf::Color(13, 0, 255, 205);;// defined in GameConstants.cpp
const std::string BULLET_STATS::SHOTGUN_AUDIO_NAME = "zum";



sf::Font GameConstants::font = sf::Font();