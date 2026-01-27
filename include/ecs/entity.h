#pragma once
#include <cstdint>

namespace sdk::ecs {

// Entity sadece bir ID'dir
using EntityID = std::uint32_t;

// Geçersiz entity tanımı
constexpr EntityID InvalidEntity = 0;

} // namespace sdk::ecs
