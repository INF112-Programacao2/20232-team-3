#include"Developer.hpp"
#include"../Database/ClientDB.hpp"
#include"../Database/GameDB.hpp"
#include<iostream>

Developer::Developer(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> publishedGames): Client(_username, _password, _email, _cpf, balance, birthdate, 10)
{ 
    _publishedGames = publishedGames;
}

void Developer::print_published_games()
{
    for(int i = 0 ; i < _publishedGames.size() ; i++)
        std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
}

void Developer::menu()
{
    int aux;
    std::cout << "Bem vindo, " << _username << "!\n";
    Game* game;
    Game auxgame("Minecraft", "Mojang", 0, 125, 1, {}, "21/04/2008", "Sandbox", "PC", "Portugues", "Windows 11", "Intel core i3", "4 GB", "Intel graphics", 10, "5 GB");
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
        std::cout << "O que deseja fazer?\n1 - Editar Jogos;\n2 - Publicar um jogo;\n3 - Remover um jogo da loja\n4 - Voltar\n";
        std::cin >> aux;
        switch (aux)
        {
            case 1:
                for(int i = 0 ; i < _publishedGames.size() ; i++)
                    std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
                while (true)
                {
                    std::cout << "Digite o número correspondente ao jogo que deseja editar: ";
                    std::cin >> aux;
                    if(aux >= 1 && aux <= _publishedGames.size()) break;
                    else std::cout << "Número inválido, tente novamente" << std::endl;
                }
                aux--;
                GameDB::edit_game(&_publishedGames[aux]); // Função que permite que o usuario veja seus jogos e edite eles
                std::cout << _publishedGames[aux].get_name() << "!\n";
                std::cout << "Jogos editados com sucesso!\n";
            break;
            case 2:
                game = GameDB::add_game(); // Função que permite que o usuario publique um jogo
                auxgame = *game;
                delete game;
                std::cout << "Jogo publicado com sucesso!\n";
                _publishedGames.push_back(auxgame);
                std::cout << "Jogo publicado com sucesso!2\n";
            break;
            case 3:
                for(int i = 0 ; i < _publishedGames.size() ; i++)
                    std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
                while (true)
                {
                    std::cout << "Digite o número correspondente ao jogo que deseja remover: ";
                    std::cin >> aux;
                    if(aux >= 1 && aux <= _publishedGames.size()) break;
                    else std::cout << "Número inválido, tente novamente" << std::endl;
                }
                aux--;
                GameDB::delete_game(_publishedGames[aux].get_name()); // Função que permite que o usuario veja seus jogos e edite eles
                _publishedGames.erase(_publishedGames.begin() + aux);
            break;
        }
        goto INIT;
    default:
        break;
    }
}
