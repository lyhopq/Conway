#include "alive.h"

Alive::Alive(int px, int py)
	:Cell(px, py)
{
}

Alive::~Alive()
{
}

const char Alive::show() const
{
	return '$';
}