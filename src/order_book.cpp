#include "order_book.hpp"
#include <iostream>
#include <ranges>

void OrderBook::add_order(const Order& order) {
    orders_[order.id] = order;
    if (order.side == Side::Bid){
        bids_[order.price] += order.quantity;
    } else {
        asks_[order.price] += order.quantity;
    }
}

void OrderBook::cancel_order(uint64_t order_id) {
    auto it = orders_.find(order_id);
    if (it == orders_.end()) return;

    const Order& order = it->second;
    if (order.side == Side::Bid){
        auto level_it = bids_.find(order.price);
        if (level_it != bids_.end()) {
            if (level_it->second < order.quantity){
                std::cerr << "cancel_order: quantity underflow for order " << order_id << "\n";
                orders_.erase(it);
                return; 
            }
            level_it->second -= order.quantity;
            if (level_it->second == 0)
                bids_.erase(level_it);
        }
        orders_.erase(it);
    } else{
        auto level_it = asks_.find(order.price);
        if (level_it != asks_.end()) {
            if (level_it->second < order.quantity){
                std::cerr << "cancel_order: quantity underflow for order " << order_id << "\n";
                orders_.erase(it);
                return; 
            }
            level_it->second -= order.quantity;
            if (level_it->second == 0)
                asks_.erase(level_it);
        }
        orders_.erase(it);
    }
}


void OrderBook::print() const {
    // TODO: print asks (ascending), then bids (descending) — shows the book as a ladder

    // print asks
    for (const auto& [key,value]: asks_ | std::views::reverse){
        std::cout << "QTY: " << value << " units of AAPL selling at PRICE: " << key << "\n";
    }

    // print buys
    for (const auto& [key,value]: bids_){
        std::cout << "QTY: " << value << " units of AAPL buying at PRICE: " << key << "\n";
    }


}
