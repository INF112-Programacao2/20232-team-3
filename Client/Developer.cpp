#include"Developer.hpp"
#include"../Auxiliar/Input.hpp"
#include"../Database/ClientDB.hpp"
#include"../Database/GameDB.hpp"
#include<iostream>

// Construtor
Developer::Developer(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> publishedGames): Client(_username, _password, _email, _cpf, balance, birthdate, 10)
{ 
    _publishedGames = publishedGames;
}

void Developer::print_published_games()  // Imprime os jogos publicados pelo desenvolvedor
{
    for(int i = 0 ; i < _publishedGames.size() ; i++)
        std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
}

void Developer::menu()  // Menu do desenvolvedor
{
    int aux;
    Game auxgame("Minecraft", "Mojang", 0, 125, 1, {}, "21/04/2008", "Sandbox", "PC", "Portugues", "Windows 11", "Intel core i3", "4 GB", "Intel graphics", 10, "5 GB");
    Game* auxgameptr;

    std::cout << "Bem vindo, " << _username << "!\n";
    INIT:
    std::cout << "O que deseja fazer?\n1 - Ver/Alterar Dados;\n2 - Ver/Resgatar Saldo;\n3 - Ver/Editar jogos;\nAperte qualquer outra tecla para sair.\n";
    std::cin >> aux;
    std::cin.ignore();

    switch (aux)
    {
    case 1:
        ClientDB::edit_info(this);  // Função que permite que o usuario veja seus dados e edite eles
        std::cout << "Dados alterados com sucesso!\n";
        goto INIT;
    break;
    case 2:
        ClientDB::redeem_balance(this); // Função que permite que o usuario veja seu saldo atual e resgate um valor
        std::cout << "Valores resgatados com sucesso!\n";
        goto INIT;
        break;
    case 3:
        std::cout << "O que deseja fazer?\n1 - Editar Jogos;\n2 - Publicar um jogo;\n3 - Remover um jogo da loja\nAperte qualquer outra tecla para sair voltar.\n";
        std::cin >> aux;
        std::cin.ignore();
        switch (aux)
        {
            case 1:
                for(int i = 0 ; i < _publishedGames.size() ; i++)   // Imprime os jogos publicados pelo desenvolvedor
                    std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
                aux = Input::input_int("Digite o número correspondente ao jogo que deseja editar: ", 1, _publishedGames.size());
                aux--;
                GameDB::edit_game(&_publishedGames[aux]); // Função que permite que o usuario veja seus jogos e edite eles
                std::cout << _publishedGames[aux].get_name() << "!\n";
                std::cout << "Jogos editados com sucesso!\n";
            break;
            case 2:
                auxgameptr = GameDB::add_game(); // Função que permite que o usuario publique um jogo
                auxgame = *auxgameptr;
                delete auxgameptr;
                std::cout << "Jogo publicado com sucesso!\n";
                ClientDB::add_publication(this, auxgame.get_name());
                _publishedGames.push_back(auxgame); // Adiciona o jogo publicado ao vetor de jogos publicados
            break;
            case 3:
                for(int i = 0 ; i < _publishedGames.size() ; i++)   // Imprime os jogos publicados pelo desenvolvedor
                    std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';
                aux = Input::input_int("Digite o número correspondente ao jogo que deseja remover: ", 1, _publishedGames.size());
                aux--;
                GameDB::delete_game(_publishedGames[aux].get_name()); // Função que permite que o usuario veja seus jogos e edite eles
                _publishedGames.erase(_publishedGames.begin() + aux);   // Remove o jogo publicado do vetor de jogos publicados
            break;
        }
        goto INIT;
    default:
        break;
    }
}
