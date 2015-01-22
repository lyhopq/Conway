#include <iostream>
#include <stdlib.h>
#include "conway.h"

int main(int argc, char *argv[])
{
    // int times = 1;
    // if(argc > 1)
    // {
    //     times = atoi(argv[1]);
    // }

    // std::cout << "Propagate " << times << " time(s)." << std::endl;

	Conway game;
	game.getSeed();

    // for(int i = 0; i < times; i++)
    {
        game.step();
    }

	game.dump();
}
