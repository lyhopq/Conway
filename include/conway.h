#ifndef CONWAY
#define CONWAY

#include <iostream>
#include <vector>

class Cell;

using namespace std;

#define VECTOR std::vector<const Cell*>

class Conway
{
public:
    ~Conway();

	void getSeed(ifstream& data);
    void propagate();
	bool step();
	string dump() const;

private:
	VECTOR cells;
	int row;
	int column;

	bool isAlive(const char& c) const;
	VECTOR neighbours(const Cell* cell) const;
	int countAliveNeighbours(const Cell *cell) const;
    VECTOR getChangedCells() const;
	void update(VECTOR& changed);
	bool isStabilized(VECTOR& changed) const;

    int index(const Cell* cell) const;
    int index(int r, int c) const;
};

#endif
