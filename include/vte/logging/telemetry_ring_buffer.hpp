#pragma once

#include <cstddef>
#include <optional>

namespace vte::logging
{

template <typename T, std::size_t Capacity>
class TelemetryRingBuffer
{
    static_assert(Capacity > 0, "Ring buffer capacity must be positive");

public:
    void Append(const T& item);
    [[nodiscard]] std::optional<T> GetOldest(std::size_t offset) const;
    [[nodiscard]] std::size_t Size() const noexcept;

    static constexpr std::size_t capacity() noexcept
    {
        return Capacity;
    }
};

} // namespace vte::logging
