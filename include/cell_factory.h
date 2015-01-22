#ifndef CELL_FACTORY
#define CELL_FACTORY

#include "cell.h"

class CellFactory
{
public:
	const Cell* NewCell(int px, int py, char status);
	const Cell* changeCell(const Cell* cell);
};
#endif
