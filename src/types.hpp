#pragma once
#include <cstdint>

enum class Side { Bid, Ask };

struct Order {
    uint64_t id;
    Side     side;
    int64_t   price; // scaled integer to avoid floating point error accumulations affecting comparisons
    uint32_t quantity;
};

struct OHLCV {
    int64_t open;
    int64_t high;
    int64_t low;
    int64_t close;
    uint32_t volume;
};
