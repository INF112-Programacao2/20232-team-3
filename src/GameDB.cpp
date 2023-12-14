#include "../include/GameDB.hpp"
#include "../include/Input.hpp"

#include <fstream>
#include <iostream>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

void change_gameValue(std::string key, std::string value, std::string gameName) // Função auxiliar para alterar um valor string de um jogo no arquivo JSON
{
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())            // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;   // Cria um vetor JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o vetor JSON é um array
    {
        for (auto& data : dadosJSON)    // Percorre o vetor JSON
        {
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (data["Name"] == gameName)   // verifica se o nome do jogo é igual ao nome do jogo que queremos alterar
            {
                data[key] = value;  // Altera o valor da chave
                std::ofstream arquivoSaida("data/games.json");   // Abre o arquivo JSON
                arquivoSaida << dadosJSON.dump(16);  // Ajuste o valor de indentação conforme necessário
                arquivoSaida.close();   // Fecha o arquivo
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
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())       // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;  // Cria um vetor JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o vetor JSON é um array
    {
        for (auto& data : dadosJSON)    // Percorre o vetor JSON
        {
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (data["Name"] == gameName)   // verifica se o nome do jogo é igual ao nome do jogo que queremos alterar
            {
                data[key] = value;  // Altera o valor da chave
                std::ofstream arquivoSaida("data/games.json");   // Abre o arquivo JSON
                arquivoSaida << dadosJSON.dump(16); // Ajuste o valor de indentação conforme necessário
                arquivoSaida.close();   // Fecha o arquivo
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
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())     // verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;  // Cria um vetor JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   //verifica se o tipo json é um array
    {
        for (auto& data : dadosJSON)    // Percorre o vetor JSON
        {
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (data["Name"] == gameName)   // verifica se o nome do jogo é igual ao nome do jogo que queremos alterar
            {
                data[key] = value;  // Altera o valor da chave
                std::ofstream arquivoSaida("data/games.json");   // Abre o arquivo JSON
                arquivoSaida << dadosJSON.dump(16); // Ajuste o valor de indentação conforme necessário
                arquivoSaida.close();   // Fecha o arquivo
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void GameDB::list_games()   // Função que lista os jogos cadastrados
{
    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;  // Cria um vetor JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o vetor JSON é um array
    {
        for (auto& data : dadosJSON)    // Percorre o vetor JSON
        {
            std::cout << "  Nome: " << data["Name"] << std::endl;   // Imprime o nome do jogo
            std::cout << "Plataforma: " << data["Platform"] << std::endl;   // Imprime a plataforma do jogo
            std::cout << "Preço: " << data["Price"] << std::endl;   // Imprime o preço do jogo  
            std::cout << "Disponivel? ";    // Imprime se o jogo está disponível ou não
            if((int)data["Availability"]) std::cout << "Sim" << std::endl;  // imprime sim se o jogo estiver disponível
            else std::cout << "Não" << std::endl;   // imprime não se o jogo não estiver disponível
            std::cout << "Estúdio: " << data["Studio"] << std::endl;    // Imprime o estúdio do jogo
            std::cout << "Data de lançamento: " << data["Release Date"] << std::endl;   // Imprime a data de lançamento do jogo
            std::cout << "Processador: " << data["Processor"] << std::endl; // Imprime o processador do jogo
            std::cout << "Memória: " << data["Memory"] << std::endl;    // Imprime a memória do jogo
            std::cout << "Armazenamento: " << data["Storage"] << std::endl;     // Imprime o armazenamento do jogo
            std::cout << "Placa de vídeo: " << data["Graphics"] << std::endl;   // Imprime a placa de vídeo do jogo
            std::cout << "DirectX: " << data["DirectX"] << std::endl;   // Imprime o DirectX do jogo
            std::cout << "Sistema operacional: " << data["OS"] << std::endl;    // Imprime o sistema operacional do jogo
            std::cout << "Idioma: " << data["Language"] << std::endl;   // Imprime o idioma do jogo
            std::cout << "Classificação indicativa: " << data["Age rating"] << std::endl;   // Imprime a classificação indicativa do jogo
            std::cout << "Gênero: " << data["Genre"] << std::endl;  // Imprime o gênero do jogo
            for(auto review : data["Review"])   // Percorre o vetor de reviews do jogo
                std::cout << "Review: " << review << std::endl;     // Imprime a review
            std::cout << std::endl;

        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void GameDB::edit_game(Game* game)  // Função que permite que o usuario veja seus jogos e edite eles
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
        aux2 = Input::input_name("Digite o novo nome: ");   // Recebe o novo nome
        change_gameValue("Name", aux2, game->get_name());   // Altera o nome do jogo no arquivo JSON
        game->set_name(aux2);   // Altera o nome do jogo no objeto
        break;
    case 2: // Editar plataforma
        aux2 = Input::input_name("Digite a nova plataforma: "); // Recebe a nova plataforma
        change_gameValue("Platform", aux2, game->get_name());   // Altera a plataforma do jogo no arquivo JSON
        game->set_platform(aux2);   // Altera a plataforma do jogo no objeto
        break;
    case 3: // Editar preço
        while (true)
        {
            aux3 = Input::input_double("Digite o novo preço: ");    // Recebe o novo preço
            if(aux3 >= 0) break;    // Verifica se o preço é válido
            else std::cout << "Preço inválido, tente novamente" << std::endl;
        }
        change_gameValue("Price", aux3, game->get_name());  // Altera o preço do jogo no arquivo JSON
        game->set_price(aux3);  // Altera o preço do jogo no objeto
        break;
    case 4: // Editar disponibilidade
        aux = Input::input_bool("O jogo está disponível? (1 - Sim, 0 - Não): ");
        if(aux == 0)
            change_gameValue("Availability", 0, game->get_name());  // Altera a disponibilidade do jogo no arquivo JSON
        else
            change_gameValue("Availability", 1, game->get_name());  // Altera a disponibilidade do jogo no arquivo JSON
        game->set_availability((bool)aux);  // Altera a disponibilidade do jogo no objeto
        break;
    case 5: // Editar estúdio
        aux2 = Input::input_name("Digite o novo estúdio: ");    // Recebe o novo estúdio
        change_gameValue("Studio", aux2, game->get_name());  // Altera o estúdio do jogo no arquivo JSON
        game->set_studio(aux2); // Altera o estúdio do jogo no objeto
        break;
    case 6: // Editar data de lançamento
        aux2 = Input::input_date("Digite a nova data de lançamento: ");   // Recebe a nova data de lançamento
        change_gameValue("Release Date", aux2, game->get_name());   // Altera a data de lançamento do jogo no arquivo JSON
        game->set_releaseDate(aux2);    // Altera a data de lançamento do jogo no objeto
        break;
    case 7: // Editar processador
        aux2 = Input::input_name("Digite o novo processador: ");    // Recebe o novo processador
        change_gameValue("Processor", aux2, game->get_name());  // Altera o processador do jogo no arquivo JSON
        game->set_processor(aux2);  // Altera o processador do jogo no objeto
        break;
    case 8: // Editar memória
        aux2 = Input::input_name("Digite a nova memória: ");    // Recebe a nova memória
        change_gameValue("Memory", aux2, game->get_name()); // Altera a memória do jogo no arquivo JSON
        game->set_memory(aux2); // Altera a memória do jogo no objeto
        break;
    case 9: // Editar armazenamento
        aux2 = Input::input_name("Digite o novo armazenamento: ");  // Recebe o novo armazenamento
        change_gameValue("Storage", aux2, game->get_name());    // Altera o armazenamento do jogo no arquivo JSON
        game->set_storage(aux2);    // Altera o armazenamento do jogo no objeto
        break;
    case 10: // Editar placa de vídeo
        aux2 = Input::input_name("Digite a nova placa de vídeo: "); // Recebe a nova placa de vídeo
        change_gameValue("Graphics", aux2, game->get_name());   // Altera a placa de vídeo do jogo no arquivo JSON
        game->set_graphics(aux2);   // Altera a placa de vídeo do jogo no objeto
        break;
    case 11: // Editar DirectX
        aux = Input::input_int("Digite o novo DirectX: ", 0, 12);   // Recebe o novo DirectX
        change_gameValue("DirectX", aux, game->get_name()); // Altera o DirectX do jogo no arquivo JSON
        game->set_directx(aux); // Altera o DirectX do jogo no objeto
        break;
    case 12: // Editar sistema operacional
        aux2 = Input::input_name("Digite o novo sistema operacional: ");    // Recebe o novo sistema operacional
        change_gameValue("OS", aux2, game->get_name()); // Altera o sistema operacional do jogo no arquivo JSON
        game->set_os(aux2); // Altera o sistema operacional do jogo no objeto
        break;
    case 13: // Editar idioma
        aux2 = Input::input_name("Digite o novo idioma: ");     // Recebe o novo idioma
        change_gameValue("Language", aux2, game->get_name());   // Altera o idioma do jogo no arquivo JSON
        game->set_language(aux2);   // Altera o idioma do jogo no objeto
        break;
    case 14: // Editar classificação indicativa
        aux = Input::input_int("Digite a nova classificação indicativa: ", 0, 18);  // Recebe a nova classificação indicativa
        change_gameValue("Age rating", aux, game->get_name());  // Altera a classificação indicativa do jogo no arquivo JSON
        game->set_age_rating(aux);  // Altera a classificação indicativa do jogo no objeto
        break;
    case 15: // Editar gênero
        aux2 = Input::input_name("Digite o novo gênero: ");    // Recebe o novo gênero
        change_gameValue("Genre", aux2, game->get_name());   // Altera o gênero do jogo no arquivo JSON
        game->set_genre(aux2);  // Altera o gênero do jogo no objeto
        break;
    default:
        break;
    }
}

Game* GameDB::add_game()    // Função que permite que o usuario publique um jogo
{
    std::string name, studio, releaseDate, genre, plataform, language, os, processor, memory, graphics, storage;
    int ageRating, directx;
    double price;
    bool availability;

    Game* gameptr;  // Ponteiro para um objeto da classe Game

    std::ifstream arquivo("data/games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um vetor JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    while (true)
    {
        name = Input::input_name("Digite o nome do jogo: ");    // Recebe o nome do jogo
        studio = Input::input_name("Digite o estúdio do jogo: ");   // Recebe o estúdio do jogo
        ageRating = Input::input_int("Digite a classificação indicativa do jogo: ", 0, 18);  // Recebe a classificação indicativa do jogo
        price = Input::input_double("Digite o preço do jogo: ");    // Recebe o preço do jogo
        availability = Input::input_bool("O jogo está disponível? (1 - Sim, 0 - Não): ");   // Recebe a disponibilidade do jogo
        releaseDate = Input::input_date("Digite a data de lançamento do jogo: ");   // Recebe a data de lançamento do jogo
        genre = Input::input_name("Digite o gênero do jogo: ");   // Recebe o gênero do jogo
        plataform = Input::input_name("Digite a plataforma do jogo: ");  // Recebe a plataforma do jogo
        language = Input::input_name("Digite o idioma do jogo: ");  // Recebe o idioma do jogo
        os = Input::input_name("Digite o sistema operacional do jogo: ");   // Recebe o sistema operacional do jogo
        processor = Input::input_name("Digite o processador do jogo: ");    // Recebe o processador do jogo
        memory = Input::input_name("Digite a memória do jogo: ");   // Recebe a memória do jogo
        graphics = Input::input_name("Digite a placa de vídeo do jogo: ");  // Recebe a placa de vídeo do jogo
        directx = Input::input_int("Digite o DirectX do jogo: ", 0, 12);    // Recebe o DirectX do jogo
        storage = Input::input_name("Digite o armazenamento do jogo: ");    // Recebe o armazenamento do jogo

        // Cria um objeto da classe Game
        gameptr = new Game(name, studio, ageRating, price, availability, {}, releaseDate, genre, plataform, language, os, processor, memory, graphics, directx, storage);

        if (dadosJSON.is_array())       // Verifica se o vetor JSON é um array
        {
            for (const auto& data : dadosJSON)  // Percorre o vetor JSON 
            {
                if (data["Name"] == gameptr->get_name())    // Verifica se o jogo já está cadastrado
                {
                    std::cout << "Jogo já cadastrado." << std::endl;
                    delete gameptr; // Deleta o objeto
                    continue;
                }
            }
        }
        break;
    }
    


    json novoGame;  // Cria um vetor JSON
    novoGame["Name"] = gameptr->get_name(); // Adiciona o nome do jogo ao vetor JSON
    novoGame["Platform"] = gameptr->get_platform(); // Adiciona a plataforma do jogo ao vetor JSON
    novoGame["Release Date"] = gameptr->get_releaseDate();  // Adiciona a data de lançamento do jogo ao vetor JSON
    novoGame["Studio"] = gameptr->get_studio(); // Adiciona o estúdio do jogo ao vetor JSON
    novoGame["Age Rating"] = gameptr->get_ageRating();  // Adiciona a classificação indicativa do jogo ao vetor JSON
    novoGame["Availability"] = (int)gameptr->get_availability();    // Adiciona a disponibilidade do jogo ao vetor JSON
    novoGame["DirectX"] = gameptr->get_directx();   // Adiciona o DirectX do jogo ao vetor JSON
    novoGame["Memory"] = gameptr->get_memory(); // Adiciona a memória do jogo ao vetor JSON
    novoGame["Graphics"] = gameptr->get_graphics();     // Adiciona a placa de vídeo do jogo ao vetor JSON
    novoGame["Processor"] = gameptr->get_processor();       // Adiciona o processador do jogo ao vetor JSON   
    novoGame["Storage"] = gameptr->get_storage();   // Adiciona o armazenamento do jogo ao vetor JSON
    novoGame["Price"] = gameptr->get_price();   // Adiciona o preço do jogo ao vetor JSON
    novoGame["Language"] = gameptr->get_language();  // Adiciona o idioma do jogo ao vetor JSON
    novoGame["OS"] = gameptr->get_os(); // Adiciona o sistema operacional do jogo ao vetor JSON
    novoGame["Genre"] = gameptr->get_genre();   // Adiciona o gênero do jogo ao vetor JSON
    novoGame["Review"] = {};    // Adiciona a review do jogo ao vetor JSON

    dadosJSON.push_back(novoGame);  // Adiciona o vetor JSON ao vetor de jogos
    std::ofstream arquivoSaida("data/games.json");   // Abre o arquivo JSON
    arquivoSaida << dadosJSON.dump(16); // Ajuste o valor de indentação conforme necessário
    arquivoSaida.close();   // Fecha o arquivo

    return gameptr;     // Retorna o ponteiro para o objeto da classe Game
}

void GameDB::delete_game(std::string game){   // Função que permite que o usuario remova um jogo
    std::string name = game;
    bool gameExists = false;

    while (true) 
    {

        std::ifstream inputFile("data/games.json");    // Abre o arquivo JSON
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

            std::ofstream fileout("data/games.json");
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