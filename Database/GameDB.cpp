#include "GameDB.hpp"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;

std::string verifyName() {    // Verifica se o nome é válido
    std::string name;
    while (true) {
        try {
            std::cin >> name;
            if (name.empty()) {
                throw std::invalid_argument("O nome nao pode ser vazio.");
            }
            for (char c : name) {    // Verifica se o nome contém apenas letras, números e espaços
                if (!std::isalnum(c) && c != ' ') {
                    throw std::invalid_argument("O nome deve ter apenas letras, numeros e espacos.");
                }
            }
            if (!std::isupper(name[0]) && !std::isdigit(name[0])) {    // Verifica se o nome começa com uma letra maiúscula ou um número
                throw std::invalid_argument("O nome deve comecar com letra maiuscula ou numero.");
            }

            if(name.size() > 50){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("O nome deve ter no maximo 50 caracteres.");
            }
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return name;
}

std::string verifyStudio() {    // Verifica se o nome é válido
    std::string studio;
    while (true) {
        try {
            std::cin >> studio;
            for (char c : studio) {    // Verifica se o nome contém apenas letras, números e espaços
                if (!std::isalnum(c) && c != ' ') {
                    throw std::invalid_argument("The studio must contain only letters, numbers, and spaces.");
                }
            }
            if (!std::isupper(studio[0])) {    // Verifica se o nome começa com uma letra maiúscula
                throw std::invalid_argument("The studio must start with a capital letter or a number.");
            }
        
            if(studio.size() > 30){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("The studio must have a maximum of 30 characters.");
            }
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return studio;
}

int verifyAgeRating(){
    int ageRating;
    while(true){
        try{
            bool validAgeRating = true;
            std::cin >> ageRating;
            if(ageRating > 18 || ageRating < 0){    // Verifica se a classificação etária é válida
                validAgeRating = false;
                throw std::invalid_argument("The age rating must be between 0 and 18.");
            }
            if(validAgeRating){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return ageRating;
}

double verifyPrice() {
    std::string price;
    while (true){
        try{
            std::cin >> price;
            bool validPrice = true;
            for(char c : price) {
                if(!std::isdigit(c) && c != '.'){
                    validPrice = false;
                    throw std::invalid_argument("The price must contain only numbers and '.'");
                }
            }
            if(price.size() > 6){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("The price must have a maximum of 10 characters.");
            }
            if(validPrice){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return std::stod(price);
}

int verifyAvailability() {    // Verifica se a disponibilidade é válida
    int availability;
    while (true) {
        try {
            bool validAvailability = true;
            std::cin >> availability;
            if (availability != 0 && availability != 1) {
                validAvailability = false;
                throw std::invalid_argument("Availability must be 0 or 1.");
            }
            if(validAvailability){
                break;
            }
        } catch (const std::exception& e) {    // Caso a disponibilidade não seja válida, pede para tentar novamente
            std::cerr << e.what() << " Please try again: ";
            //std::cin.clear(); // Limpa o estado de erro
            //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
        }
    }
    return availability == 0 ? 0 : 1;
}

std::string verifyDate()
{    // Verifica se a data de lançamento é válida
    int day, month, year;
    while (true){
        try{
            std::cout << "Day: ";
            std::cin >> day;
            std::cout << "Month: ";
            std::cin >> month;
            std::cout << "Year: ";
            std::cin >> year;
            if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1951){    // Verifica se a data é válida
                throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 31, the month must be between 1 and 12 and the year must be between 1951 and the current year.");
            }
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){    // Verifica se o ano é bissexto
                if (month == 2 && day > 29) {    // Verifica se o dia é válido para o mês de fevereiro em um ano bissexto
                    throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 29.");
                }
            }
            else{
                if (month == 2 && day > 28) {    // Verifica se o dia é válido para o mês de fevereiro
                    throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 28.");
                }
            }
            if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){    // Verifica se o dia é válido para os meses de 30 dias
                throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 30.");
            }
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){    // Verifica se o dia é válido para os meses de 31 dias
                throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 31.");
            }
            break;
        }catch(const std::exception& e){    // Caso a data não seja válida, pede para tentar novamente
            std::cerr << " Please try again." << std::endl;
        }
    }
    std::string strday = std::to_string(day), strmonth = std::to_string(month), stryear = std::to_string(year);
    if(strday.size() == 1) strday = "0" + strday;
    if(strmonth.size() == 1) strmonth = "0" + strmonth;
    if(stryear.size() == 1) stryear = "0" + stryear;
    std::string releaseDate = strday + '/' + strmonth + '/' + stryear;
    return releaseDate;
}

int verify_num()
{
    int num;
    while (true)
    {
        try
        {
            std::cin >> num;
            if (num < 0)
            {
                throw std::invalid_argument("O número deve ser positivo.");
            }
            break;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return num;

}

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

void change_gameValue(std::string key, double value, std::string gameName)
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

void change_gameValue(std::string key, int value, std::string gameName)
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
        change_gameValue("Price", aux3, game->get_name());
        game->set_price(aux3);
        break;
    case 4: // Editar disponibilidade
        std::cout << "O produto está disponível? (1 - Sim, 0 - Não): ";
        std::cin >> aux;
        if(aux == 0)
            change_gameValue("Availability", 0, game->get_name());
        else
            change_gameValue("Availability", 1, game->get_name());
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
        change_gameValue("DirectX", aux, game->get_name());
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
        change_gameValue("Age rating", aux, game->get_name());
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

Game* GameDB::add_game() 
{
    std::string name, studio, releaseDate, gender, plataform, language, os, processor, memory, graphics, storage;
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
        std::cout << "Digite o nome do jogo: ";
        name = verifyName();
        std::cout << "Digite o estúdio do jogo: ";
        studio = verifyStudio();
        std::cout << "Digite a classificação indicativa do jogo: ";
        ageRating = verifyAgeRating();
        std::cout << "Digite o preço do jogo: ";
        price = verifyPrice();
        std::cout << "O jogo está disponível? (1 - Sim, 0 - Não): ";
        availability = verifyAvailability();
        // review = {}
        std::cout << "Digite a data de lançamento do jogo: \n";
        releaseDate = verifyDate();
        std::cout << "Digite o gênero do jogo: ";
        gender = verifyName();
        std::cout << "Digite a plataforma do jogo: ";
        plataform = verifyName();
        std::cout << "Digite o idioma do jogo: ";
        language = verifyName();
        std::cout << "Digite o sistema operacional do jogo: ";
        os = verifyName();
        std::cout << "Digite o processador do jogo: ";
        processor = verifyName();
        std::cout << "Digite a memória do jogo: ";
        memory = verifyName();
        std::cout << "Digite a placa de vídeo do jogo: ";
        graphics = verifyName();
        std::cout << "Digite o DirectX do jogo: ";
        directx = verify_num();
        std::cout << "Digite o armazenamento do jogo: ";
        storage = verifyName();

        gameptr = new Game(name, studio, ageRating, price, availability, {}, releaseDate, gender, plataform, language, os, processor, memory, graphics, directx, storage);

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
    novoGame["Gender"] = gameptr->get_gender();
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

    while (true) {

        std::ifstream inputFile("games.json");    // Abre o arquivo JSON
        if (!inputFile.is_open()) {    // Verifica se o arquivo foi aberto corretamente
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

        if (it != dadosJSON.end()) {    // Se o jogo existir, remove
            dadosJSON.erase(it);

            std::ofstream fileout("games.json");
            fileout << dadosJSON.dump(4);  // Ajuste o valor de indentação conforme necessário
            fileout.close();

            std::cout << "Jogo removido com sucesso!" << std::endl;
            gameExists = true;
        }
        else{    // Jogo não encontrado, pede para tentar novamente
            std::cout << "Jogo nao encontrado. Por favor tente novamente: " << std::endl;
        }

        if(gameExists){
            break;
        }
    }
}