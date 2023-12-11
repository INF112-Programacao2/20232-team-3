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
            std::cout << "Review: " << data["Review"] << std::endl;

        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

