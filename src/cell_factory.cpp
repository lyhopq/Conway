#include "cell_factory.h"
#include "alive.h"
#include "dead.h"

Cell* CellFactory::NewCell(int px, int py, char status)
{
	// return status == '1' ? new Alive(px, py) : new Dead(px, py);
	if('1' == status)
	{
		return new Alive(px, py);
	}

	return new Dead(px, py);
}
