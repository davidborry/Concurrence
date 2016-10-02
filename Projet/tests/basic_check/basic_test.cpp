//
// Created by epu on 9/27/16.
//

#include "../../project/include/Cell.h"
#include "gtest/gtest.h"

TEST(basic_tes__Test,basic_tes__Test_test_eq_Test){
    Cell a;
    EXPECT_EQ(a.isSolid(),false);

    a.setSolid(true);
    EXPECT_EQ(a.isSolid(),true);

    std::cout << "ON TEsSTE";
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
