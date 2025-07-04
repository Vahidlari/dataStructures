#include "chapter3/stack_of_plates.hpp"

CStackOfPlates::CStackOfPlates(size_t overalCapacity = stack_t::defaultCapacity)
    : stack_t(overalCapacity, std::ceil(overalCapacity/stack_t::TStackMetadata::stackInitialCapacity)) {
        // A stack is created to track the stacks of plates. This stack will hold the IDs of the stacks created.
        // The top of this stack will be the last stack created.
        createStack(stackTrackingStackID, std::ceil(overalCapacity/stack_t::TStackMetadata::stackInitialCapacity));

        // Create the first stack to hold the actual data
        createStack(firstStackID, stack_t::TStackMetadata::stackInitialCapacity);
    }