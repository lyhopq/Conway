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
	return count == 3;
}

char Dead::encode() const
{
	return ' ';
}

int Dead::present() const
{
	return 0;
}
