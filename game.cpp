#include <fstream>
#include <stdlib.h>
#include "conway.h"

const char *initalData = "initalData.txt";
const char *output = "final.txt";


int main(int argc, char *argv[])
{
	Conway game;

	std::ifstream data(initalData);
	game.getSeed(data);
	data.close();
    game.propagate();

    std::ofstream fs(output);
	fs << game.dump().c_str();
	fs.close();
}
