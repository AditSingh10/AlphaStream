#include "order_book.hpp"
#include <iostream>

void OrderBook::add_order(const Order& order) {
    // TODO: add to orders_, then add quantity to the right price level in bids_ or asks_
}

void OrderBook::cancel_order(uint64_t order_id) {
    // TODO: look up order in orders_, reduce quantity at its price level, remove if zero, erase from orders_
}

void OrderBook::print() const {
    // TODO: print asks (ascending), then bids (descending) — shows the book as a ladder
}
