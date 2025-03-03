#include <iostream>
#include "OrderBook.h"

int main() {
    // Basic Tests
    OrderBook orderBook{};

    orderBook.addOrder(Order(1, 100.0, 10, Side::Buy));
    orderBook.addOrder(Order(2, 101.0, 5, Side::Buy));
    orderBook.addOrder(Order(3, 99.0, 8, Side::Sell));
    orderBook.addOrder(Order(4, 100.0, 3, Side::Sell));

    orderBook.printOrderBook();
    return 0;
}