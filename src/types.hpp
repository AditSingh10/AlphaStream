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
    int64_t OPEN;
    int64_t HIGH;
    int64_t LOW;
    int64_t CLOSE;
    uint32_t VOLUME;
};
