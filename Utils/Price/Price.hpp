class Price
{
    int amount;
    std::string symbol;
public:
    Price(int amount, const std::string& symbol="Rs.")
    : amount(amount),
    symbol(symbol) {
    }
    inline int getAmount() {
        return amount;
    }
    inline const std::string& getSymbol() {
        return symbol;
    }

};