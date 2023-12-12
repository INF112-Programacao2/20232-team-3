#include "GameDB.hpp"
#include "../Auxiliar/Input.hpp"

#include <fstream>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

void change_gameValue(std::string key, std::string value, std::string gameName) // Função auxiliar para alterar um valor string de um jogo no arquivo JSON
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
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (data["Name"] == gameName) 
            {
                data[key] = value;
                std::ofstream arquivoSaida("games.json");
                arquivoSaida << dadosJSON.dump(16);
                arquivoSaida.close();
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void change_gameValue(std::string key, double value, std::string gameName) // Função auxiliar para alterar um valor double de um jogo no arquivo JSON
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
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (data["Name"] == gameName) 
            {
                data[key] = value;
                std::ofstream arquivoSaida("games.json");
                arquivoSaida << dadosJSON.dump(16);
                arquivoSaida.close();
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void change_gameValue(std::string key, int value, std::string gameName) // Função auxiliar para alterar um valor int de um jogo no arquivo JSON
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
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (data["Name"] == gameName) 
            {
                data[key] = value;
                std::ofstream arquivoSaida("games.json");
                arquivoSaida << dadosJSON.dump(16);
                arquivoSaida.close();
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void GameDB::list_games()
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
            std::cout << "  Nome: " << data["Name"] << std::endl;
            std::cout << "Plataforma: " << data["Platform"] << std::endl;
            std::cout << "Preço: " << data["Price"] << std::endl;
            std::cout << "Disponivel? ";
            if((int)data["Availability"]) std::cout << "Sim" << std::endl;
            else std::cout << "Não" << std::endl;
            std::cout << "Estúdio: " << data["Studio"] << std::endl;
            std::cout << "Data de lançamento: " << data["Release Date"] << std::endl;
            std::cout << "Processador: " << data["Processor"] << std::endl;
            std::cout << "Memória: " << data["Memory"] << std::endl;
            std::cout << "Armazenamento: " << data["Storage"] << std::endl;
            std::cout << "Placa de vídeo: " << data["Graphics"] << std::endl;
            std::cout << "DirectX: " << data["DirectX"] << std::endl;
            std::cout << "Sistema operacional: " << data["OS"] << std::endl;
            std::cout << "Idioma: " << data["Language"] << std::endl;
            std::cout << "Classificação indicativa: " << data["Age rating"] << std::endl;
            std::cout << "Gênero: " << data["Genre"] << std::endl;
            for(auto review : data["Review"])
                std::cout << "Review: " << review << std::endl;
            std::cout << std::endl;

        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void GameDB::edit_game(Game* game)
{
    std::cout << "Digite o número correspondente à informação que deseja alterar: \n";
    std::cout << "1 - Nome\n2 - Plataforma\n3 - Preço\n4 - Disponibilidade\n5 - Estúdio\n6 - Data de lançamento\n7 - Processador\n8 - Memória\n9 - Armazenamento\n10 - Placa de vídeo\n11 - DirectX\n12 - Sistema operacional\n13 - Idioma\n14 - Classificação indicativa\n15 - Gênero\nAperte qualquer outra tecla para sair\n";
    int aux;
    std::string aux2;
    double aux3;
    std::cin >> aux;
    std::cin.ignore();

    switch (aux)
    {
    case 1: // Editar nome
        aux2 = Input::input_name("Digite o novo nome: ");
        change_gameValue("Name", aux2, game->get_name());
        game->set_name(aux2);
        break;
    case 2: // Editar plataforma
        aux2 = Input::input_name("Digite a nova plataforma: ");
        change_gameValue("Platform", aux2, game->get_name());
        game->set_platform(aux2);
        break;
    case 3: // Editar preço
        while (true)
        {
            aux3 = Input::input_double("Digite o novo preço: ");
            if(aux3 >= 0) break;
            else std::cout << "Preço inválido, tente novamente" << std::endl;
        }
        change_gameValue("Price", aux3, game->get_name());
        game->set_price(aux3);
        break;
    case 4: // Editar disponibilidade
        aux = Input::input_bool("O jogo está disponível? (1 - Sim, 0 - Não): ");
        if(aux == 0)
            change_gameValue("Availability", 0, game->get_name());
        else
            change_gameValue("Availability", 1, game->get_name());
        game->set_availability((bool)aux);
        break;
    case 5: // Editar estúdio
        aux2 = Input::input_name("Digite o novo estúdio: ");
        change_gameValue("Studio", aux2, game->get_name());
        game->set_studio(aux2);
        break;
    case 6: // Editar data de lançamento
        aux2 = Input::input_date("Digite a nova data de lançamento: ");
        change_gameValue("Release Date", aux2, game->get_name());
        game->set_releaseDate(aux2);
        break;
    case 7: // Editar processador
        aux2 = Input::input_name("Digite o novo processador: ");
        change_gameValue("Processor", aux2, game->get_name());
        game->set_processor(aux2);
        break;
    case 8: // Editar memória
        aux2 = Input::input_name("Digite a nova memória: ");
        change_gameValue("Memory", aux2, game->get_name());
        game->set_memory(aux2);
        break;
    case 9: // Editar armazenamento
        aux2 = Input::input_name("Digite o novo armazenamento: ");
        change_gameValue("Storage", aux2, game->get_name());
        game->set_storage(aux2);
        break;
    case 10: // Editar placa de vídeo
        aux2 = Input::input_name("Digite a nova placa de vídeo: ");
        change_gameValue("Graphics", aux2, game->get_name());
        game->set_graphics(aux2);
        break;
    case 11: // Editar DirectX
        aux = Input::input_int("Digite o novo DirectX: ", 0, 12);
        change_gameValue("DirectX", aux, game->get_name());
        game->set_directx(aux);
        break;
    case 12: // Editar sistema operacional
        aux2 = Input::input_name("Digite o novo sistema operacional: ");
        change_gameValue("OS", aux2, game->get_name());
        game->set_os(aux2);
        break;
    case 13: // Editar idioma
        aux2 = Input::input_name("Digite o novo idioma: ");
        change_gameValue("Language", aux2, game->get_name());
        game->set_language(aux2);
        break;
    case 14: // Editar classificação indicativa
        aux = Input::input_int("Digite a nova classificação indicativa: ", 0, 18);
        change_gameValue("Age rating", aux, game->get_name());
        game->set_age_rating(aux);
        break;
    case 15: // Editar gênero
        aux2 = Input::input_name("Digite o novo gênero: ");
        change_gameValue("Genre", aux2, game->get_name());
        game->set_genre(aux2);
        break;
    default:
        break;
    }
}

Game* GameDB::add_game() 
{
    std::string name, studio, releaseDate, genre, plataform, language, os, processor, memory, graphics, storage;
    int ageRating, directx;
    double price;
    bool availability;

    Game* gameptr;

    std::ifstream arquivo("games.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    while (true)
    {
        name = Input::input_name("Digite o nome do jogo: ");
        studio = Input::input_name("Digite o estúdio do jogo: ");
        ageRating = Input::input_int("Digite a classificação indicativa do jogo: ", 0, 18);
        price = Input::input_double("Digite o preço do jogo: ");
        availability = Input::input_bool("O jogo está disponível? (1 - Sim, 0 - Não): ");
        // review = {}
        releaseDate = Input::input_date("Digite a data de lançamento do jogo: ");
        genre = Input::input_name("Digite o gênero do jogo: ");
        plataform = Input::input_name("Digite a plataforma do jogo: ");
        language = Input::input_name("Digite o idioma do jogo: ");
        os = Input::input_name("Digite o sistema operacional do jogo: ");
        processor = Input::input_name("Digite o processador do jogo: ");
        memory = Input::input_name("Digite a memória do jogo: ");
        graphics = Input::input_name("Digite a placa de vídeo do jogo: ");
        directx = Input::input_int("Digite o DirectX do jogo: ", 0, 12);
        storage = Input::input_name("Digite o armazenamento do jogo: ");

        gameptr = new Game(name, studio, ageRating, price, availability, {}, releaseDate, genre, plataform, language, os, processor, memory, graphics, directx, storage);

        if (dadosJSON.is_array())
        {
            for (const auto& data : dadosJSON) 
            {
                if (data["Name"] == gameptr->get_name()) 
                {
                    std::cout << "Jogo já cadastrado." << std::endl;
                    delete gameptr;
                    continue;
                }
            }
        }
        break;
    }
    


    json novoGame;
    novoGame["Name"] = gameptr->get_name();
    novoGame["Platform"] = gameptr->get_platform();
    novoGame["Release Date"] = gameptr->get_releaseDate();
    novoGame["Studio"] = gameptr->get_studio();
    novoGame["Age Rating"] = gameptr->get_ageRating();
    novoGame["Availability"] = (int)gameptr->get_availability();
    novoGame["DirectX"] = gameptr->get_directx();
    novoGame["Memory"] = gameptr->get_memory();
    novoGame["Graphics"] = gameptr->get_graphics();
    novoGame["Processor"] = gameptr->get_processor();
    novoGame["Storage"] = gameptr->get_storage();
    novoGame["Price"] = gameptr->get_price();
    novoGame["Language"] = gameptr->get_language();
    novoGame["OS"] = gameptr->get_os();
    novoGame["Genre"] = gameptr->get_genre();
    novoGame["Review"] = {};

    dadosJSON.push_back(novoGame);
    std::ofstream arquivoSaida("games.json");
    arquivoSaida << dadosJSON.dump(16);
    arquivoSaida.close();
    //std::cout << "Game cadastrado com sucesso" << std::endl;

    return gameptr;
}

void GameDB::delete_game(std::string game){
    std::string name = game;
    bool gameExists = false;

    while (true) 
    {

        std::ifstream inputFile("games.json");    // Abre o arquivo JSON
        if (!inputFile.is_open()) 
        {    // Verifica se o arquivo foi aberto corretamente
            std::cerr << "Erro ao abrir o arquivo json" << std::endl;
            return;
        }

        json dadosJSON;    // Cria um vetor JSON
        inputFile >> dadosJSON;    // Lê o arquivo JSON
        inputFile.close();    // Fecha o arquivo

        auto it = std::find_if(dadosJSON.begin(), dadosJSON.end(), [&](const json& game) 
        {    // Verifica se o jogo existe
            return game["Name"] == name;
        });

        if (it != dadosJSON.end()) 
        {    // Se o jogo existir, remove
            dadosJSON.erase(it);

            std::ofstream fileout("games.json");
            fileout << dadosJSON.dump(4);  // Ajuste o valor de indentação conforme necessário
            fileout.close();

            std::cout << "Jogo removido com sucesso!" << std::endl;
            gameExists = true;
        }
        else
        {    // Jogo não encontrado, pede para tentar novamente
            std::cout << "Jogo nao encontrado. Por favor tente novamente: " << std::endl;
        }

        if(gameExists)
        {
            break;
        }
    }
}