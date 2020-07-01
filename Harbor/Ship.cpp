#include <iostream>
#include <string>
#include "Valid.h"
#include "Ship.h"

using namespace std;

void Ship::create(int flag)
{
	string tmp;

	cout << "1. Ship type: ";
	if (flag == 1)
	{
		data.type = "Civil";
		cout << "Civil\n";
	}
	else
	{
		data.type = "Warship";
		cout << "Warship\n";
	}

	do
	{
		cout << "2. Ship class: ";
		getline(cin, data.ship_class);
	} while (!str_valid(data.ship_class));

	do
	{
		cout << "3. Specialty: ";
		getline(cin, data.specialty);
	} while (!str_valid(data.specialty));

	do
	{
		cout << "4. Size: ";
		getline(cin, data.size);
	} while (!str_valid(data.size));

	do
	{
		cout << "5. Area: ";
		getline(cin, data.area);
	} while (!str_valid(data.area));

	do
	{
		cout << "6. Power type: ";
		getline(cin, data.power_type);
	} while (!str_valid(data.power_type));

	while (true) // Check for correct input
	{
		cout << "7. Displacement: ";
		getline(cin, tmp);
		data.displacement = atoi(tmp.c_str());
		if (num_valid(tmp)) // If string-num check passed
			if (data.displacement > 0) // If data are reasonable
				break;
	}

	while (true)
	{
		cout << "8. Capacity: ";
		getline(cin, tmp);
		data.capacity = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.capacity > 0)
				break;
	}

	while (true)
	{
		cout << "9. Crew: ";
		getline(cin, tmp);
		data.crew = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.crew > 0)
				break;
	}

	while (true)
	{
		cout << "10. Passengers: ";
		getline(cin, tmp);
		data.passengers = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.passengers > 0)
				break;
	}

	while (true)
	{
		cout << "11. Speed: ";
		getline(cin, tmp);
		data.speed = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (data.speed > 0)
				break;
	}
}

void Ship::set_data(Data d)
{
	data.area = d.area;
	data.capacity = d.capacity;
	data.crew = d.crew;
	data.displacement = d.displacement;
	data.passengers = d.passengers;
	data.power_type = d.power_type;
	data.ship_class = d.ship_class;
	data.size = d.size;
	data.specialty = d.specialty;
	data.speed = d.speed;
	data.type = d.type;
}

Data Ship::get_data() const
{
	return data;
}