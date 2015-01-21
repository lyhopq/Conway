#include <gtest/gtest.h>
#include "cell_factory.h"
#include "alive.h"
#include "dead.h"

TEST(cell_factory_test, gernate_new_cell)
{
	CellFactory factory;
    EXPECT_EQ(new Alive(0, 0), factory.NewCell(0, 0, '1'));
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
