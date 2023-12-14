#include"../include/User.hpp"
#include"../include/ClientDB.hpp"
#include"../include/GameDB.hpp"
#include "../include/Input.hpp"
#include <nlohmann/json.hpp>
#include <iostream>
using json = nlohmann::json;

bool game_exist(std::string gameName)// Função auxiliar - retorna se um jogo existe em data/games.json
{
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open()) // Verifica se o arquivo foi aberto corretamente 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosGamesJSON;    // Cria um objeto json
    arquivo >> dadosGamesJSON;  // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosGamesJSON.is_array())  // Verifica se o arquivo é um array
    {
        for (auto& data : dadosGamesJSON)   // Percorre o array
        {
            if (data["Name"] == gameName)   // Verifica se o nome do jogo é igual ao nome do jogo passado como parâmetro
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
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto json
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o arquivo é um array
    {
        for (auto& data : dadosJSON)    // Percorre o array
        {
            std::string gameJSON = data["Name"];    // Pega o nome do jogo
            if (gameJSON == name)   // Verifica se o nome do jogo é igual ao nome do jogo passado como parâmetro
            {
                std::string name = data["Name"];    // Pega o nome do jogo
                std::string platform = data["Platform"];    // Pega a plataforma do jogo
                std::string release_date = data["Release Date"];    // Pega a data de lançamento do jogo
                std::string studio = data["Studio"];    // Pega o estúdio do jogo
                int age = data["Age Rating"];   // Pega a classificação indicativa do jogo
                bool available = data["Availability"].get<int>();   // Pega a disponibilidade do jogo
                int directx = data["DirectX"];  // Pega o directx do jogo
                double price = data["Price"];   // Pega o preço do jogo
                std::string genre = data["Genre"];  // Pega o gênero do jogo
                std::string graphics =data["Graphics"]; // Pega a placa de vídeo do jogo
                std::string language = data["Language"];    // Pega o idioma do jogo
                std::string memory = data["Memory"];    // Pega a memória do jogo
                std::string os = data["OS"];    // Pega o sistema operacional do jogo
                std::string processor = data["Processor"];  // Pega o processador do jogo
                std::string storage = data["Storage"];  // Pega o armazenamento do jogo
                std::vector <std::string> review;   // Cria um vetor de reviews
                for(auto& rev : data["Review"]) // Percorre o array de reviews
                {
                    review.push_back(rev);  // Adiciona a review no vetor
                }
                // Cria um objeto Game com os dados do jogo
                Game jogo(name, studio, age, price, available, review, release_date, genre, platform, language, os, processor, memory, graphics, directx, storage);
                games.push_back(jogo);  // Adiciona o jogo no vetor de jogos
            }
        }
    }
}

Game load_game_from_json(std::string &name) // Função auxiliar - Busca um game no json e adiciona no vetor de games
{
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())    // Verifica se o arquivo foi aberto corretamente 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto json
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o arquivo é um array
    {
        for (auto& data : dadosJSON) 
        {
            std::string gameJSON = data["Name"];    // Pega o nome do jogo
            if (gameJSON == name)   // Verifica se o nome do jogo é igual ao nome do jogo passado como parâmetro
            {
                std::string name = data["Name"];    // Pega o nome do jogo
                std::string platform = data["Platform"];    // Pega a plataforma do jogo
                std::string release_date = data["Release Date"];    // Pega a data de lançamento do jogo
                std::string studio = data["Studio"];    // Pega o estúdio do jogo
                int age = data["Age Rating"];   // Pega a classificação indicativa do jogo
                bool available = data["Availability"].get<int>();   // Pega a disponibilidade do jogo
                int directx = data["DirectX"];  // Pega o directx do jogo
                double price = data["Price"];   // Pega o preço do jogo
                std::string genre = data["Genre"];  // Pega o gênero do jogo
                std::string graphics =data["Graphics"];     // Pega a placa de vídeo do jogo
                std::string language = data["Language"];    // Pega o idioma do jogo
                std::string memory = data["Memory"];    // Pega a memória do jogo
                std::string os = data["OS"];    // Pega o sistema operacional do jogo
                std::string processor = data["Processor"];  // Pega o processador do jogo
                std::string storage = data["Storage"];  // Pega o armazenamento do jogo
                std::vector <std::string> review;   // Cria um vetor de reviews
                for(auto& rev : data["Review"]) // Percorre o array de reviews
                {
                    review.push_back(rev);  // Adiciona a review no vetor
                }
                // Cria um objeto Game com os dados do jogo
                Game jogo(name, studio, age, price, available, review, release_date, genre, platform, language, os, processor, memory, graphics, directx, storage);
                return jogo;
            }
        }
    }
    return Game();  // Retorna um jogo vazio
}

// Construtor
User::User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, const std::vector<Game> _library, const std::vector<Game> _wishlist): Client(_username, _password, _email, _cpf, balance, birthdate, 1), _library(_library), _wishlist(_wishlist)
{
}

void User::print_wishlist() // Imprime a lista de desejos
{
    for(int i = 0 ; i < _wishlist.size() ; i++) // Percorre o vetor de jogos
    {
        std::cout << i+1 << " " << _wishlist[i].get_name() << '\n';
    }
}

void User::print_library()      // Imprime a biblioteca de jogos
{
    for(int i = 0 ; i < _library.size() ; i++)  // Percorre o vetor de jogos
    {
        std::cout << i+1 << " " << _library[i].get_name() << '\n';
    }
}

void User::buy_game(Game game, std::string username)    // Função que permite que o usuario compre um jogo
{
    std::ifstream arquivo("data/clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }
    if(!game.get_availability())    // Verifica se o jogo está disponível
    {
        int aux = Input::input_int("Jogo indisponivel, deseja adiciona-lo à lista de desejos?\n1 - Sim\n2 - Nao\n", 1, 2);
        if(aux == 1)    // Adiciona o jogo à lista de desejos
        {
            add_to_wishlist(game.get_name(), username); // Adiciona o jogo à lista de desejos
        }
        return;
    }

    json dadosClientsJSON;  // Cria um objeto json
    arquivo >> dadosClientsJSON;    // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo
    bool existe = false;

    if(dadosClientsJSON.is_array()) // Verifica se o arquivo é um array
    {
        for (auto& data : dadosClientsJSON)  // Percorre o array
        {
            if(data["Username"] == username)    // Verifica se o nome de usuario é igual ao nome de usuario passado como parâmetro
            {
                // Adiciona à wishlist no json
                for (auto it = data["Jogos"].begin(); it != data["Jogos"].end(); ++it)  // Percorre o array de jogos 
                {
                    if (*it == game.get_name()) // Verifica se o nome do jogo é igual ao nome do jogo passado como parâmetro 
                    {
                        existe = true;
                        std::cout << "Jogo já está na biblioteca\n";
                        return;
                    }
                }
                // Adiciona à wishlist no objeto
                if(!existe)
                {
                    load_game_from_json(game.get_name(), _library); // Carrega o jogo do json
                    data["Jogos"].push_back(game.get_name());   // Adiciona o jogo no array de jogos
                    _balance -= game.get_price();   // Diminui o saldo do cliente
                    data["Balance"] = _balance; // Atualiza o saldo no json
                }
            }
        }
    }
    std::ofstream arquivoSaida("data/clients.json"); // Abre o arquivo JSON
    arquivoSaida << dadosClientsJSON.dump(10);  // Escreve no arquivo JSON
    arquivoSaida.close();   // Fecha o arquivo
}

void User::add_to_wishlist(std::string gameName, std::string username)  // Adiciona um jogo a lista de desejos
{
    if(!game_exist(gameName))   // Verifica se o jogo existe
    {
        std::cout << "Erro: jogo nao encontrado\n";
        return;
    }

    std::ifstream arquivo("data/clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosClientsJSON;  // Cria um objeto json
    arquivo >> dadosClientsJSON;    // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    bool existe = false;

    if(dadosClientsJSON.is_array()) // Verifica se o arquivo é um array
    {
        for (auto& data : dadosClientsJSON) // Percorre o array
        {
            if(data["Username"] == username)    // Verifica se o nome de usuario é igual ao nome de usuario passado como parâmetro
            {
                // Adiciona à wishlist no json
                for (auto it = data["Wishlist"].begin(); it != data["Wishlist"].end(); ++it)    // Percorre o array de jogos
                {
                    if (*it == gameName)    // Verifica se o nome do jogo é igual ao nome do jogo passado como parâmetro
                    {
                        existe = true;
                        std::cout << "Jogo já está na lista de desejos\n";
                        break;
                    } 
                }
                // Adiciona à wishlist no objeto
                if(!existe)
                {
                    load_game_from_json(gameName, _wishlist);   // Carrega o jogo do json
                    data["Wishlist"].push_back(gameName);   // Adiciona o jogo no array de jogos
                }
            }
        }
    }
    std::ofstream arquivoSaida("data/clients.json"); // Abre o arquivo JSON
    arquivoSaida << dadosClientsJSON.dump(10);  // Escreve no arquivo JSON
    arquivoSaida.close();   // Fecha o arquivo

}

void User::menu()   // Menu do usuário
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
        print_library();    // Função que imprime a biblioteca de jogos
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
                    aux2 = Input::input_name("Digite o nome do jogo que deseja comprar: "); // Função que recebe o nome do jogo
                    auxgame = load_game_from_json(aux2);    // Carrega o jogo do json
                    std::cout << auxgame.get_price() << '\n';   // Imprime o preço do jogo
                    std::cout << _balance << '\n';  // Imprime o saldo do cliente
                    if(!game_exist(aux2))   // Verifica se o jogo existe
                    {
                        std::cout << "Erro: jogo nao encontrado\n";
                    }
                    else if(auxgame.get_price() > _balance) // Verifica se o preço do jogo é maior que o saldo do cliente
                    {
                        std::cout << "Erro: saldo insuficiente\n";
                        break;
                    }
                    else
                    {
                        buy_game(auxgame, _username);   // Função que permite que o usuario compre um jogo
                        std::cout << "Jogo comprado com sucesso!\n";
                        break;
                    }
                }
            break;
            case 2:
                std::cout << "Digite o nome do jogo que deseja adicionar à lista de desejos: ";
                std::getline(std::cin, aux2);   // Recebe o nome do jogo
                add_to_wishlist(aux2, _username);   // Adiciona o jogo à lista de desejos
                std::cout << "Jogo adicionado à lista de desejos com sucesso!\n";
                break;
            default:
                goto INIT;
            break;
        }
        goto INIT;
    case 5:
        print_wishlist();   // Função que imprime a lista de desejos
        goto INIT;
        break;
    default:
        std::cout << "Obrigado por usar a Steam!\n";    // Mensagem de despedida :)
        break;
    }
} 
