#pragma once

#include <cstdint>
#include <vector>
#include <cassert>
#include <cstddef>

namespace engine {

using EntityId = std::uint32_t;

// Dense, contiguous storage for ONE component type across all entities that
// have it - the struct-of-arrays layout from the plan (contrast with an
// array-of-structs "GameObject" holding every component together).
//
// TODO(you): this is core ECS design, deliberately left for you to
// implement rather than handed over:
//   - Store<T> as a flat std::vector<T> (the dense array itself)
//   - A sparse EntityId -> dense-index map (so removing entity 7 doesn't
//     require shifting every element after it - swap-and-pop against the
//     dense array, then fix up the sparse map for whichever entity got
//     moved into the freed slot)
//   - Insert(EntityId, T), Remove(EntityId), Get(EntityId) -> T&
//   - An iteration path that returns the dense array directly - the whole
//     point of this class is that a system can walk contiguous memory,
//     so don't route iteration through the sparse map.
//
// Think about it in terms of the order book: the dense array here is your
// "hot" data, iterated every frame; the sparse map is closer to an index
// you consult occasionally, not something you stream through.
template <typename T>
class ComponentArray {
public:
    void Insert(EntityId id, T component){
        if (id >= sparse_.size()){
            sparse_.resize(id+1, NO_COMPONENT);
        }
        dense_.push_back(component);
        dense_to_entity_.push_back(id);
        sparse_[id] = dense_.size()-1;

    }

    void Remove(EntityId id){
        size_t i = sparse_[id];


        T temp = dense_[dense_.size()-1];
        EntityId temp2 = dense_to_entity_[dense_to_entity_.size()-1];

       dense_[dense_.size()-1] = dense_[i];
       dense_to_entity_[dense_to_entity_.size()-1] = dense_to_entity_[i];

       dense_[i] = temp;
       dense_to_entity_[i] = temp2;

       dense_.pop_back();
       dense_to_entity_.pop_back();   
       
       if (i < dense_.size()) {   
            sparse_[dense_to_entity_[i]] = i;
        }
        sparse_[id] = NO_COMPONENT;
    }

    T& Get(EntityId id){
        assert(id < sparse_.size());         
        assert(sparse_[id] != NO_COMPONENT);   
        return dense_[sparse_[id]];
    }

    std::vector<T>& Dense() { return dense_; }

private:
    static constexpr size_t NO_COMPONENT = SIZE_MAX;

    std::vector<T> dense_;          
    std::vector<EntityId> dense_to_entity_; 
    std::vector<size_t> sparse_;      
};

} 
