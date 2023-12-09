#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <cctype>
<<<<<<< HEAD:Product/GameSystem.cpp
#include "Product.hpp"
#include "Game.hpp"
=======
#include "../Product/Product.hpp"
#include "../Product/Game.hpp"
>>>>>>> bb1e84d68a5dd2868d623552bbeae55891900422:Data_manage/GameSystem.cpp
#include "GameSystem.hpp"

using json = nlohmann::json;

int GameSystem::numberOfGames = 0;    // Número de jogos

// Funções principais
void GameSystem::gameMenu(){    // Menu principal do sistema de jogos
    int opcao;
    while(true){
        std::cout << "O que deseja fazer?" << std::endl;
        std::cout << "1 - Adicionar jogo" << std::endl;
        std::cout << "2 - Remover jogo" << std::endl;
        std::cout << "3 - Alterar jogo" << std::endl;
        std::cout << "4 - Buscar jogo" << std::endl;
        std::cout << "5 - Voltar" << std::endl;
        std::cin >> opcao;
        std::cin.ignore();
        switch(opcao){
            case 1:
                GameSystem::addGame();    // Adiciona um jogo
                break;
            case 2:
                GameSystem::removeGame();    // Remove um jogo
                break;
            case 3:
                GameSystem::changeGame();    // Altera um jogo
                break;
            case 4:
                GameSystem::searchGame();    // Procura um jogo
                break;
            case 5:    // Voltar
                return;
        }
    }
}

void GameSystem::addGame(){    // Adiciona um jogo
    std::string nameFile = "games.json";
    std::string name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;

    std::ifstream inputFile(nameFile);

    if(!inputFile.is_open()){
        std::cerr << "Erro ao abrir o arquivo json" << std::endl;
        return;
    }

    json dadosJSON;
    inputFile >> dadosJSON;
    inputFile.close();
    std::cout << "Digite o nome do jogo: ";
    name = GameSystem::verifyName();
    
    auto it = std::find_if(dadosJSON.begin(), dadosJSON.end(), [&](const auto& data) {    // Verifica se o jogo já existe
        return data["Name"] == name;
    });

    if(it != dadosJSON.end()){    // Se o jogo já existir, não adiciona
        std::cout << "Esse jogo ja existe!" << std::endl;
        return;

    }
    else{    // Jogo não existe, crie um novo jogo
        std::cout << "Digite o nome do studio: ";
        studio = GameSystem::verifyStudio();
        std::cout << "Digite a classificação etaria: ";
        ageRating = GameSystem::verifyAgeRating();
        std::cout << "Digite o preco: ";
        price = GameSystem::verifyPrice();
        std::cout << "Digite a disponibilidade: ";
        availability = GameSystem::verifyAvailability();
        std::cout << "Digite o review: ";
        review = GameSystem::verifyReview();
        std::cout << "Digite o dia, mes e ano do lancamento: " << std::endl;
        releaseDate = GameSystem::verifyReleaseDate();
        std::cout << "Digite o genero: ";
        gender = GameSystem::verifyName();
        std::cout << "Digite a plataforma: ";
        platform = GameSystem::verifyName();
        std::cout << "Digite o idioma: ";
        language = GameSystem::verifyName();
 
        if(platform != "PC"){    // Se a plataforma for diferente de PC, não pede as informações de PC
            json newGame;    // Cria um novo jogo
            // Adiciona as informações do jogo
            newGame["Name"] = name;
            newGame["Studio"] = studio;
            newGame["Age Rating"] = ageRating;
            newGame["Price"] = price;
            newGame["Availability"] = availability;
            newGame["Review"] = review;
            newGame["Release Date"] = releaseDate;
            newGame["Gender"] = gender;
            newGame["Platform"] = platform;
            newGame["Language"] = language;

            dadosJSON.push_back(newGame);
            std::ofstream fileout(nameFile);    // Abre o arquivo JSON
            fileout << dadosJSON.dump(10);  // Use o valor apropriado para a formatação desejada
            fileout.close();
            std::cout << "Jogo adicionado com sucesso!" << std::endl;
            numberOfGames++;
        }
        else{    // Se a plataforma for PC, pede as informações de PC
            std::cout << "Digite o sistema operacional: ";
            os = GameSystem::verifyName();
            std::cout << "Digite o processador: ";
            processor = GameSystem::verifyName();
            std::cout << "Digite o tamanho da memoria: ";
            memory = GameSystem::verifyName();
            std::cout << "Digite a placa de video: ";
            graphics = GameSystem::verifyName();
            std::cout << "Digite o directx: ";
            directx = GameSystem::verifyName();
            std::cout << "Digite o tamanho do armazenamento: ";
            storage = GameSystem::verifyName();

            json newGame;
            // Adiciona as informações do jogo
            newGame["Name"] = name;
            newGame["Studio"] = studio;
            newGame["Age Rating"] = ageRating;
            newGame["Price"] = price;
            newGame["Availability"] = availability;
            newGame["Review"] = review;
            newGame["Release Date"] = releaseDate;
            newGame["Gender"] = gender;
            newGame["Platform"] = platform;
            newGame["Language"] = language;
            newGame["OS"] = os;
            newGame["Processor"] = processor;
            newGame["Memory"] = memory;
            newGame["Graphics"] = graphics;
            newGame["DirectX"] = directx;
            newGame["Storage"] = storage;

            dadosJSON.push_back(newGame);
            std::ofstream fileout(nameFile);    // Abre o arquivo JSON
            fileout << dadosJSON.dump(16);
            fileout.close();
            std::cout << "Jogo adicionado com sucesso!" << std::endl;
            numberOfGames++;
        }
    }
}

void GameSystem::removeGame(){    // Remove um jogo
    std::string name;
    bool gameExists = false;
    std::cout << "Digite o nome do jogo que deseja remover: ";

    while (true) {
        name = GameSystem::verifyName();

        std::ifstream inputFile("games.json");    // Abre o arquivo JSON
        if (!inputFile.is_open()) {    // Verifica se o arquivo foi aberto corretamente
            std::cerr << "Erro ao abrir o arquivo json" << std::endl;
            return;
        }

        json dadosJSON;    // Cria um vetor JSON
        inputFile >> dadosJSON;    // Lê o arquivo JSON
        inputFile.close();    // Fecha o arquivo

        auto it = std::find_if(dadosJSON.begin(), dadosJSON.end(), [&](const json& game) {    // Verifica se o jogo existe
            return game["Name"] == name;
        });

        if (it != dadosJSON.end()) {    // Se o jogo existir, remove
            dadosJSON.erase(it);
            numberOfGames--;

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

void GameSystem::changeGame(){    // Altera um jogo
    std::string name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;
    bool gameExists = false;

    while(true){
        std::cout << "Enter the name of the game you want to change: ";
        name = GameSystem::verifyName();

        std::ifstream inputFile("games.json");    // Abre o arquivo JSON
        if(!inputFile.is_open()){    // Verifica se o arquivo foi aberto corretamente
            std::cerr << "Error opening json file" << std::endl;
            return;
        }

        json dadosJSON;    // Cria um vetor JSON
        inputFile >> dadosJSON;    // Lê o arquivo JSON
        inputFile.close();

        for(auto& game : dadosJSON){    // Procura o jogo no vetor JSON
            if (game["Name"] == name){    // Se o jogo existir, altera as informações
                gameExists = true;
                // Apenas o preço e a disponibilidade podem ser alterados
                std::cout << "Enter the new price: ";
                price = GameSystem::verifyPrice();
                game["Price"] = price;

                std::cout << "Enter the new availability ('Available' or 'Unavailable'): ";
                availability = GameSystem::verifyAvailability();
                game["Availability"] = availability;

                std::ofstream fileout("games.json");
                fileout << dadosJSON.dump(4);  // Ajuste o valor de indentação conforme necessário
                fileout.close();

                std::cout << "Game changed successfully!" << std::endl;
            }
        }
        if(!gameExists){    // Jogo não encontrado, pede para tentar novamente
            std::cout << "Game not found. Please try again: " << std::endl;
        }
        else{
            break;
        }
    }
}

void GameSystem::searchGame(){    // Procura um jogo
    std::string name;
    std::cout << "Enter the name of the game you want to search: ";

    while (true) {
        bool gameExists = false;

        name = GameSystem::verifyName();
        if (!std::isupper(name[0]) && !std::isdigit(name[0])) {    // Verifica se o nome começa com uma letra maiúscula ou um número
            std::cout << "The name must start with a capital letter or a number. Please try again:" << std::endl;
            continue;
        }

        std::ifstream inputFile("games.json");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening json file" << std::endl;
            return;
        }

        json dadosJSON;
        inputFile >> dadosJSON;
        inputFile.close();

        for (const auto& game : dadosJSON) {    // Procura o jogo no vetor JSON
            if (game["Name"] == name) {    // Se o jogo existir, imprime as informações
                gameExists = true;
                std::cout << "Name: " << game["Name"] << std::endl;
                std::cout << "Studio: " << game["Studio"] << std::endl;
                std::cout << "Age Rating: " << game["Age Rating"] << std::endl;
                std::cout << "Price: " << game["Price"] << std::endl;
                std::cout << "Availability: " << game["Availability"] << std::endl;
                std::cout << "Review: " << game["Review"] << std::endl;
                std::cout << "Release date: " << game["Release Date"] << std::endl;
                std::cout << "Gender: " << game["Gender"] << std::endl;
                std::cout << "Platform: " << game["Platform"] << std::endl;
                std::cout << "Language: " << game["Language"] << std::endl;

                if (game["Platform"] == "PC") {
                    std::cout << "OS: " << game["OS"] << std::endl;
                    std::cout << "Processor: " << game["Processor"] << std::endl;
                    std::cout << "Memory: " << game["Memory"] << std::endl;
                    std::cout << "Graphics: " << game["Graphics"] << std::endl;
                    std::cout << "DirectX: " << game["DirectX"] << std::endl;
                    std::cout << "Storage: " << game["Storage"] << std::endl;
                }
            }
        }
        if (!gameExists) {
            std::cout << "Game not found. Please try again: ";
        } else {
            break;
        }
    }
    std::cout << std::endl;
}

// Verificações
// A função verifyName() é usada para verificar o nome, a plataforma, o idioma, o sistema operacional, o processador, a memória, a placa de vídeo, o DirectX e o armazenamento
std::string GameSystem::verifyName() {    // Verifica se o nome é válido
    std::string name;
    while (true) {
        try {
            std::getline(std::cin, name);
            for (char c : name) {    // Verifica se o nome contém apenas letras, números e espaços
                if (!std::isalnum(c) && c != ' ') {
                    throw std::invalid_argument("The name must contain only letters, numbers, and spaces.");
                }
            }
            if (!std::isupper(name[0]) && !std::isdigit(name[0])) {    // Verifica se o nome começa com uma letra maiúscula ou um número
                throw std::invalid_argument("The name must start with a capital letter or a number.");
            }
        
            if(name.size() > 50){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("The name must have a maximum of 50 characters.");
            }
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return name;
}

std::string GameSystem::verifyStudio() {    // Verifica se o nome é válido
    std::string name;
    while (true) {
        try {
            std::getline(std::cin, name);
            for (char c : name) {    // Verifica se o nome contém apenas letras, números e espaços
                if (!std::isalnum(c) && c != ' ') {
                    throw std::invalid_argument("The name must contain only letters, numbers, and spaces.");
                }
            }
            if (!std::isupper(name[0])) {    // Verifica se o nome começa com uma letra maiúscula
                throw std::invalid_argument("The name must start with a capital letter or a number.");
            }
        
            if(name.size() > 30){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("The name must have a maximum of 30 characters.");
            }
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return name;
}

std::string GameSystem::verifyAgeRating(){
    std::string ageRating;
    while(true){
        try{
            bool validAgeRating = true;
            std::getline(std::cin, ageRating);
            if(ageRating != "L" && ageRating != "10" && ageRating != "12" && ageRating != "14" && ageRating != "16" && ageRating != "18"){    // Verifica se a classificação etária é válida
                validAgeRating = false;
                throw std::invalid_argument("The age rating must be 'L', '10', '12', '14', '16' or '18'.");
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

std::string GameSystem::verifyPrice() {
    std::string price;
    while (true){
        try{
            std::getline(std::cin, price);
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
    return price;
}

std::string GameSystem::verifyAvailability() {    // Verifica se a disponibilidade é válida
    std::string availability;
    while (true) {
        try {
            bool validAvailability = true;
            std::getline(std::cin, availability);
            if (availability != "Available" && availability != "Unavailable") {
                validAvailability = false;
                throw std::invalid_argument("Availability must be 'Available' or 'Unavailable'.");
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
    return availability;
}

std::string GameSystem::verifyReview() {    // Verifica se a avaliação é válida
    std::string review;
    while (true) {
        try{
            std::getline(std::cin, review);
            bool validReview = true;
            for(char c : review) {
                if(!std::isalnum(c) && std::islower(review[0]) && c != '.'){
                    validReview = false;
                    throw std::invalid_argument("The review must contain only numbers and '.'");
                }
            }
            if(review.size() > 50){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("The name must have a maximum of 50 characters.");
            }
            if(validReview){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return review;
}

std::string GameSystem::verifyReleaseDate(){    // Verifica se a data de lançamento é válida
    int day, month, year;
    while (true){
        try{
            std::cout << "Day: ";
            std::cin >> day;
            std::cout << "Month: ";
            std::cin >> month;
            std::cout << "Year: ";
            std::cin >> year;
            std::cin.ignore();
            if(std::cin.fail()){
                // Se a entrada não for um número válido, limpe o buffer e solicite a entrada novamente
                std::cin.clear();    // Limpar o buffer de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignorar o restante da linha
                throw std::invalid_argument("Invalid input. Please enter numeric values.");
            }
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

        // Limpar o buffer de entrada para evitar loops infinitos
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::string releaseDate = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
    return releaseDate;
}
