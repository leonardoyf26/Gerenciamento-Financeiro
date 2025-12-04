#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction
{
public:
    enum class Type {
        income,
        expense
    };

public:
    enum class Category {
        Alimentacao,
        Transporte,
        Moradia,
        Lazer,
        Saude,
        Educacao,
        Compras,
        Contas,
        Investimentos,
        Outros
    };

public:
    Type type;
    double value;
    std::string date;
    Category category;
    std::string description;

public:
    Transaction(Type t, double v, std::string d1, Category c, std::string d2);
    std::string getTypeTxt(Type t);
    std::string getCategoryTxt(Category c);
};

#endif