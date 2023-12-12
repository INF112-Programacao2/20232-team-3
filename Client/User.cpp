#include"User.hpp"
#include"../Database/ClientDB.hpp"
#include"../Database/GameDB.hpp"
#include "iostream"
#include "../Auxiliar/Input.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

bool game_exist(std::string gameName)// Função auxiliar - retorna se um jogo existe em games.json
{
    std::ifstream arquivo("games.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosGamesJSON;
    arquivo >> dadosGamesJSON;
    arquivo.close();

    if (dadosGamesJSON.is_array()) 
    {
        for (auto& data : dadosGamesJSON) 
        {
            if (data["Name"] == gameName) 
            {
                return true;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
    return false;
}

void load_game_from_json(std::string name, std::vector<Game> &games) // Função auxiliar - Busca um game no json e adiciona no vetor de games
{
    std::ifstream arquivo("games.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) 
    {
        for (auto& data : dadosJSON) 
        {
            std::string gameJSON = data["Name"];
            if (gameJSON == name)
            {
                std::string name = data["Name"];
                std::string platform = data["Platform"];
                std::string release_date = data["Release Date"];
                std::string studio = data["Studio"];
                int age = data["Age Rating"];
                bool available = data["Availability"].get<int>();
                int directx = data["DirectX"];
                double price = data["Price"];
                std::string gender = data["Gender"];
                std::string graphics =data["Graphics"];
                std::string language = data["Language"];
                std::string memory = data["Memory"];
                std::string os = data["OS"];
                std::string processor = data["Processor"];
                std::string storage = data["Storage"];
                std::vector <std::string> review;
                for(auto& rev : data["Review"])
                {
                    review.push_back(rev);
                }
                Game jogo(name, studio, age, price, available, review, release_date, gender, platform, language, os, processor, memory, graphics, directx, storage);
                games.push_back(jogo);
            }
        }
    }
}

Game load_game_from_json(std::string &name) // Função auxiliar - Busca um game no json e adiciona no vetor de games
{
    std::ifstream arquivo("games.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) 
    {
        for (auto& data : dadosJSON) 
        {
            std::string gameJSON = data["Name"];
            if (gameJSON == name)
            {
                std::string name = data["Name"];
                std::string platform = data["Platform"];
                std::string release_date = data["Release Date"];
                std::string studio = data["Studio"];
                int age = data["Age Rating"];
                bool available = data["Availability"].get<int>();
                int directx = data["DirectX"];
                double price = data["Price"];
                std::string gender = data["Gender"];
                std::string graphics =data["Graphics"];
                std::string language = data["Language"];
                std::string memory = data["Memory"];
                std::string os = data["OS"];
                std::string processor = data["Processor"];
                std::string storage = data["Storage"];
                std::vector <std::string> review;
                for(auto& rev : data["Review"])
                {
                    review.push_back(rev);
                }
                Game jogo(name, studio, age, price, available, review, release_date, gender, platform, language, os, processor, memory, graphics, directx, storage);
                return jogo;
            }
        }
    }
    return Game();
}

User::User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, const std::vector<Game> _library, const std::vector<Game> _wishlist): Client(_username, _password, _email, _cpf, balance, birthdate, 1), _library(_library), _wishlist(_wishlist)
{
}

void User::print_wishlist()
{
    for(int i = 0 ; i < _wishlist.size() ; i++)
    {
        std::cout << i+1 << " " << _wishlist[i].get_name() << '\n';
    }
}

void User::print_library()
{
    for(int i = 0 ; i < _library.size() ; i++)
    {
        std::cout << i+1 << " " << _library[i].get_name() << '\n';
    }
}

void User::buy_game(Game game, std::string username)
{
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosClientsJSON;
    arquivo >> dadosClientsJSON;
    arquivo.close();
    bool existe = false;

    if(dadosClientsJSON.is_array())
    {
        for (auto& data : dadosClientsJSON)
        {
            if(data["Username"] == username)
            {
                // Adiciona à wishlist no json
                for (auto it = data["Jogos"].begin(); it != data["Jogos"].end(); ++it) 
                {
                    if (*it == game.get_name()) 
                    {
                        existe = true;
                        std::cout << "Jogo já está na biblioteca\n";
                        break;
                    }
                }
                // Adiciona à wishlist no objeto
                if(!existe)
                {
                    load_game_from_json(game.get_name(), _library);
                    data["Jogos"].push_back(game.get_name());
                    _balance -= game.get_price();
                    data["Balance"] = _balance;
                }
            }
        }
    }
    std::ofstream arquivoSaida("clients.json");
    arquivoSaida << dadosClientsJSON.dump(10);
    arquivoSaida.close();
}

void User::add_to_wishlist(std::string gameName, std::string username)
{
    if(!game_exist(gameName))
    {
        std::cout << "Erro: jogo nao encontrado\n";
        return;
    }

    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosClientsJSON;
    arquivo >> dadosClientsJSON;
    arquivo.close();

    bool existe = false;

    if(dadosClientsJSON.is_array())
    {
        for (auto& data : dadosClientsJSON)
        {
            if(data["Username"] == username)
            {
                // Adiciona à wishlist no json
                for (auto it = data["Wishlist"].begin(); it != data["Wishlist"].end(); ++it) 
                {
                    if (*it == gameName) 
                    {
                        existe = true;
                        std::cout << "Jogo já está na lista de desejos\n";
                        break;
                    } 
                }
                // Adiciona à wishlist no objeto
                if(!existe)
                {
                    load_game_from_json(gameName, _wishlist);
                    data["Wishlist"].push_back(gameName);
                }
            }
        }
    }
    std::ofstream arquivoSaida("clients.json");
    arquivoSaida << dadosClientsJSON.dump(10);
    arquivoSaida.close();

}

void User::menu()
{
    int aux;
    Game auxgame;
    std::string aux2;
    std::cout << "Bem vindo, " << _username << "!\n";
    INIT:
    std::cout << "O que deseja fazer?\n1 - Ver/Alterar Dados\n2 - Ver/Adicionar Saldo\n3 - Ver biblioteca\n4 - Loja\n5 - Ver lista de desejos\nAperte qualquer outra tecla para sair\n";
    std::cin >> aux;
    std::cin.ignore();
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
        std::cout << "Biblioteca:\n";
        print_library();
        goto INIT;
        break;
    case 4:
        GameDB::list_games(); // Função que mostra os jogos disponiveis para compra
        std::cout << "O que deseja fazer?\n1 - Comprar jogo;\n2 - Adicionar um jogo à lista de desejos;\nAperte qualquer outra tecla para voltar\n";
        std::cin >> aux;
        std::cin.ignore();
        switch (aux)
        {
            case 1:
                while (true)
                {
                    aux2 = Input::input_name("Digite o nome do jogo que deseja comprar: ");
                    auxgame = load_game_from_json(aux2);
                    std::cout << auxgame.get_price() << '\n';
                    std::cout << _balance << '\n';
                    if(!game_exist(aux2))
                    {
                        std::cout << "Erro: jogo nao encontrado\n";
                    }
                    else if(auxgame.get_price() > _balance)
                    {
                        std::cout << "Erro: saldo insuficiente\n";
                        break;
                    }
                    else
                    {
                        buy_game(auxgame, _username);
                        std::cout << "Jogo comprado com sucesso!\n";
                        break;
                    }
                }
            break;
            case 2:
                std::cout << "Digite o nome do jogo que deseja adicionar à lista de desejos: ";
                std::getline(std::cin, aux2);
                add_to_wishlist(aux2, _username);
                std::cout << "Jogo adicionado à lista de desejos com sucesso!\n";
                break;
            default:
                goto INIT;
            break;
        }
        goto INIT;
    case 5:
        print_wishlist();
        goto INIT;
        break;
    default:
        std::cout << "Obrigado por usar a Steam!\n";
        break;
    }
} 
