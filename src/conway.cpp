#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

#include "conway.h"
#include "cell_factory.h"

using namespace std;

const char *initalData = "initalData.txt";
const char *output = "final.txt";

#define ITER VECTOR::const_iterator

void Conway::getSeed()
{
	CellFactory factory;
	int r = 0;
	int c = 0;
    ifstream fs(initalData);

	for(string line; getline(fs, line);)
	{
		for(c = 0; c < line.length(); c++)
		{
			cells.push_back(factory.NewCell(r, c, line[c]));
		}
		r++;
	}

	row = r;
	column = c;
}

void Conway::step()
{
    while(1)
    {
        VECTOR changedCells = getChangedCells();
        if(changedCells.size() == 0) break;
        update(changedCells);
    }
}

void Conway::dump() const
{
    ofstream fs(output);
	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < column; c++)
		{
			fs << cells[index(r, c)]->show();
		}
		fs << endl;
	}

	fs.close();
}

VECTOR Conway::neighbours(const Cell *cell) const
{
	VECTOR neighs;
	for(int r = cell->px - 1; r <= cell->px + 1; r++)
	{
		for(int c = cell->py - 1; c <= cell->py + 1; c++)
		{
			if(r == cell->px && c == cell->py) continue;
			if(r < 0 || r >= row || c < 0 || c >= column) continue;

			neighs.push_back(cells[index(r, c)]);
		}
	}

	return neighs;
}

int Conway::countAliveNeighbours(const Cell *cell) const
{
	VECTOR neighs = neighbours(cell);

	int count = 0;
	for(ITER iter = neighs.begin(); iter != neighs.end(); ++iter)
	{
		count += (*iter)->isAlive() ? 1 : 0;
	}

	return count;
}

VECTOR Conway::getChangedCells() const
{
    CellFactory factory;
    VECTOR changedCells;
    for(ITER iter = cells.begin(); iter != cells.end(); ++iter)
    {
        const Cell *cell = *iter;
        int aliveNeighs = countAliveNeighbours(cell);
        if(cell->isStatusChanged(aliveNeighs))
        {
            changedCells.push_back(factory.changeCell(cell));
        }
    }

    return changedCells;
}

void Conway::update(VECTOR& changed)
{
	for(ITER iter = changed.begin(); iter != changed.end(); ++iter)
	{
		const Cell *cell = *iter;
        int index_ = index(cell);
		delete cells[index_];
		cells[index_] = cell;
	}
}

int Conway::index(const Cell* cell) const
{
    return index(cell->px, cell->py);
}

int Conway::index(int r, int c) const
{
    return r * column + c;
}

Conway::~Conway()
{
    for(ITER iter = cells.begin(); iter != cells.end(); ++iter)
    {
        delete *iter;
    }
}
