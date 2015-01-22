#ifndef CONWAY
#define CONWAY

#include <vector>

class ifstrame;
class Cell;

class Conway
{
public:
	void getSeed();
	void step();

	void dump() const;

private:
	std::vector<Cell*> cells;
	int row;
	int column;

	std::vector<Cell*> neighbours(Cell* cell) const;
	int countAliveNeighbours(Cell *cell) const;
	void update(std::vector<Cell*>& changed);

    int index(Cell* cell) const;
    int index(int r, int c) const;
};

#endif
