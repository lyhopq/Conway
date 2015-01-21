#ifndef ALIVE
#define ALIVE 

#include "cell.h"

class Alive: public Cell
{
public:
	Alive(int px, int py);
	virtual ~Alive();

	const char show() const;
};
#endif