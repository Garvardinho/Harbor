#pragma once
#include "Ship.h"

class Factory
{
public:
	virtual void create_civil() = 0;
	virtual void create_warship() = 0;
};