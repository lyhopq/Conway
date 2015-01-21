#include "dead.h"

Dead::Dead(int px, int py)
	:Cell(px, py)
{
}

Dead::~Dead()
{
}

bool Dead::isAlive() const
{
	return false;
}

const char Dead::show() const
{
	return ' ';
}