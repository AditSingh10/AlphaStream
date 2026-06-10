#include <iostream>
#include "order_book.hpp"

int main() {
    OrderBook book(60);

    book.add_order({1, Side::Bid, 10050, 100});
    book.add_order({2, Side::Bid, 10025, 200});
    book.add_order({3, Side::Ask, 10075, 150});
    book.add_order({4, Side::Ask, 10100, 300});

    book.print();

    book.cancel_order(1);
    std::cout << "\nAfter cancelling order 1:\n";
    book.print();

    return 0;
}
