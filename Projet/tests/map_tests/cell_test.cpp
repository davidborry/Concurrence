//
// Created by david on 02/10/16.
//

#include "gtest/gtest.h"
#include "include/Cell.h"

TEST(cellTest, testSolid_a){
    Cell a;

    EXPECT_EQ(a.isSolid(),false);
}

TEST(cellTest, testSolid_b){
    Cell a;
    a.setSolid(true);

    EXPECT_EQ(a.isSolid(),true);
}
