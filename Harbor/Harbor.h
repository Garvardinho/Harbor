#pragma once
#include <list>
#include "Factory.h"

class Harbor : public Factory
{
private:
	std::list<Ship*> ships;
public:
	void create_civil() override;
	void create_warship() override;
	void setData(Data);
	void show();
	std::list<Ship*> get_ships();
};