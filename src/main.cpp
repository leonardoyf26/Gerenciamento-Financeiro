#include "../include/FinanceManager.hpp"
#include "../include/Transaction.hpp"
#include <iostream>
#include <stdio.h>

void creatTransaction(FinanceManager& fm);
void interface(FinanceManager& fm);
void listByMonth(const FinanceManager& fm);
void listTransaction(const FinanceManager& fm);

int main()
{
    FinanceManager fm{};
    interface(fm);
    return 0;
}

void listTransaction(const FinanceManager& fm){
    system("cls");
    fm.listAll();
    std::cout << "\nPressione enter tecla para continuar...";
    std::cin.get(); 
}

void listByMonth(const FinanceManager& fm)
{
    system("cls");
    std::string month;
    std::cout << "Digite um valor de mes(mm): ";
    std::cin >> month;

    fm.listByMonth(month);

    std::cout << "\n\n\nPressione enter tecla para continuar...";
    std::cin.get(); 
}

void creatTransaction(FinanceManager& fm)
{
    int t, c;
    double v;
    std::string d1, d2;
    
    system("cls");
    std::cout << "Entre com o tipo: \n";
    std::cout << "1 - Renda \n";
    std::cout << "2 - Despesa \n";
    std::cin >> t;

    system("cls");
    std::cout << "Valor(R$): ";
    std::cin >> v;

    std::cout << "Data (dd-mm-aaaa): ";
    std::cin >> d1;

    system("cls");
    std::cout << "Categoria: \n";
    std::cout << "1 - Alimentacao   5 - Saude      9  - Investimento\n";
    std::cout << "2 - Transporte    6 - Educacao   10 - Outros\n";
    std::cout << "3 - Moradia       7 - Compras\n";
    std::cout << "4 - Lazer         8 - Contas\n\n";
    std::cin >> c;
    std::cin.ignore();

    system("cls");
    std::cout << "Descricao: ";
    std::cin >> d2;

    Transaction tr{t,v,d1,c,d2};
    fm.addTransaction(tr);
}

void interface(FinanceManager& fm)
{
    size_t cmd{10};
    //lembrar de carregar os dados do arquivo .csv

    while(cmd){
        system("cls");
        std::cout << "Digite a operacao\n";
        std::cout << "1 - Adicionar Transacao\n";
        std::cout << "2 - Listar todas as transacoes\n";
        std::cout << "3 - Listar transacao por mes\n\n";
        std::cin >> cmd;

        if(std::cin.fail()) {
            std::cin.clear(); 
            std::cout << "\nComando invalido. Tente novamente.\n";
            std::cin.ignore();
            continue; 
        }

        if(cmd == 1){creatTransaction(fm);}
        else if(cmd == 2){listTransaction(fm);}
        else if(cmd == 3){listByMonth(fm);}
        else{std::cout << "\nComando invalido";}
        std::cin.ignore(); 
    }
}