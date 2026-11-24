# Architecture

The engine is divided into four modules, with public interfaces under
`include/vte/` and implementations under the matching `src/` subdirectory.
Shared event types live in `include/vte/types.hpp`; `include/vte/pipeline.hpp`
defines the composition boundary used by the application entry point.

| Module | Planned structure | Responsibility |
| --- | --- | --- |
| `routing` | Hash map or prefix trie | Map standard and extended CAN IDs to message handlers |
| `faults` | Array-backed binary min/max heap | Dispatch high-priority diagnostic trouble codes first |
| `logging` | Fixed-size circular ring buffer | Record telemetry in bounded storage without steady-state allocation |
| `thresholds` | AVL tree | Maintain ordered sensor values and support range queries |

## Constraints from the proposal

- Target C++17 or newer.
- Preallocate buffers, node pools, and hash buckets before steady-state processing.
- Keep hot-path structures cache-friendly and avoid dynamic allocation during
  steady-state processing.
- Preserve clear interfaces between CAN ingestion and downstream modules.
- Evaluate against at least 500,000 telemetry events and compare each module
  with the baselines described in the project proposal.

The proposal leaves several implementation details open, including hash map
versus trie routing, heap priority direction, and the concurrency guarantees
required by each API. Resolve those choices when defining the module contracts;
the current headers are contract-only and do not assume them. Their method
definitions and the `TelemetryPipeline::Process` implementation remain to be
added. The entry point currently wires the components but does not ingest data.
