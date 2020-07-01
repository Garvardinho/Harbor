#pragma once
#include "Ship.h"

class Warship : public Ship
{
public:
	std::string note() const override;
};