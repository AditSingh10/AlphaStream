#pragma once
#include <cstdint>

enum class Side { Bid, Ask };

struct Order {
    uint64_t id;
    Side     side;
    double   price;
    uint32_t quantity;
};