#include"Developer.hpp"
#include"../Database/ClientDB.hpp"
#include<iostream>

//class ClientDB;

Developer::Developer(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance): Client(_username, _password, _email, _cpf, balance, 10)
{ 
    //_publishedGames = publishedGames;
}

void Developer::menu()
{
    int aux;
    std::cout << "Bem vindo, " << _username << "!\n";
    INIT:
    std::cout << "O que deseja fazer?\n1 - Ver/Alterar Dados;\n2 - Ver/Resgatar Saldo;\n3 - Ver/Editar jogos;\n4 - Sair\n";
    std::cin >> aux;
    switch (aux)
    {
    case 1:
        ClientDB::edit_info(this);
        std::cout << "Dados alterados com sucesso!\n";
        goto INIT;
        break;
    case 2:
        ClientDB::redeem_balance(this); // Função que permite que o usuario veja seu saldo atual e resgate um valor
        std::cout << "Valores resgatados com sucesso!\n";
        goto INIT;
        break;
    case 3:
        //for(int i = 0 ; i < _publishedGames.size() ; i++)
            //std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
        //ClientDB::edit_games(this); // Função que permite que o usuario veja seus jogos e edite eles
        //std::cout << "O que deseja fazer?\n1 - Publicar novo jogo;\n2 - Remover jogo;\n3 - Editar jogo;\n";
        std::cout << "Jogos editados com sucesso!\n";
        goto INIT;
    default:
        break;
    }
}