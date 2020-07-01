#include "Harbor.h"
#include "Civil.h"
#include "Warship.h"

Ship *Harbor::createCivil() const
{
	return new Civil();
}

Ship *Harbor::createWarship() const
{
	return new Warship();
}