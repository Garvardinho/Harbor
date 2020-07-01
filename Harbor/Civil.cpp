#include "Civil.h"

Civil::Civil(int flag, Data *d)
{
	if (flag == 0)
		create(1);
	else
		set_data(*d);
}