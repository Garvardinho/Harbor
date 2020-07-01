#pragma once
#include <iostream>

class Ship
{
protected:
	std::string type;
	std::string ship_class;
	std::string specialty;
	std::string size;
	std::string area;
	std::string power_type;
	int displacement;
	int capacity;
	int crew;
	int passengers;
	int speed;

public:
	void create();
	virtual ~Ship() {};
	virtual std::string note() const = 0;
};