#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "Order.h"
#include <map>
#include <vector>

class OrderBook {
public:
    void addOrder(const Order& order);
    void cancelOrder(OrderId id);
    void matchOrders();
    void printOrderBook() const;

private:
    std::map<Price, std::vector<Order>> m_buy_orders{};
    std::map<Price, std::vector<Order>> m_sell_orders{};
};

#endif // ORDERBOOK_H