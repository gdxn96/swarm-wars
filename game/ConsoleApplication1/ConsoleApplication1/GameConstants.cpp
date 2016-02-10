#include "stdafx.h"
#include "GameConstants.h"

//actual static variable values defined here

float const GameConstants::PLAYER_RADIUS = 5;
int const GameConstants::WALK_RADIUS = 150;
float const GameConstants::PLAYER_SPEED = 0.5f; // rads / second

float const GameConstants::PI = std::acos(-1); 

float const GameConstants::POINTER_RADIUS = 25;
Vector2D const GameConstants::WINDOW_SIZE = Vector2D(1300, 800);
Vector2D const GameConstants::WINDOW_CENTRE = Vector2D(GameConstants::WINDOW_SIZE.x / 2, GameConstants::WINDOW_SIZE.y / 2);


//AK Stuff
int const WeaponStats::AK_DMG = 10;
int const WeaponStats::AK_RANGE = 40;

//Plasma gun stuff
int const WeaponStats::PLASMA_DMG = 10;
int const WeaponStats::PLASMA_RANGE = 40;