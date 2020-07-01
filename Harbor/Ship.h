#pragma once
#include <iostream>

struct Data
{
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
};

class Ship
{
protected:
	Data data;
public:
	virtual ~Ship() {};
	void create(int flag);
	void set_data(struct Data); // Set data from file
	Data get_data() const;
};