#include "../include/FinanceManager.hpp"
#include <iostream>

void FinanceManager::addTransaction(const Transaction& t){
    this->transactions.emplace_back(t);
}
std::vector<Transaction> FinanceManager::getTransaction()
{
    return this->transactions;
}

void FinanceManager::listAll() const{
    for(auto t : this->transactions){
        std::cout << "Tipo: " << t.getTypeTxt()  << '\n';
        std::cout << "Valor: " <<  t.value << '\n';
        std::cout << "Data: " << t.date  << '\n';
        std::cout << "Categoria: " << t.getCategoryTxt()  << '\n';
        std::cout << "Descricao: " << t.description  << '\n';
        std::cout << "------------------------\n";
    }
}

void FinanceManager::listByMonth(const std::string& d1 ) const{
    double income{}, expense{};
    for(auto t : this->transactions){
        if(t.date.substr(3,2) == d1)
        {
            if(t.type == Transaction::Type::renda){income += t.value;}
            else if(t.type == Transaction::Type::despesa){expense += t.value;}
        }
    }

    std::cout << "\n\n------------------------";
    std::cout << "\nRelatorio do mes " << d1;
    std::cout << "\nRenda: " << income << "R$";
    std::cout << "\nDespesa: " << expense << "R$";
    std::cout << "\nSaldo: " << income - expense << "R$";
    std::cout << "------------------------\n\n";
}