#ifndef ORDER_H
#define ORDER_H

#include <cstdint>

enum class Side {
    Buy,
    Sell,
};

using OrderId = std::uint64_t;
using Price = std::int64_t;
using Quantity = std::uint64_t;


class Order {
public:
    Order(OrderId id, Price price, Quantity quantity, Side side)
        : m_id{ id }
        , m_price{ price }
        , m_quantity{ quantity }
        , m_side{ side }
    {}
    
    OrderId getId() const { return m_id; };
    Price getPrice() const { return m_price; };
    Quantity getQuantity() const { return m_quantity; };
    Side getSide() const { return m_side; };

    void setQuantity(Quantity q) { m_quantity = q; };


private:
    OrderId m_id{};
    Price m_price{};
    Quantity m_quantity{};
    Side m_side{};
}; 

#endif  // ORDER_H