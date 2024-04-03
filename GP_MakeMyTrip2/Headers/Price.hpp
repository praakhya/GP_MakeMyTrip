class Price
{
    float amount;
    std::string symbol;
public:
    Price(float amount=0, const std::string& symbol="Rs.")
    : amount(amount),
    symbol(symbol) {
    }
    inline int getAmount() {
        return amount;
    }
    inline const std::string& getSymbol() {
        return symbol;
    }
    friend std::ostream &operator<<(std::ostream &strm, const Price &rhs)
    {
            std::cout << rhs.symbol << " " << rhs.amount;
            return strm;
    }

};