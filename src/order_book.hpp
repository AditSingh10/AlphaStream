#pragma once
#include <map>
#include <unordered_map>
#include <functional>
#include "types.hpp"

class OrderBook {
public:
    void add_order(const Order& order);
    void cancel_order(uint64_t order_id);
    void print() const;

private:
    std::map<int64_t, uint32_t, std::greater<int64_t>> bids_; // highest price first
    std::map<int64_t, uint32_t>                       asks_; // lowest price first
    std::unordered_map<uint64_t, Order>              orders_; // order_id : Order
};
