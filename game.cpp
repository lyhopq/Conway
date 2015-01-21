#include "conway.h"

int main(int argc, char *argv[])
{
	Conway game;
	game.getSeed();

	game.step();
	game.step();
	game.dump();
}
