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

bool Dead::isStatusChanged(int count) const
{
	return count == 3 ? true : false;
}

const char Dead::encode() const
{
	return ' ';
}
