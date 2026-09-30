#pragma once

#include "Skeleton.h"

namespace engine {

// The job in the frame graph that merges AI update's decisions (e.g.
// "start the Heat Action clip") and Physics update's results (e.g.
// "character is airborne, blend toward a fall pose") into one final pose
// before Render submit.
//
// TODO(you): start with linear blending between exactly two poses by a
// single weight in [0,1]. Don't build a general blend-tree editor - you
// have one moveset, not a AAA animation system to author.
Skeleton BlendPoses(const Skeleton& a, const Skeleton& b, float weight);

} // namespace engine
