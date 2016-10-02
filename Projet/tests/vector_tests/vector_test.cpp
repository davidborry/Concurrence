//
// Created by david on 02/10/16.
//

#include "gtest/gtest.h"
#include "include/Map.h"

Vector2i a(4,3);
Vector2i b(a);
Vector2i c(8,4);


TEST(vector_test, test_length){
    EXPECT_EQ(a.length(),5);
    a = c;
    EXPECT_NEAR(a.length(),8.94,0.1);

    a.y++;
    EXPECT_EQ(a.length(),sqrt(64+25));
    EXPECT_EQ(b.length(),5);

}

TEST(vector_test, test_eq){
    a = b;
    EXPECT_EQ(a,b);
}

TEST(vector_test, test_neq){
    EXPECT_NE(a,c);
}

TEST(vector_test, test_inf){
    EXPECT_TRUE(a < c);
    EXPECT_TRUE(a <= c);
    EXPECT_TRUE(a <= a);
    EXPECT_FALSE(a < a);
}

TEST(vector_test, test_sup){
    EXPECT_TRUE(c > a);
    EXPECT_TRUE(c >= a);
    EXPECT_TRUE(c >= c);
    EXPECT_FALSE(c > c);
}

TEST(vector_test, test_plus){
    Vector2i d = a + c;
    Vector2i v(12,7);
    EXPECT_EQ(d,v);
    EXPECT_EQ(d.length(),v.length());
}

TEST(vector_test, test_minus){
    Vector2i d = a - c;
    Vector2i v(-4,-1);
    EXPECT_EQ(d,v);
    EXPECT_EQ(d.length(),v.length());
}

TEST(vector_test, test_prod){
    Vector2i d = 2*a;
    Vector2i v(8,6);

    EXPECT_EQ(d,v);
    EXPECT_EQ(d.length(),v.length());
}

TEST(vector_test, test_div){
    Vector2i d = c/2;
    Vector2i v(4,2);

    EXPECT_EQ(d,v);
    EXPECT_EQ(d.length(),v.length());
}