#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <list>
#include <string>
#include "Harbor.h"
#include "Ship.h"
#include "Valid.h"

using namespace std;

Harbor read_from_file(int);
void write_to_file(Harbor);
int main_menu();

bool str_cmp(Data d1, Data d2)
{
	return d1.type > d2.type;
}

int main()
{
	int menu = 1; // To avoid 'while' condition below
	int ship_type;
	int num;
	string tmp;
	Harbor h;

	while (menu)
	{
		system("cls");
		menu = main_menu();

		switch (menu)
		{
		case 1:
			system("cls");
			cout << "How much ships do you want to add?\n";

			while (true) // Check for correct input
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp)) // If string-num check passed
					if (num > 0) // If data are reasonable
						break;
			}

			for (int i = 0; i < num; i++)
			{
				system("cls");
				cout << "1. Civil\n"
					<< "2. Warship\n";

				while (true)
				{
					cout << "> ";
					getline(cin, tmp);
					ship_type = atoi(tmp.c_str());
					if (num_valid(tmp))
						if (ship_type == 1 || ship_type == 2)
							break;
				}

				if (ship_type == 1)
					h.create_civil();
				else
					h.create_warship();
			}
			break;

		case 2:
			h.show();
			getchar();
			break;

		case 3:
			system("cls");
			cout << "How much ships do you want to read from file?\n";

			while (true)
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}

			h = read_from_file(num);
			break;
		}
	}

	write_to_file(h);
	return 0;
}

int main_menu()
{
	int menu;
	string tmp;

	cout << "1. Add ship to harbor\n"
		<< "2. Show harbor\n"
		<< "3. Load ships from the file\n"
		<< "0. Exit\n";

	while (true) // Check for correct input
	{
		cout << "> ";
		getline(cin, tmp);
		menu = atoi(tmp.c_str());
		if (num_valid(tmp)) // If string-num check passed
			if (menu >= 0 && menu <= 3) // If data are reasonable
				break;
	}

	return menu;
}

Harbor read_from_file(int num)
{
	ifstream in;
	Harbor h;
	Data data;
	string tmp;
	int flag = 1;
	int pos;

	try
	{
		in.open("Harbor.txt", ios::in);
		if (!in.is_open())
			throw exception("File can not be opened!\n");

		if (in.peek() == EOF)
			throw exception("File is empty!\n");

		while (in.peek() != EOF && num != 0) // Read data from file
		{
			getline(in, tmp);
			if (tmp.empty())
				continue;

			cout << tmp << endl;

			switch (flag)
			{
			case 1:
				if (pos = tmp.find("Ship type: ") != 0)
					throw exception("There is an error in file\n");

				data.type = tmp.substr(11);
				if (data.type != "Warship" && data.type != "Civil")
					throw exception("There is a ship type error in file");
				break;

			case 2:
				if (pos = tmp.find("Ship class: ") != 0)
					throw exception("There is an error in file\n");

				data.ship_class = tmp.substr(12);
				break;

			case 3:
				if (pos = tmp.find("Specialty: ") != 0)
					throw exception("There is an error in file\n");

				data.specialty = tmp.substr(11);
				break;

			case 4:
				if (pos = tmp.find("Size: ") != 0)
					throw exception("There is an error in file\n");

				data.size = tmp.substr(6);
				break;

			case 5:
				if (pos = tmp.find("Area: ") != 0)
					throw exception("There is an error in file\n");

				data.area = tmp.substr(6);
				break;

			case 6:
				if (pos = tmp.find("Power type: ") != 0)
					throw exception("There is an error in file\n");

				data.power_type = tmp.substr(12);
				break;

			case 7:
				if (pos = tmp.find("Displacement: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(14);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				data.displacement = atoi(tmp.c_str()); // Convert string to integer
				if (data.displacement < 0)
					throw exception("There is a displacement error in file\n");
				break;

			case 8:
				if (pos = tmp.find("Capacity: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(10);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				data.capacity = atoi(tmp.c_str());
				if (data.capacity < 0)
					throw exception("There is a capacity error in file\n");
				break;

			case 9:
				if (pos = tmp.find("Crew: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(6);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				data.crew = atoi(tmp.c_str());
				if (data.crew < 0)
					throw exception("There is a crew error in file\n");
				break;

			case 10:
				if (pos = tmp.find("Passengers: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(12);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				data.passengers = atoi(tmp.c_str());
				if (data.passengers < 0)
					throw exception("There is a passengers error in file\n");
				break;

			case 11:
				if (pos = tmp.find("Speed: ") != 0)
					throw exception("There is an error in file\n");

				tmp = tmp.substr(7);
				if (!num_valid(tmp))
					throw exception("There is an error in file\n");

				data.speed = atoi(tmp.c_str());
				if (data.speed < 0)
					throw exception("There is a speed error in file\n");
				break;

			}

			if (flag == 11)
			{
				cout << endl;
				flag = 0; // Zero because of increment below
				h.setData(data);
				num--;
			}

			flag++;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		getchar();
	}

	in.close();

	return h;
}

void write_to_file(Harbor h)
{
	ofstream out;
	Data d;
	list<Ship *> l = h.get_ships();

	l.sort([](const Ship *s1, const Ship *s2) 
	{
		return s1->get_data().type < s2->get_data().type;
	});

	try
	{
		out.open("Harbor.txt", ios_base::app);
		if (!out.is_open())
			throw exception("File can not be opened!");

		for (auto el : l)
		{
			d = el->get_data();
			out << "Ship type: " << d.type << "\nShip class: " << d.ship_class << "\nSpecialty: "
				<< d.specialty << "\nSize: " << d.size << "\nArea: " << d.area << "\nPower type: " 
				<< d.power_type << "\nDisplacement: " << d.displacement << "\nCapacity: " << d.capacity << "\nCrew: " 
				<< d.crew << "\nPassengers: " << d.passengers << "\nSpeed: " << d.speed << endl << endl;
		}
		out.close();
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}
}