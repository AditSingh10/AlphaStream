#pragma once
#include <map>
#include <unordered_map>
#include <functional>
#include "types.hpp"
#include <vector>

class OrderBook {
public:
    void add_order(const Order& order);
    void cancel_order(uint64_t order_id);
    void print() const;
    void execute_order(uint64_t order_id, uint32_t executed_quantity, uint64_t timestamp);
    void modify_order(uint64_t order_id, int64_t new_price, uint32_t new_quantity);
    void accumulate_order(int64_t price, uint32_t executed_quantity, uint64_t timestamp);
    OrderBook(uint64_t window_width);

private:
    std::map<int64_t, uint32_t, std::greater<int64_t>> bids_; // highest price first
    std::map<int64_t, uint32_t>                       asks_; // lowest price first
    std::unordered_map<uint64_t, Order>              orders_; // order_id : Order
    uint64_t window_start_;
    std::vector<OHLCV> bars_;
    OHLCV current_;
    uint64_t window_width_;
};
