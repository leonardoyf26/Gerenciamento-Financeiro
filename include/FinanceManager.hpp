#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H
#include "Transaction.hpp"
#include <string>
#include <vector>

class FinanceManager
{
private:
    std::vector<Transaction> transactions{};

public:
    void addTransaction(const Transaction& t);
    void listAll() const;
    void listByMonth(const std::string& d1) const;
};

#endif