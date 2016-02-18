#include "stdafx.h"
#include "GameConstants.h"

//actual static variable values defined here

float const GameConstants::TOWER_RADIUS = 80;
float const GameConstants::TOWER_HEALTH = 100;
float const GameConstants::PLAYER_RADIUS = 4;
float const GameConstants::WALK_RADIUS = GameConstants::TOWER_RADIUS + GameConstants::PLAYER_RADIUS + 15;
float const GameConstants::PLAYER_SPEED = 0.15f; // rads / second


float const GameConstants::PI = std::acos(-1);

float const GameConstants::ENEMY1_RADIUS = 5; 
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

float enemiesPerSecond = 0.5f;
float const GameConstants::ENEMY_SPAWN_INTERVAL = 1.0f / enemiesPerSecond; 

float const GameConstants::POINTER_RADIUS = GameConstants::PLAYER_RADIUS + 1;
Vector2D const GameConstants::WINDOW_SIZE = Vector2D(1100, 900);
Vector2D const GameConstants::WINDOW_CENTRE = Vector2D(GameConstants::WINDOW_SIZE.x / 2, GameConstants::WINDOW_SIZE.y / 2);


float const GameConstants::BUNKER_SIZE_WIDTH = GameConstants::PI / 8; //width in radians, defined by angle
float const GameConstants::BUNKER_SIZE_HEIGHT = 10; 
float const GameConstants::BUNKER_SIZE_INNER = GameConstants::WALK_RADIUS + GameConstants::PLAYER_RADIUS + 15;
float const GameConstants::BUNKER_SIZE_OUTER = GameConstants::BUNKER_SIZE_INNER + GameConstants::BUNKER_SIZE_HEIGHT;
float const GameConstants::BUNKER_HEALTH = 100;


// weapon stuff

//AK Stuff
float const WeaponStats::AK_DMG = 300;
float const WeaponStats::AK_RANGE = 500;
float const WeaponStats::AK_FOV = GameConstants::PI / 4;
float const WeaponStats::AK_FIRE_RATE = 50;


//Plasma gun stuff
float const WeaponStats::PLASMA_DMG = 300;
float const WeaponStats::PLASMA_RANGE = 300;
float const WeaponStats::PLASMA_FOV = GameConstants::PI / 4;
float const WeaponStats::PLASMA_FIRE_RATE = 20;

//sniper
float const WeaponStats::SNIPER_DMG = 300;
float const WeaponStats::SNIPER_RANGE = 300;
float const WeaponStats::SNIPER_FOV = GameConstants::PI / 4;
float const WeaponStats::SNIPER_FIRE_RATE = 20;

//shotgun
float const WeaponStats::SHOTGUN_DMG = 300;
float const WeaponStats::SHOTGUN_RANGE = 300;
float const WeaponStats::SHOTGUN_FOV = GameConstants::PI / 4;
float const WeaponStats::SHOTGUN_FIRE_RATE = 20;

//LMG
float const WeaponStats::LMG_DMG = 300;
float const WeaponStats::LMG_RANGE = 300;
float const WeaponStats::LMG_FOV = GameConstants::PI / 4;
float const WeaponStats::LMG_FIRE_RATE = 20;

//SMG
float const WeaponStats::SMG_DMG = 300;
float const WeaponStats::SMG_RANGE = 300;
float const WeaponStats::SMG_FOV = GameConstants::PI / 4;
float const WeaponStats::SMG_FIRE_RATE = 20;

//pistol
float const WeaponStats::PISTOL_DMG = 300;
float const WeaponStats::PISTOL_RANGE = 300;
float const WeaponStats::PISTOL_FOV = GameConstants::PI / 4;
float const WeaponStats::PISTOL_FIRE_RATE = 20;