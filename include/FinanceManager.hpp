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
    std::vector<Transaction> getTransaction();
    void addTransaction(const Transaction& t);
    void listAll() const;
    void listAllResume() const;
    void listByMonth(const std::string& month, const std::string& year) const;
};

#endif