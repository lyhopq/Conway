#ifndef CELL
#define CELL

class Cell
{
public:
	Cell(int px, int py);
	virtual ~Cell();

	virtual bool isAlive() const = 0;
	virtual bool isStatusChanged(int count) const = 0;
	virtual char encode() const = 0;
	virtual int  present() const = 0;

	int px;
	int py;
};

#endif
