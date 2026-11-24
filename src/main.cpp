#include <iostream>

#include "vte/faults/fault_dispatcher.hpp"
#include "vte/logging/telemetry_ring_buffer.hpp"
#include "vte/pipeline.hpp"
#include "vte/routing/message_router.hpp"
#include "vte/thresholds/threshold_engine.hpp"

namespace
{
constexpr std::size_t kLogCapacity = 4096;
}

int main()
{
    vte::routing::MessageRouter router;
    vte::faults::FaultDispatcher fault_dispatcher;
    vte::logging::TelemetryRingBuffer<vte::TelemetrySample, kLogCapacity> event_log;
    vte::thresholds::ThresholdEngine threshold_engine;

    vte::TelemetryPipeline<kLogCapacity> pipeline{
        router,
        fault_dispatcher,
        event_log,
        threshold_engine
    };
    (void)pipeline;

    std::cout << "Vehicle Telemetry Engine: module interfaces wired; "
                 "processing is not implemented yet\n";
    return 0;
}
