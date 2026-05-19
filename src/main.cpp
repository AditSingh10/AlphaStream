#include <iostream>
#include "order_book.hpp"

int main() {
    OrderBook book;

    book.add_order({1, Side::Bid, 100.50, 100});
    book.add_order({2, Side::Bid, 100.25, 200});
    book.add_order({3, Side::Ask, 100.75, 150});
    book.add_order({4, Side::Ask, 101.00, 300});

    book.print();

    book.cancel_order(1);
    std::cout << "\nAfter cancelling order 1:\n";
    book.print();

    return 0;
}
