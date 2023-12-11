#include"User.hpp"
#include"../Database/ClientDB.hpp"
#include "iostream"

User::User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance): Client(_username, _password, _email, _cpf, balance, 1)
{
    //_library = _library;
    //_wishlist = _wishlist;
}

void User::menu()
{
    int aux;
    std::cout << "Bem vindo, " << _username << "!\n";
    INIT:
    std::cout << "O que deseja fazer?\n1 - Ver/Alterar Dados\n2 - Ver/Adicionar Saldo\n3 - Ver biblioteca\n4 - Loja\n5 - Ver lista de desejos\n6 - Sair\n";
    std::cin >> aux;
    switch (aux)
    {
    case 1:
        // Mostra os dados de Developer sem usar DB
        ClientDB::edit_info(this); // Função que edita os dados do cliente no banco de dados e usando o this, edita nessa instancia da classe DIFERENTE DO DEVELOPER
        std::cout << "Dados alterados com sucesso!\n";
        goto INIT;
        break;
    case 2:
        ClientDB::add_balance(this); // Função que permite que o usuario veja seu saldo atual e resgate um valor
        std::cout << "Valores resgatados com sucesso!\n";
        goto INIT;
        break;
    case 3:
    /*
        for(int i = 0 ; i < _library.size() ; i++)
        {
            std::cout << i+1 << " " << _library[i].get_name() << '\n';
        }
    */
        goto INIT;
        break;
    case 4:
        //GameDB::show_games();
        std::cout << "O que deseja fazer?\n1 - Comprar jogo;\n2 - Adicionar um jogo à lista de desejos;\n3 - Sair;\n";
        std::cin >> aux;
        switch (aux)
        {
            case 1:
                //GameDB::buy_game(this);
                break;
            case 2:
                //GameDB::add_to_wishlist(this);
                break;
            default:
                break;
        }
        goto INIT;
    case 5:
        /*
        for(int i = 0 ; i < _wishlist.size() ; i++)
        {
            std::cout << i+1 << " " << _wishlist[i].get_name() << '\n';
        }
        */
        goto INIT;
        break;
    default:
        std::cout << "Obrigado por usar a Steam!\n";
        break;
    }
} 
