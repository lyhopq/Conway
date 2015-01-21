#ifndef CELL
#define CELL

class Cell
{
public:
	Cell(int px, int py);
	virtual ~Cell();

	virtual const char show() const = 0;
	virtual bool isAlive() const = 0;

	int px;
	int py;
};

#endif