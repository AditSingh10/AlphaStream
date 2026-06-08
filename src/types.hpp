#pragma once
#include <cstdint>

enum class Side { Bid, Ask };

struct Order {
    uint64_t id;
    Side     side;
    int64_t   price; // scaled integer to avoid floating point error accumulations affecting comparisons
    uint32_t quantity;
};