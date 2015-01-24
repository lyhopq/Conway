#include "alive.h"

Alive::Alive(int px, int py)
	:Cell(px, py)
{
}

Alive::~Alive()
{
}

bool Alive::isAlive() const
{
	return true;
}

bool Alive::isStatusChanged(int count) const
{
	return count !=2 && count !=3;
}

char Alive::encode() const
{
	return '$';
}

int Alive::present() const
{
	return 1;
}