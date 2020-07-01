#include "Warship.h"

Warship::Warship(int flag, Data *d)
{
	if (flag == 0)
		create(2);
	else
		set_data(*d);
}