#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 


namespace Constants
{
	//GLOBAL VARIABLES (FOR TESTING PURPOSES)
	extern const sf::Vector2f CENTRE(640, 360);
	extern const int ARC_RADIUS = 200;
	extern const float PI = std::acos(-1);
	extern const int MAX_CHAR = 3;

	extern enum soldier_type_t
	{
		sergeant,
		soldier
	};
}


#endif