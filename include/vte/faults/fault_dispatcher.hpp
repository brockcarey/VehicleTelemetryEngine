#pragma once

#include <optional>

#include "vte/types.hpp"

namespace vte::faults
{

class FaultDispatcher
{
public:
    void Push(const FaultEvent& event);
    [[nodiscard]] std::optional<FaultEvent> PopHighestPriority();
};

} // namespace vte::faults
