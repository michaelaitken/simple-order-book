#include <iostream>
#include "OrderBook.h"

void OrderBook::addOrder(const Order& order) {
    if (order.getSide() == Side::Buy) {
        m_buy_orders[order.getPrice()].push_back(order);
    } else {
        m_sell_orders[order.getPrice()].push_back(order);
    }
    matchOrders();
}

void OrderBook::matchOrders() {
    while (!m_buy_orders.empty() && !m_sell_orders.empty()) {
        auto highest_buy = m_buy_orders.rbegin();
        auto lowest_sell = m_sell_orders.begin();

        if (highest_buy->first < lowest_sell->first) break;

        auto& buy_list = highest_buy->second;
        auto& sell_list = lowest_sell->second;

        while (!buy_list.empty() && !sell_list.empty()) {
            Order& buy = buy_list.back();
            Order& sell = sell_list.back();

            Quantity traded_qty = std::min(buy.getQuantity(), sell.getQuantity());

            buy.setQuantity(buy.getQuantity() - traded_qty);
            sell.setQuantity(sell.getQuantity() - traded_qty);

            std::cout << "Trade executed: " << traded_qty
                      << " units @ " << static_cast<double>(sell.getPrice()) / 100.00 << "\n";
            
            if (buy.getQuantity() == 0) buy_list.pop_back();
            if (sell.getQuantity() == 0) sell_list.pop_back();
        }

        if (buy_list.empty()) m_buy_orders.erase(highest_buy->first);
        if (sell_list.empty()) m_sell_orders.erase(lowest_sell->first);
    }
}

void OrderBook::printOrderBook() const {
    std::cout << " === BUY ORDERS ===\n";
    for (auto iter = m_buy_orders.rbegin(); iter != m_buy_orders.rend(); ++iter) {
        for (const auto& order : iter->second) {
            std::cout << "Price: " << static_cast<double>(iter->first) / 100.00
                      << " | Qty: " << order.getQuantity() << "\n";
        }
    }

    std::cout << " === SELL ORDERS ===\n";
    for (const auto& [price, orders] : m_sell_orders) {
        for (const auto& order : orders) {
            std::cout << "Price: " << static_cast<double>(price) / 100.00
                      << " | Qty: " << order.getQuantity() << "\n";
        }
    }
}