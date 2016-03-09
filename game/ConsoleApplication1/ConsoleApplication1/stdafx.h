// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <iomanip>

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
	std::ostringstream out;
	out << std::setprecision(n) << a_value;
	return out.str();
}

template <class T>
std::string numberToString(const T& t) {

	std::stringstream ss;
	ss << t;

	return ss.str();

}

float RandomFloat(float min, float max);

// TODO: reference additional headers your program requires here
