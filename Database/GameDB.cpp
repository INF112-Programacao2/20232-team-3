#include "GameDB.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

void change_gameValue(std::string key, std::string value, std::string gameName)
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
            std::cout << "    Nome: " << data["Name"] << std::endl;
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
            std::cout << "Gênero: " << data["Gender"] << std::endl;
            for(auto review : data["Review"])
                std::cout << "Review: " << review << std::endl;

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
    std::cout << "1 - Nome\n2 - Plataforma\n3 - Preço\n4 - Disponibilidade\n5 - Estúdio\n6 - Data de lançamento\n7 - Processador\n8 - Memória\n9 - Armazenamento\n10 - Placa de vídeo\n11 - DirectX\n12 - Sistema operacional\n13 - Idioma\n14 - Classificação indicativa\n15 - Gênero\n16 - Sair\n";
    int aux;
    std::string aux2;
    double aux3;
    std::cin >> aux;

    switch (aux)
    {
    case 1: // Editar nome
        std::cout << "Digite o novo nome: ";
        std::cin >> aux2;
        change_gameValue("Name", aux2, game->get_name());
        game->set_name(aux2);
        break;
    case 2: // Editar plataforma
        std::cout << "Digite a nova plataforma: ";
        std::cin >> aux2;
        change_gameValue("Platform", aux2, game->get_name());
        game->set_platform(aux2);
        break;
    case 3: // Editar preço
        while (true)
        {
            std::cout << "Digite o novo preço: ";
            std::cin >> aux3;
            if(aux3 >= 0) break;
            else std::cout << "Preço inválido, tente novamente" << std::endl;
        }
        //data["Price"] = aux3;
        game->set_price(aux3);
        break;
    case 4: // Editar disponibilidade
        std::cout << "O produto está disponível? (1 - Sim, 0 - Não): ";
        std::cin >> aux;
        //if(aux == 0)
            //data["Availability"] = 0;
        //else
            //data["Availability"] = 1;
        game->set_availability((bool)aux);
        break;
    case 5: // Editar estúdio
        std::cout << "Digite o novo estúdio: ";
        std::cin >> aux2;
        change_gameValue("Studio", aux2, game->get_name());
        game->set_studio(aux2);
        break;
    case 6: // Editar data de lançamento
        std::cout << "Digite a nova data de lançamento: ";
        std::cin >> aux2;
        change_gameValue("Release Date", aux2, game->get_name());
        game->set_releaseDate(aux2);
        break;
    case 7: // Editar processador
        std::cout << "Digite o novo processador: ";
        std::cin >> aux2;
        change_gameValue("Processor", aux2, game->get_name());
        game->set_processor(aux2);
        break;
    case 8: // Editar memória
        std::cout << "Digite a nova memória: ";
        std::cin >> aux2;
        change_gameValue("Memory", aux2, game->get_name());
        game->set_memory(aux2);
        break;
    case 9: // Editar armazenamento
        std::cout << "Digite o novo armazenamento: ";
        std::cin >> aux2;
        change_gameValue("Storage", aux2, game->get_name());
        game->set_storage(aux2);
        break;
    case 10: // Editar placa de vídeo
        std::cout << "Digite a nova placa de vídeo: ";
        std::cin >> aux2;
        change_gameValue("Graphics", aux2, game->get_name());
        game->set_graphics(aux2);
        break;
    case 11: // Editar DirectX
        std::cout << "Digite o novo DirectX: ";
        std::cin >> aux;
        //data["DirectX"] = aux;
        game->set_directx(aux);
        break;
    case 12: // Editar sistema operacional
        std::cout << "Digite o novo sistema operacional: ";
        std::cin >> aux2;
        change_gameValue("OS", aux2, game->get_name());
        game->set_os(aux2);
        break;
    case 13: // Editar idioma
        std::cout << "Digite o novo idioma: ";
        std::cin >> aux2;
        change_gameValue("Language", aux2, game->get_name());
        game->set_language(aux2);
        break;
    case 14: // Editar classificação indicativa
        std::cout << "Digite a nova classificação indicativa: ";
        std::cin >> aux;
        //data["Age rating"] = aux;
        game->set_age_rating(aux);
        break;
    case 15: // Editar gênero
        std::cout << "Digite o novo gênero: ";
        std::cin >> aux2;
        change_gameValue("Gender", aux2, game->get_name());
        game->set_gender(aux2);
        break;
    default:
        break;
    }
}
