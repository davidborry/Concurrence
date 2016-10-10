//
// Created by david on 02/10/16.
//

#include <include/Map.h>
#include <include/Entity.h>
#include "gtest/gtest.h"


Map m(40,40);
TEST(entity_test,dist_test){

    Entity e(&m,Entity::Human,24,12);
    e.setTarget(Vector2i(2,8));
    EXPECT_EQ(e.shortestDistanceToTarget().top(),Vector2i(-22,-4));

    e.setTarget(Vector2i(30,30));
    EXPECT_EQ(e.shortestDistanceToTarget().top(),Vector2i(3,15));

    e.setTarget(Vector2i(0,30));
    EXPECT_EQ(e.shortestDistanceToTarget().top(),Vector2i(-24,15));

    e.setTarget(Vector2i(30,0));
    EXPECT_EQ(e.shortestDistanceToTarget().top(),Vector2i(3,-12));
}

/**
 *
 * Entity should not move or move in loop because it can't reach its target
 */
TEST(entity_test, impass_test){
    Entity e(&m,Entity::Human,24,12);

    m.setSolid(28,0,5,40,true);

    e.setTarget(Vector2i(30,12));
    e.update();

    EXPECT_TRUE(e.getPosition() == Vector2i(24,12) || e.getPosition() == Vector2i(24,11));


}

/**
 * Entity should cancells its vertical or horizontal velocity.
 * It can reach its target but an obstacle is in its way
 */
TEST(entity_test, velocity_test){
    Entity e(&m,Entity::Human,24,12);

    m.setSolid(28,0,5,40,true);

    e.setTarget(Vector2i(40,40));
    e.update();

    EXPECT_EQ(e.getPosition(),Vector2i(24,13));

    m.setSolid(0,17,40,5,true);
    e.setTarget(Vector2i(0,13));
    e.update();

    EXPECT_EQ(e.getPosition(),Vector2i(23,13));

}

TEST(entity_test,corners_test){

    Entity e(&m,Entity::Human,24,12);
    e.move(Vector2i(1,1));
    std::array<Vector2i,4> corners = e.corners();

    EXPECT_EQ(corners[Entity::TL],Vector2i(25,13));
    EXPECT_EQ(corners[Entity::TR],Vector2i(28,13));
    EXPECT_EQ(corners[Entity::BL],Vector2i(25,16));
    EXPECT_EQ(corners[Entity::BR],Vector2i(28,16));
}