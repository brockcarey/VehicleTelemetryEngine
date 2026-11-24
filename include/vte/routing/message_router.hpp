#pragma once

#include <cstdint>

#include "vte/types.hpp"

namespace vte::routing
{

class MessageRouter
{
public:
    using Handler = void (*)(const CanFrame&);

    void Register(std::uint32_t arbitration_id, bool is_extended, Handler handler);
    [[nodiscard]] Handler Find(const CanFrame& frame) const;
};

} // namespace vte::routing
