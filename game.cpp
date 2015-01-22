#include <iostream>
#include <stdlib.h>
#include "conway.h"

int main(int argc, char *argv[])
{
	Conway game;

	game.getSeed();
    game.propagate();
	game.dump();
}
