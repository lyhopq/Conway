#include "cell_factory.h"
#include "alive.h"
#include "dead.h"

const Cell* CellFactory::NewCell(int px, int py, char status)
{
	if('1' == status)
	{
		return new Alive(px, py);
	}

	return new Dead(px, py);
}

const Cell* CellFactory::changeCell(const Cell *cell)
{
	Cell *newCell;
	if(cell->isAlive())
	{
		newCell = new Dead(cell->px, cell->py);
	}
	else
	{
		newCell = new Alive(cell->px, cell->py);
	}

	return newCell;
}
