#pragma once

#include <array>
#include <cstdint>

namespace vte
{

struct CanFrame
{
    std::uint32_t arbitration_id{};
    bool is_extended{};
    std::uint8_t payload_size{};
    std::array<std::uint8_t, 8> payload{};
};

struct FaultEvent
{
    std::uint32_t code{};
    std::uint8_t priority{};
    std::uint64_t timestamp{};
};

struct TelemetrySample
{
    std::uint32_t signal_id{};
    double value{};
    std::uint64_t timestamp{};
};

} // namespace vte
