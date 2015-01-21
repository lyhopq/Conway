#ifndef CELL
#define CELL

class Cell
{
public:
	Cell(int px, int py);
	virtual ~Cell();

	virtual const char show() const = 0;

private:
	int px;
	int py;
};

#endif