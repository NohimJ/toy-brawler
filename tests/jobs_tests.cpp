#include <gtest/gtest.h>

#include "engine/jobs/JobSystem.h"

// TODO(you): once Submit/SubmitAfter/Wait exist, the real tests here are
// the ones that matter most for a concurrency portfolio piece:
//   - N jobs submitted concurrently all complete exactly once
//   - a job with two dependencies never starts before both finish
//   - stress test under ThreadSanitizer (-fsanitize=thread), same
//     discipline you used AddressSanitizer for on the order book.
TEST(JobSystem, ConstructsAndDestructsCleanly) {
    engine::JobSystem jobs(2);
    SUCCEED();
}
