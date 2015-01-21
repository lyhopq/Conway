#ifndef DEAD
#define DEAD

#include "cell.h"

class Dead: public Cell
{
public:
	Dead(int px, int py);
	~Dead();

	bool isAlive() const;
	bool isStatusChanged(int count) const;
	const char show() const;
};
#endif