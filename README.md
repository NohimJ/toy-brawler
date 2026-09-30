# yakuza-toy

A single-location, wave-survival brawler (Kiryu vs. waves of enemies on a
beach, one Heat Action) built on a small custom C++ engine. See
`docs/job-graph.md` for the per-frame threading model.

## Layout

```
src/engine/     Reusable engine core - knows nothing about Kiryu, enemies, or waves.
    core/       Window, main loop, frame clock.
    ecs/        Entity IDs + struct-of-arrays component storage.
    jobs/       Fixed-size worker thread pool with dependency-counted jobs.
    renderer/   RendererBackend interface (backend-agnostic) + mesh/shader types.
    physics/    Hand-rolled AABB collision.
    animation/  Skeleton + pose blending.
    math/       Thin aliases over GLM.
src/game/       Game-specific: Kiryu, Enemy, WaveSpawner, CombatSystem.
tests/          GoogleTest, fetched via CMake FetchContent.
assets/         models/ shaders/ textures/
docs/           Design notes (job graph, etc).
```

## Building

```
cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build -j
ctest --test-dir build
```

First configure will fetch GLFW, GLM, and GoogleTest via `FetchContent` -
requires network access and takes a minute.

## Status

Scaffold only - see `TODO(you)` comments throughout for what's implemented
vs. what's designed-but-not-written. Build order roughly follows the
project plan: engine skeleton -> renderer core -> combat+animation ->
enemy waves+AI -> performance pass -> portfolio packaging.
