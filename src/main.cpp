#include "../include/FinanceManager.hpp"
#include "../include/Transaction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//3tasks no codigo
//resolver problema do comando invalido


void createTransaction(FinanceManager& fm);
void interface(FinanceManager& fm);
void listByMonth(const FinanceManager& fm);
void listTransaction(const FinanceManager& fm);
void loadFromFile(FinanceManager& fm);
int typeStr2int(const std::string& t);
int categoryStr2int(const std::string& c);
void saveToFile(FinanceManager& fm);

int main()
{
    FinanceManager fm{};
    loadFromFile(fm);
    interface(fm);
    saveToFile(fm);
    return 0;
}

void saveToFile(FinanceManager& fm)
{
    std::ofstream arq("data/transaction.csv");

    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!\n";
    }

    arq << "Type;Value;Data;Category;Description\n";
    for(auto transaction : fm.getTransaction())
    {
        arq << transaction.getTypeTxt() << ';' << transaction.value << ';' << transaction.date << ';' 
        << transaction.getCategoryTxt() << ';' << transaction.description << '\n';
    }

    arq.close();
}

void loadFromFile(FinanceManager& fm){
    std::ifstream arq("data/transaction.csv");
    std::string line;
    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir o arquivo!\n";
    }

    //skip header
    getline(arq,line);
    while(getline(arq,line)){
        std::string t,d1,c,d2,v;
        std::stringstream ss(line);

        getline(ss, t, ';');
        getline(ss, v, ';');
        getline(ss, d1, ';');
        getline(ss, c, ';');
        getline(ss, d2, ';');
        Transaction tr{typeStr2int(t),std::stod(v),d1,categoryStr2int(c),d2};
        fm.addTransaction(tr);
        std::cout << t << ' ' << v << ' ' << d1 << ' ' << c << ' ' << d2 << '\n';
        std::cout << typeStr2int(t) << ' ' << std::stod(v) << ' ' << d1 << ' ' << categoryStr2int(c) << ' ' << d2 << ' ';
    }
}

int categoryStr2int(const std::string& c){
    if(c == "Alimentacao"){return 1;}
    else if(c == "Transporte"){return 2;}
    else if(c == "Moradia"){return 3;}
    else if(c == "Lazer"){return 4;}
    else if(c == "Saude"){return 5;}
    else if(c == "Educacao"){return 6;}
    else if(c == "Compras"){return 7;}
    else if(c == "Contas"){return 8;}
    else if(c == "Investimentos"){return 9;}
    else if(c == "Outros"){return 10;}
    else{return 10;}
    //lembrar de adicionar condicao para caso de valor invalido
}


int typeStr2int(const std::string& t){
    if(t == "Renda"){return 1;}
    else if(t == "Despesa"){return 2;}
    else{return -1;}
    //lembrar de adicionar condicao para caso de valor invalido

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

void createTransaction(FinanceManager& fm)
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
    std::getline(std::cin, d2);

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

        if(cmd == 1){createTransaction(fm);}
        else if(cmd == 2){listTransaction(fm);}
        else if(cmd == 3){listByMonth(fm);}
        else{std::cout << "\nComando invalido";}
        std::cin.ignore(); 
    }
}