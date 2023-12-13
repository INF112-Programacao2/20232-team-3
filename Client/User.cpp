#include"User.hpp"
#include"../Database/ClientDB.hpp"
#include"../Database/GameDB.hpp"
#include "iostream"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

bool checkgame(std::string gameName)    // Função que verifica se o jogo existe no json
{
    std::ifstream arquivo("games.json");    // Abre o arquivo json
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosGamesJSON;    // Cria um objeto json
    arquivo >> dadosGamesJSON;  // Lê o arquivo json
    arquivo.close();    // Fecha o arquivo

    if (dadosGamesJSON.is_array())  // Verifica se o arquivo é um array
    {
        for (auto& data : dadosGamesJSON)   // Percorre o array 
        {
            if (data["Name"] == gameName)   // Verifica se o nome do jogo é igual ao nome do jogo que o usuario digitou 
            {
                return true;    // Retorna true se o jogo existir
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
    return false;
}

void search_game(std::string &game, std::vector<Game> &games){  // Função que procura o jogo no json e adiciona no vetor de jogos
    std::ifstream arquivo("games.json");    // Abre o arquivo json
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;   // Cria um objeto json
    arquivo >> dadosJSON;   // Lê o arquivo json
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array()) { // Verifica se o arquivo é um array
        for (auto& data : dadosJSON) {  // Percorre o array
            std::string gameJSON = data["Name"];    // Pega o nome do jogo no json
            if (gameJSON == game)   // Verifica se o nome do jogo é igual ao nome do jogo que o usuario digitou
            {
                std::string name = data["Name"];    // Pega o nome do jogo no json
                std::string platform = data["Platform"];    // Pega a plataforma do jogo no json
                std::string release_date = data["Release Date"];    // Pega a data de lançamento do jogo no json
                std::string studio = data["Studio"];    // Pega o estúdio do jogo no json
                int age = data["Age Rating"];   // Pega a classificação indicativa do jogo no json
                bool available = data["Availability"].get<int>();   // Pega a disponibilidade do jogo no json
                int directx = data["DirectX"];  // Pega o directx do jogo no json
                double price = data["Price"];   //pega o preço do jogo no json
                std::string gender = data["Gender"];    // Pega o gênero do jogo no json
                std::string graphics =data["Graphics"];   // Pega a placa de vídeo do jogo no json
                std::string language = data["Language"];    // Pega o idioma do jogo no json
                std::string memory = data["Memory"];    // Pega a memória do jogo no json
                std::string os = data["OS"];    // Pega o sistema operacional do jogo no json
                std::string processor = data["Processor"];  // Pega o processador do jogo no json
                std::string storage = data["Storage"];  // Pega o armazenamento do jogo no json
                std::vector <std::string> review;   // Cria um vetor de strings para as avaliações do jogo
                for(auto& rev : data["Review"]) // Percorre o array de avaliações
                {
                    review.push_back(rev);  // Adiciona a avaliação no vetor de avaliações
                }
                // Cria um objeto jogo
                Game jogo(name, studio, age, price, available, review, release_date, gender, platform, language, os, processor, memory, graphics, directx, storage);    
                games.push_back(jogo);  // Adiciona o jogo no vetor de jogos
            }
        }
    }
}
// Constructor    
User::User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, const std::vector<Game> _library, const std::vector<Game> _wishlist): Client(_username, _password, _email, _cpf, balance, birthdate, 1), _library(_library), _wishlist(_wishlist)
{
}

void User::print_wishlist() // Função que printa a lista de desejos do usuario
{
    for(int i = 0 ; i < _wishlist.size() ; i++) // Percorre o vetor de jogos
    {
        std::cout << i+1 << " " << _wishlist[i].get_name() << '\n'; // Printa o nome do jogo
    }
}

void User::print_library()  // Função que printa a biblioteca de jogos do usuario
{
    for(int i = 0 ; i < _library.size() ; i++)  // Percorre o vetor de jogos
    {
        std::cout << i+1 << " " << _library[i].get_name() << '\n';  // Printa o nome do jogo
    }
}

void User::buy_game(std::string gameName, std::string username) // Função que permite que o usuario compre um jogo
{
    if(!checkgame(gameName))    //verifica se o jogo já existe
    {
        std::cout << "Erro: jogo nao encontrado\n";
        return;
    }

    std::ifstream arquivo("clients.json");  // Abre o arquivo json
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosClientsJSON;  // Cria um objeto json
    arquivo >> dadosClientsJSON;    // Lê o arquivo json
    arquivo.close();    // Fecha o arquivo
    if(dadosClientsJSON.is_array()) // Verifica se o arquivo é um array
    {
        for (auto& data : dadosClientsJSON)  // Percorre o array
        {
            if(data["Username"] == username)    // Verifica se o nome de usuario é igual ao nome de usuario que o usuario digitou
            {
                // Remove da wishlist e adiciona em jogos no json
                for (auto it = data["Wishlist"].begin(); it != data["Wishlist"].end(); ++it)    // Percorre a lista de desejos 
                {
                    if (*it == gameName)    // Verifica se o nome do jogo é igual ao nome do jogo que o usuario digitou 
                    {
                        data["Wishlist"].erase(it); // Remove o jogo da lista de desejos
                        data["Jogos"].push_back(gameName);  // Adiciona o jogo na lista de jogos
                        break; // Para remover apenas a primeira ocorrência de "gameName"
                    }
                            
                }
                // remove da wishlist e adiciona na biblioteca no objeto
                for(int i = 0 ; i < _wishlist.size() ; i++) // Percorre o vetor de jogos
                {
                    if(_wishlist[i].get_name() == gameName) // Verifica se o nome do jogo é igual ao nome do jogo que o usuario digitou
                    {
                        _library.push_back(_wishlist[i]);   // Adiciona o jogo na biblioteca
                        _wishlist.erase(_wishlist.begin()+i);   // Remove o jogo da lista de desejos
                        break;
                    }
                }
            }
        }
    }
    std::ofstream arquivoSaida("clients.json");   // Abre o arquivo json
    arquivoSaida << dadosClientsJSON.dump(10);  // Escreve no arquivo json
    arquivoSaida.close();   // Fecha o arquivo
}

void User::add_to_wishlist(std::string gameName, std::string username)  // Função que permite que o usuario adicione um jogo a sua lista de desejos
{
    if(!checkgame(gameName))    // Verifica se o jogo existe
    {
        std::cout << "Erro: jogo nao encontrado\n";
        return;
    }

    std::ifstream arquivo("clients.json");  // Abre o arquivo json
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosClientsJSON;  // Cria um objeto json
    arquivo >> dadosClientsJSON;    // Lê o arquivo json
    arquivo.close();    // Fecha o arquivo

    bool existe = false;

    if(dadosClientsJSON.is_array()) // Verifica se o arquivo é um array
    {
        for (auto& data : dadosClientsJSON) // Percorre o array
        {
            if(data["Username"] == username)    // Verifica se o nome de usuario é igual ao nome de usuario que o usuario digitou
            {
                // Adiciona à wishlist no json
                for (auto it = data["Wishlist"].begin(); it != data["Wishlist"].end(); ++it)    // Percorre a lista de desejos 
                {
                    if (*it == gameName)    // Verifica se o nome do jogo é igual ao nome do jogo que o usuario digitou 
                    {
                        existe = true;
                        std::cout << "Jogo já está na lista de desejos\n";
                        break;
                    } 
                }
                // Adiciona à wishlist no objeto
                if(!existe) 
                {
                    search_game(gameName, _wishlist);   // Procura o jogo no json e adiciona no vetor de jogos
                    data["Wishlist"].push_back(gameName);   // Adiciona o jogo na lista de desejos
                }
            }
        }
    }
    std::ofstream arquivoSaida("clients.json");  // Abre o arquivo json
    arquivoSaida << dadosClientsJSON.dump(10);  // Escreve no arquivo json
    arquivoSaida.close();   // Fecha o arquivo

}

void User::menu()   // Menu do usuario
{
    int aux;
    std::string aux2;
    std::cout << "Bem vindo, " << _username << "!\n";   // Mensagem de boas vindas
    INIT:
    // Menu de opções
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
        std::cout << "Biblioteca:\n";   // printa os jogos da biblioteca
        print_library();
        goto INIT;
        break;
    case 4:
        GameDB::list_games(); // Função que mostra os jogos disponiveis para compra
        std::cout << "O que deseja fazer?\n1 - Comprar jogo;\n2 - Adicionar um jogo à lista de desejos;\n3 - Sair;\n";
        std::cin >> aux;
        switch (aux)
        {
            case 1:
                std::cout << "Digite o nome do jogo que deseja comprar: ";
                std::cin >> aux2;
                buy_game(aux2, _username);  // Função que permite que o usuario compre um jogo
                break;
            case 2:
                std::cout << "Digite o nome do jogo que deseja adicionar à lista de desejos: ";
                std::cin >> aux2;
                add_to_wishlist(aux2, _username);   // Função que permite que o usuario adicione um jogo à lista de desejos
                break;
            default:
                break;
        }
        goto INIT;
    case 5:
        print_wishlist();   // printa os jogos da lista de desejos
        goto INIT;
        break;
    default:
        std::cout << "Obrigado por usar a Steam!\n";    // Mensagem de despedida
        break;
    }
} 
