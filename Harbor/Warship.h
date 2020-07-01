#pragma once
#include "Ship.h"

class Warship : public Ship
{
public:
	Warship();
	std::string note() const override;
};