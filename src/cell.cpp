#include "cell.h"

Cell::Cell(int _px, int _py)
	:px(_px), py(_py)
{
}

Cell::~Cell()
{
}

int Cell::index() const
{
	return px * py;
}