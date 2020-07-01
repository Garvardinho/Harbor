#pragma once
#include "Ship.h"

class Harbor
{
public:
	virtual Ship *createCivil() const = 0;
	virtual Ship *createWarship() const = 0;
};