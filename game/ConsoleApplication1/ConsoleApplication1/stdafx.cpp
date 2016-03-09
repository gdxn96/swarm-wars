// stdafx.cpp : source file that includes just the standard includes
// ConsoleApplication1.pch will be the pre-compiled header
// stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"

float RandomFloat(float min, float max)
{
	// this  function assumes max > min
	float random = ((float)rand()) / (float)RAND_MAX;

	float range = max - min;
	return (random*range) + min;
}

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file
