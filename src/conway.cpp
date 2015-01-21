#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

#include "conway.h"
#include "cell_factory.h"

using namespace std;

const char *initalData = "initalData.txt";
const char *output = "final.txt";

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
	CellFactory factory;
	vector<Cell*> changedCells;
	for(int index = 0; index < cells.size(); index++)
	{
		Cell *cell = cells[index];
		int aliveNeighs = countAliveNeighbours(cell);
		// cout << cell->px << cell->py << aliveNeighs << endl;
		if(cell->isStatusChanged(aliveNeighs))
		{
			changedCells.push_back(factory.changeCell(cell));
		}

	}

	update(changedCells);
}

void Conway::dump() const
{
    ofstream fs(output);
	for(int r = 0; r < row; r++)
	{
		for(int c = 0; c < column; c++)
		{
			fs << cells[r * column + c]->show();
		}
		fs << endl;
	}

	fs.close();
}

vector<Cell*> Conway::neighbours(Cell *cell) const
{
	vector<Cell*> neighs;
	for(int r = cell->px - 1; r <= cell->px + 1; r++)
	{
		for(int c = cell->py - 1; c <= cell->py + 1; c++)
		{
			if(r == cell->px && c == cell->py) continue;
			if(r < 0 || r >= row || c < 0 || c >= column) continue;

			neighs.push_back(cells[r * column + c]);
		}
	}

	return neighs;
}

int Conway::countAliveNeighbours(Cell *cell) const 
{
	vector<Cell*> neighs = neighbours(cell);

	int count = 0;
	for(vector<Cell*>::iterator iter = neighs.begin(); iter != neighs.end(); ++iter)
	{
		count += (*iter)->isAlive() ? 1 : 0;
		cout << (*iter)->px << (*iter)->py << (*iter)->isAlive() << endl;
	}
	cout << endl;

	return count;
}

void Conway::update(vector<Cell*>& changed)
{
	for(vector<Cell*>::iterator iter = changed.begin(); iter != changed.end(); ++iter)
	{
		Cell *cell = *iter;
		delete cells[cell->index()];
		cells[cell->index()] = cell;
	}

}
