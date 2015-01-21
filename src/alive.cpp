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

const char Alive::show() const
{
	return '$';
}