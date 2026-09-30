#pragma once

#include "engine/math/MathTypes.h"
#include <vector>

namespace engine {

struct AABB {
    Vec3 min;
    Vec3 max;
};

// TODO(you): hand-rolled collision, as planned - don't reach for
// Bullet/PhysX here. Start with:
//   - AABB-vs-AABB overlap test (the branchless six-comparison version)
//   - A batch test over std::vector<AABB> that you can profile and
//     compare against a naive O(n^2) loop - this is your most direct
//     "same skill as the order book's O(n^2) fix" artifact in the whole
//     project, so it's worth deliberately keeping a "before" benchmark.
bool Overlaps(const AABB& a, const AABB& b);

} // namespace engine
