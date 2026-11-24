#pragma once

#include <cstddef>

#include "vte/faults/fault_dispatcher.hpp"
#include "vte/logging/telemetry_ring_buffer.hpp"
#include "vte/routing/message_router.hpp"
#include "vte/thresholds/threshold_engine.hpp"
#include "vte/types.hpp"

namespace vte
{

template <std::size_t LogCapacity>
class TelemetryPipeline
{
public:
    using EventLog = logging::TelemetryRingBuffer<TelemetrySample, LogCapacity>;

    TelemetryPipeline(
        routing::MessageRouter& router,
        faults::FaultDispatcher& fault_dispatcher,
        EventLog& event_log,
        thresholds::ThresholdEngine& threshold_engine) noexcept
        : router_(router),
          fault_dispatcher_(fault_dispatcher),
          event_log_(event_log),
          threshold_engine_(threshold_engine)
    {
    }

    void Process(const CanFrame& frame);

private:
    routing::MessageRouter& router_;
    faults::FaultDispatcher& fault_dispatcher_;
    EventLog& event_log_;
    thresholds::ThresholdEngine& threshold_engine_;
};

} // namespace vte
