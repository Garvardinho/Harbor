#pragma once
#include "Factory.h"

class Harbor : public Factory
{
public:
	Ship *createCivil() const override;
	Ship *createWarship() const override;
};