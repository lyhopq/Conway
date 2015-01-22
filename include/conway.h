#ifndef CONWAY
#define CONWAY

#include <vector>

class ifstrame;
class Cell;

#define VECTOR std::vector<const Cell*>

class Conway
{
public:
    ~Conway();

	void getSeed();
	void step();
	void dump() const;

private:
	VECTOR cells;
	int row;
	int column;

	VECTOR neighbours(const Cell* cell) const;
	int countAliveNeighbours(const Cell *cell) const;
    VECTOR getChangedCells() const;
	void update(VECTOR& changed);

    int index(const Cell* cell) const;
    int index(int r, int c) const;
};

#endif
