#ifndef CELL_FACTORY
#define CELL_FACTORY 

#include "cell.h"

class CellFactory
{
public:
	Cell* NewCell(int px, int py, char status);
};
#endif
