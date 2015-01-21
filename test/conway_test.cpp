#include <gtest/gtest.h>
#include "conway.h"

TEST(CellTest, neighbours)
{
    EXPECT_EQ(expect, cell.neighbours());
}

TEST(get_seed_test, get_seed_from_file)
{

    EXPECT_EQ(expect, get_seed());
}


int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
