#pragma once

namespace sdk::ecs {

// --- Transform / Position ---
struct Position {
    float x{0.f};
    float y{0.f};
    float z{0.f};
};

// --- Health ---
struct Health {
    int value{100};
};

// --- Velocity (ileride physics için) ---
struct Velocity {
    float x{0.f};
    float y{0.f};
    float z{0.f};
};

} // namespace sdk::ecs
