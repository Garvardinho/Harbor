#include <iostream>
#include <string>
#include "Harbor.h"
#include "Civil.h"
#include "Warship.h"

void Harbor::create_civil()
{
	ships.push_back(new Civil(0));
}

void Harbor::create_warship()
{
	ships.push_back(new Warship(0));
}

void Harbor::setData(Data d)
{
	ships.push_back(new Civil(1, &d));
}

void Harbor::show()
{
	Data d;

	for (auto el : ships)
	{
		d = el->get_data();

		std::cout << "Ship type: " << d.type << "\nShip class: " << d.ship_class << "\nSpecialty: "
			<< d.specialty << "\nSize: " << d.size << "\nArea: " << d.area << "\nPower type: "
			<< d.power_type << "\nDisplacement: " << d.displacement << "\nCapacity: " << d.capacity << "\nCrew: "
			<< d.crew << "\nPassengers: " << d.passengers << "\nSpeed: " << d.speed << std::endl << std::endl;
	}
}

std::list<Ship *> Harbor::get_ships()
{
	return ships;
}