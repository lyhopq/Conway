#include <gtest/gtest.h>
#include "cell_factory.h"
#include "alive.h"
#include "dead.h"

TEST(cell_factory_test, gernate_new_cell)
{
	CellFactory factory;
    EXPECT_EQ('$', factory.NewCell(0, 0, '1')->show());
    EXPECT_EQ(' ', factory.NewCell(0, 0, '0')->show());
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
