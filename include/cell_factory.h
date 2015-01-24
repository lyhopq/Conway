#ifndef CELL_FACTORY
#define CELL_FACTORY

#include "cell.h"

class CellFactory
{
public:
	const Cell* NewCell(int px, int py, bool isAlive);
	const Cell* changeCell(const Cell* cell);
};
#endif
