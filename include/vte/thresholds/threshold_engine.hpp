#pragma once

#include <vector>

#include "vte/types.hpp"

namespace vte::thresholds
{

class ThresholdEngine
{
public:
    void Insert(const TelemetrySample& sample);
    [[nodiscard]] std::vector<TelemetrySample> QueryRange(
        std::uint32_t signal_id,
        double minimum_value,
        double maximum_value) const;
};

} // namespace vte::thresholds
