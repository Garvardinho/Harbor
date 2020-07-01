#include <iostream>
#include <string>
#include "Valid.h"
#include "Ship.h"

using namespace std;

void Ship::create()
{
	string tmp;

	do // Hereinafter - check for empty string
	{
		cout << "1. Ship type: ";
		getline(cin, type);
	} while (!str_valid(type));

	do
	{
		cout << "2. Ship class: ";
		getline(cin, ship_class);
	} while (!str_valid(ship_class));

	do
	{
		cout << "3. Specialty: ";
		getline(cin, type);
	} while (!str_valid(type));

	do
	{
		cout << "4. Size: ";
		getline(cin, type);
	} while (!str_valid(type));

	do
	{
		cout << "5. Area: ";
		getline(cin, type);
	} while (!str_valid(type));

	do
	{
		cout << "6. Power type: ";
		getline(cin, type);
	} while (!str_valid(type));

	while (true) // Check for correct input
	{
		cout << "7. Displacement: ";
		getline(cin, tmp);
		displacement = atoi(tmp.c_str());
		if (num_valid(tmp)) // If string-num check passed
			if (displacement > 0) // If data are reasonable
				break;
	}

	while (true)
	{
		cout << "8. Capacity: ";
		getline(cin, tmp);
		capacity = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (capacity > 0)
				break;
	}

	while (true)
	{
		cout << "9. Crew: ";
		getline(cin, tmp);
		crew = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (crew > 0)
				break;
	}

	while (true)
	{
		cout << "10. Passengers: ";
		getline(cin, tmp);
		passengers = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (passengers > 0)
				break;
	}

	while (true)
	{
		cout << "11. Speed: ";
		getline(cin, tmp);
		speed = atoi(tmp.c_str());
		if (num_valid(tmp))
			if (speed > 0)
				break;
	}
}