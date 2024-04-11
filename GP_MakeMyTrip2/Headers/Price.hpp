#ifndef __PRICE_HPP__
#define __PRICE_HPP__

class Price
{
public:
    float amount;
    std::string symbol;
    Price(float amount=0, const std::string& symbol="Rs.")
    : amount(amount),
    symbol(symbol) {
    }
    friend std::ostream &operator<<(std::ostream &strm, const Price &rhs)
    {
            std::cout << rhs.symbol << " " << rhs.amount;
            return strm;
    }

};

#endif