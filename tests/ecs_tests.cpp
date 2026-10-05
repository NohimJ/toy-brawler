#include <gtest/gtest.h>

#include "engine/ecs/EntityManager.h"
#include "engine/ecs/ComponentArray.h"



TEST(EntityManager, CreateEntityReturnsIncreasingIds) {
    engine::EntityManager manager;
    const auto first = manager.CreateEntity();
    const auto second = manager.CreateEntity();
    EXPECT_NE(first, second);
}

struct TestComponent {
    int value;
    bool operator==(const TestComponent&) const = default;
};

TEST(ComponentArray, InsertThenGetReturnsCorrectValue) {
    engine::ComponentArray<TestComponent> components;

    engine::EntityId id = 5;
    components.Insert(id, TestComponent{42});

    EXPECT_EQ(components.Get(id).value, 42);
}

TEST(ComponentArray, MultipleEntitiesHaveIndependentValues) {

    engine::ComponentArray<TestComponent> components;

    engine::EntityId id1 = 5;
    engine::EntityId id2 = 6;
    engine::EntityId id3 = 7;
    engine::EntityId id4 = 8;

    components.Insert(id1, TestComponent{42});
    components.Insert(id2, TestComponent{43});
    components.Insert(id3, TestComponent{44});
    components.Insert(id4, TestComponent{45});

    EXPECT_EQ(components.Get(id1).value, 42);
    EXPECT_EQ(components.Get(id2).value, 43);
    EXPECT_EQ(components.Get(id3).value, 44);
    EXPECT_EQ(components.Get(id4).value, 45);
}

TEST(ComponentArray, InsertThenRemoveValue) {
    engine::ComponentArray<TestComponent> components;

    engine::EntityId id = 5;
    components.Insert(id, TestComponent{42});
    components.Remove(id);
    
    EXPECT_DEATH(components.Get(id), "");
}

TEST(ComponentArray, RemoveFromMiddlePreservesOtherEntities) {
    engine::ComponentArray<TestComponent> components;

    components.Insert(5, TestComponent{100});
    components.Insert(2, TestComponent{200});
    components.Insert(9, TestComponent{300});
    components.Insert(1, TestComponent{400});

    components.Remove(2);  

    EXPECT_EQ(components.Get(5).value, 100);
     EXPECT_EQ(components.Get(9).value, 300);
      EXPECT_EQ(components.Get(1).value, 400);
  
}

TEST(ComponentArray, RemoveLastElementDoesNotCrash) {
    engine::ComponentArray<TestComponent> components;

    components.Insert(5, TestComponent{100});
    components.Insert(2, TestComponent{200});
    components.Insert(9, TestComponent{300});

    components.Remove(9);  // entity 9 is at the last dense index

    EXPECT_EQ(components.Get(5).value, 100);
    EXPECT_EQ(components.Get(2).value, 200);
}