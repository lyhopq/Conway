#ifndef DEAD
#define DEAD

#include "cell.h"

class Dead: public Cell
{
public:
	Dead(int px, int py);
	~Dead();

	const char show() const;
};
#endif