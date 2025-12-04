#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction
{
public:
    enum class Type {
        renda,
        despesa
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
   
    int type_num;
    double value;
   
    std::string date;
   
    int catg_num;
    Category category;
   
    std::string description;

public:
    Transaction(int t, double v, std::string d1, int c, std::string d2);
    void setEnumType();
    void setEnumCategory();
    std::string getTypeTxt();
    std::string getCategoryTxt();
};

#endif