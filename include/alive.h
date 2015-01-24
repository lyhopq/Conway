#ifndef ALIVE
#define ALIVE

#include "cell.h"

class Alive: public Cell
{
public:
	Alive(int px, int py);
	virtual ~Alive();

	bool isAlive() const;
	bool isStatusChanged(int count) const;
	char encode() const;
	int present() const;

};
#endif
