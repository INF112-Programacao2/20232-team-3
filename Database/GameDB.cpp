#include "GameDB.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

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
    std::cout << "1 - Nome\n2 - Plataforma\n3 - Preço\n4 - Disponibilidade\n5 - Estúdio\n6 - Data de lançamento\n7 - Processador\n8 - Memória\n9 - Armazenamento\n10 - Placa de vídeo\n11 - DirectX\n12 - Sistema operacional\n13 - Idioma\n14 - Classificação indicativa\n15 - Gênero\n";
    int aux;
    std::cin >> aux;
    std::string cat[15] = {"nome", "plataforma", "preco", "disponibilidade", "estudio", "data de lancamento", "processador", "memoria", "armazenamento", "placa de video", "directx", "sistema operacional", "idioma", "classificacao indicativa", "genero"};

    std::cout << "Digite o novo valor para " << cat[aux-1] << ": ";
    std::string new_value;
    std::cin >> new_value;
    if(aux == 2)
    {
        double value = std::stod(new_value);
        if(value < 0)
        {
            std::cout << "Valor inválido" << std::endl;
        }
        else
        {
            game->set_price(value);
            // CONTINUAR AQUI
        }
    }
}
