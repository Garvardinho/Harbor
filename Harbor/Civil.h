#pragma once
#include "Ship.h"

class Civil : public Ship
{
public:
	Civil();
	std::string note() const override;
};