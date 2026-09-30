# Per-frame job graph

```
Frame start
    |-- AI update job (steering, wave spawn logic)      --\
    |-- Physics update job (collision, movement resolve) --+--> Animation blend job --> Render submit
```

AI update and Physics update read from `EntityManager` and depend only on
"Frame start" (i.e. last frame's finished state) - they run concurrently on
separate worker threads. Animation blend job depends on BOTH finishing and
merges their results into a final pose. Render submit runs single-threaded
on the main thread after the blend completes.

This is the dependency shape `JobSystem::SubmitAfter` needs to express. See
`src/engine/core/Application.cpp::RunFrame` for where this gets wired up.
