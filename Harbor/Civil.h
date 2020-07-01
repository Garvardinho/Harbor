#pragma once
#include "Ship.h"

class Civil : public Ship
{
public:
	std::string note() const override;
};