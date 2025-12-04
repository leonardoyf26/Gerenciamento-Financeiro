#include "../include/Transaction.hpp"

Transaction::Transaction(int t, double v, std::string d1, int c, std::string d2):
type_num(t), value(v), date(d1), catg_num(c), description(d2)
{
    setEnumType();
    setEnumCategory();
}

void Transaction::setEnumType()
{
    switch (this->type_num)
    {
    case 1:
        this->type = Type::renda;
        break;
    case 2:
        this->type = Type::despesa;
        break;
    default:
        break;
    }
}

void Transaction::setEnumCategory()
{
    switch (this->catg_num)
    {
    case 1:
        this->category = Category::Alimentacao;
        break;
    case 2:
        this->category = Category::Transporte;
        break;
    case 3:
        this->category = Category::Moradia;
        break;
    case 4:
        this->category = Category::Lazer;
        break;
    case 5:
        this->category = Category::Saude;
        break;
    case 6:
        this->category = Category::Educacao;
        break;
    case 7:
        this->category = Category::Compras;
        break;
    case 8:
        this->category = Category::Contas;
        break;
    case 9:
        this->category = Category::Investimentos;
        break;
    case 10:
        this->category = Category::Outros;
        break;
    default:
        break;
    }
}

std::string Transaction::getTypeTxt()
{
    switch (this->type)
    {
    case Type::renda:
        return "Renda";
    case Type::despesa:
        return "Despesa";
    default:
        return "Tipo invalido";
    }
}

std::string Transaction::getCategoryTxt()
{
    switch (this->category)
    {
    case Category::Alimentacao:
        return "Alimentacao";
    case Category::Compras:
        return "Compras";
    case Category::Contas:
        return "Contas";
    case Category::Educacao:
        return "Educacao";
    case Category::Investimentos:
        return "Investimento";
    case Category::Lazer:
        return "Lazer";
    case Category::Moradia:
        return "Moradia";
    case Category::Saude:
        return "Saude";
    case Category::Transporte:
        return "Transporte";
    case Category::Outros:
        return "Outros";
    default:
        return "Categoria invalida";
    }
}