#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "cell_factory.h"
#include "alive.h"
#include "dead.h"
#include "conway.h"

using namespace std;

TEST(cell_factory_test, gernate_new_cell)
{
	CellFactory factory;
    EXPECT_EQ('$', factory.NewCell(0, 0, true)->encode());
    EXPECT_EQ(' ', factory.NewCell(0, 0, false)->encode());
}


TEST(cell_test, check_cell_status_change)
{
	Alive alive(0, 0);
	Dead dead(0, 1);

    EXPECT_FALSE(alive.isStatusChanged(2));
    EXPECT_FALSE(alive.isStatusChanged(3));
    EXPECT_TRUE(alive.isStatusChanged(1));
    EXPECT_TRUE(alive.isStatusChanged(4));


    EXPECT_FALSE(dead.isStatusChanged(2));
    EXPECT_FALSE(dead.isStatusChanged(4));
    EXPECT_TRUE(dead.isStatusChanged(3));
}

TEST(conway_test, check_propagate_result)
{
	Conway game;
	std::ifstream data("initalData.txt");
	game.getSeed(data);
	data.close();
	game.propagate();

	EXPECT_STREQ(" $ \n$ $\n $ \n", game.dump().c_str());
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
