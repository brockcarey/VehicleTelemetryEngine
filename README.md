# Vehicle Telemetry Engine

A C++ engine scaffold for high-throughput vehicle telemetry routing, fault
prioritization, event logging, and threshold analysis.

## Build and run

Requires CMake 3.16 or newer and a C++17 compiler.

```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
.\build\Debug\vte_engine.exe
```

For single-configuration generators, the executable is at
`build/vte_engine.exe`.

## Project layout

- `include/vte/` — public interfaces, grouped by engine module
- `src/` — implementations and application entry point
- `tests/` — unit and integration tests
- `benchmarks/` — performance benchmarks
- `data/` — local datasets; generated or recorded data is not committed
- `docs/architecture.md` — module responsibilities and design constraints

The module headers define the initial API contracts. The entry point wires the
modules, but their processing implementations are not yet included.
