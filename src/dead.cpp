#include "dead.h"

Dead::Dead(int px, int py)
	:Cell(px, py)
{
}

Dead::~Dead()
{
}

const char Dead::show() const
{
	return ' ';
}