#pragma once
#include "Harbor.h"

class Factory : public Harbor
{
public:
	Ship *createCivil() const override;
	Ship *createWarship() const override;
};