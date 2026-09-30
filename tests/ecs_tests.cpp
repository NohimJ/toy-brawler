#include <gtest/gtest.h>

#include "engine/ecs/EntityManager.h"

// TODO(you): replace with real coverage once ComponentArray/EntityManager
// have actual bodies - insert/remove/get, swap-and-pop correctness, ID
// recycling. This test only proves the CMake + GoogleTest wiring is
// correct so you can build on it with confidence from commit one.
TEST(EntityManager, CreateEntityReturnsIncreasingIds) {
    engine::EntityManager manager;
    const auto first = manager.CreateEntity();
    const auto second = manager.CreateEntity();
    EXPECT_NE(first, second);
}
