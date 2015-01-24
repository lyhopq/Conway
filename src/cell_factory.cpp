#include "cell_factory.h"
#include "alive.h"
#include "dead.h"

const Cell* CellFactory::NewCell(int px, int py, bool isAlive)
{
	if(isAlive)
	{
		return new Alive(px, py);
	}

	return new Dead(px, py);
}

const Cell* CellFactory::changeCell(const Cell *cell)
{
	return NewCell(cell->px, cell->py, !cell->isAlive());
}
