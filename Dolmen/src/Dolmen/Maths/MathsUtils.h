#pragma once

#define _USE_MATH_DEFINES

#include <math.h>

namespace Dolmen
{
	inline float DegreesToRadians(float degrees)
	{
		return (float)(degrees * (M_PI / 180.0F));
	}
}