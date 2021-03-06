#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

#include "conway.h"
#include "cell_factory.h"

#define ITER VECTOR::const_iterator

void Conway::getSeed(ifstream& data)
{
	CellFactory factory;
	int r = 0;
	int c = 0;

	for(string line; getline(data, line);)
	{
		for(c = 0; c < line.length(); c++)
		{
			cells.push_back(factory.NewCell(r, c, isAlive(line[c])));
		}
		r++;
	}

	row = r;
	column = c;
}

void Conway::propagate()
{
    while(!step());
}

bool Conway::step()
{
    VECTOR changedCells = getChangedCells();
    update(changedCells);

    return isStabilized(changedCells);
}

string Conway::dump() const
{
    string str = "";
	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < column; c++)
		{
			str += cells[index(r, c)]->encode();
		}
		str += "\n";
	}

	return str;
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
		count += (*iter)->present();
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

bool Conway::isAlive(const char& c) const
{
	return c == '1';
}

int Conway::index(const Cell* cell) const
{
    return index(cell->px, cell->py);
}

int Conway::index(int r, int c) const
{
    return r * column + c;
}

bool Conway::isStabilized(VECTOR& changed) const
{
	return !changed.size();
}

Conway::~Conway()
{
    for(ITER iter = cells.begin(); iter != cells.end(); ++iter)
    {
        delete *iter;
    }
}
