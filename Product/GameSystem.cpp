#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include "ctype.h"
#include "Product.hpp"
#include "Game.hpp"
#include "GameSystem.hpp"

std::vector<Game*> GameSystem::games;    // Vetor de jogos

int GameSystem::numberOfGames = 0;    // Número de jogos

// Funções principais
void GameSystem::gameMenu(){    // Menu principal do sistema de jogos
    int opcao;
    while(true){
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - Add Game" << std::endl;
        std::cout << "2 - Remove Game" << std::endl;
        std::cout << "3 - Change Game" << std::endl;
        std::cout << "4 - Search Game" << std::endl;
        std::cout << "5 - Back" << std::endl;
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
            case 5:
                return;
        }
    }
}

void GameSystem::addGame() {    // Adiciona um jogo
    std::string name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;
    std::cout << "Enter the name of the game: ";

    while (true) {
        bool gameExists = false;
        name = GameSystem::verifyName();
        for (int i = 0; i < games.size(); i++) {    // Verificar se o jogo já existe
            if (games[i]->get_name() == name) {
                std::cout << "Game already exists. Please try again: ";
                gameExists = true;
                break;
            }
        }
        if (!gameExists) {    // Se o jogo não existir adiciona
            std::cout << "Enter the studio: ";
            studio = GameSystem::verifyName();
            std::cout << "Enter the age rating: ";
            ageRating = GameSystem::verifyAgeRating();
            std::cout << "Enter the price: ";
            price = GameSystem::verifyPrice();
            std::cout << "Enter the availability: ";
            availability = GameSystem::verifyName();
            std::cout << "Enter the review: ";
            review = GameSystem::verifyReview();
            std::cout << "Enter the day, month and year of release: " << std::endl;
            releaseDate = GameSystem::verifyReleaseDate();
            std::cout << "Enter the gender: ";
            gender = GameSystem::verifyGender();
            std::cout << "Enter the platform: ";
            platform = GameSystem::verifyName();
            std::cout << "Enter the language: ";
            language = GameSystem::verifyName();
            if (platform != "PC") {    // Se a plataforma for diferente de PC, não pede as informações de PC
                Game* game = new Game(name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language);
                games.push_back(game);
                numberOfGames++;
                std::cout << "Game added successfully!" << std::endl;
            }
            else {    // Se a plataforma for PC, pede as informações de PC
                std::cout << "Enter the OS: ";
                os = GameSystem::verifyName();
                std::cout << "Enter the processor: ";
                processor = GameSystem::verifyName();
                std::cout << "Enter the memory: ";
                memory = GameSystem::verifyName();
                std::cout << "Enter the graphics: ";
                graphics = GameSystem::verifyName();
                std::cout << "Enter the DirectX: ";
                directx = GameSystem::verifyName();
                std::cout << "Enter the storage: ";
                storage = GameSystem::verifyName();

                Game* game = new Game(name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage);
                games.push_back(game);
                numberOfGames++;
                std::cout << "Game added successfully!" << std::endl;
            }
            break;  // Encerrar o loop após adicionar o jogo com sucesso
        }
    }
}

void GameSystem::removeGame(){    // Remove um jogo
    std::string name;
    bool gameExists = false;
    while(true){    // Verifica se o jogo existe
        std::cout << "Enter the name of the game you want to remove: ";
        name = GameSystem::verifyName();
        std::cin.ignore();
        for(int i = 0; i < games.size(); i++){    // Se o jogo existir, remove
            if(games[i]->get_name() == name){
                games.erase(games.begin() + i);    // Apaga o jogo do vetor
                numberOfGames--;
                std::cout << "Game removed successfully!" << std::endl;
                gameExists = true;
                break;
            }
        }
        if(!gameExists){    // Se o jogo não existir, pede para tentar novamente
            std::cout << "Game not found. Please try again: " << std::endl;
        }
        else{
            break;
        }
    }
}

void GameSystem::changeGame(){    // Altera um jogo
    std::string name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;
    bool gameExists = false;
    while(true){
        std::getline(std::cin, name);
        std::cin.ignore();
        name = GameSystem::verifyName();
        for(int i = 0; i < games.size(); i++){
            if(games[i]->get_name() == name){
                gameExists = true;
                // Apenas o preço e a disponibilidade podem ser alterados
                name = games[i]->get_name();
                studio = games[i]->get_studio();
                ageRating = games[i]->get_ageRating();
                price = GameSystem::verifyPrice();
                availability = GameSystem::verifyAvailability();
                review = games[i]->get_review();
                releaseDate = games[i]->get_releaseDate();
                gender = games[i]->get_gender();
                platform = games[i]->get_platform();
                language = games[i]->get_language();
                if(platform != "PC"){
                    Game* game = new Game(name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language);    // Cria um novo jogo com as informações alteradas
                    //delete games[i];
                    games[i] = game;    // Substitui o jogo antigo pelo novo
                    std::cout << "Game changed successfully!" << std::endl;
                }
                else{
                    os = games[i]->get_os();
                    processor = games[i]->get_processor();
                    memory = games[i]->get_memory();
                    graphics = games[i]->get_graphics();
                    directx = games[i]->get_directx();
                    storage = games[i]->get_storage();

                    Game* game = new Game(name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage);
                    //delete games[i];
                    games[i] = game;
                    std::cout << "Game changed successfully!" << std::endl;
                }
            }
        }
        if(!gameExists){
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
    while(true){
        bool gameExists = false;
        name = GameSystem::verifyName();
        std::cin.ignore();
        for(int i = 0; i < games.size(); i++){
            if(games[i]->get_name() == name && games[i]->get_platform() != "PC"){
                std::cout << "Name: " << games[i]->get_name() << std::endl;
                std::cout << "Studio: " << games[i]->get_studio() << std::endl;
                std::cout << "Age Rating: " << games[i]->get_ageRating() << std::endl;
                std::cout << "Price: " << games[i]->get_price() << std::endl;
                std::cout << "Availability: " << games[i]->get_availability() << std::endl;
                std::cout << "Review: " << games[i]->get_review() << std::endl;
                std::cout << "Release date: " << games[i]->get_releaseDate() << std::endl;
                std::cout << "Gender: " << games[i]->get_gender() << std::endl;
                std::cout << "Platform: " << games[i]->get_platform() << std::endl;
                std::cout << "Language: " << games[i]->get_language() << std::endl;
                gameExists = true;
            }
            else if(games[i]->get_name() == name && games[i]->get_platform() == "PC"){
                std::cout << "Name: " << games[i]->get_name() << std::endl;
                std::cout << "Studio: " << games[i]->get_studio() << std::endl;
                std::cout << "Age Rating: " << games[i]->get_ageRating() << std::endl;
                std::cout << "Price: " << games[i]->get_price() << std::endl;
                std::cout << "Availability: " << games[i]->get_availability() << std::endl;
                std::cout << "Review: " << games[i]->get_review() << std::endl;
                std::cout << "Release date: " << games[i]->get_releaseDate() << std::endl;
                std::cout << "Gender: " << games[i]->get_gender() << std::endl;
                std::cout << "Platform: " << games[i]->get_platform() << std::endl;
                std::cout << "Language: " << games[i]->get_language() << std::endl;
                std::cout << "OS: " << games[i]->get_os() << std::endl;
                std::cout << "Processor: " << games[i]->get_processor() << std::endl;
                std::cout << "Memory: " << games[i]->get_memory() << std::endl;
                std::cout << "Graphics: " << games[i]->get_graphics() << std::endl;
                std::cout << "DirectX: " << games[i]->get_directx() << std::endl;
                std::cout << "Storage: " << games[i]->get_storage() << std::endl;
                gameExists = true;
            }
        }
        if(!gameExists){
            std::cout << "Game not found. Please try again: " << std::endl;
        }
        else{
            break;
        }
    }
}

// Verificações
// A função verifyName() é usada para verificar o nome, o studio, a disponibilidade, a plataforma, o idioma, o sistema operacional, o processador, a memória, a placa de vídeo, o DirectX e o armazenamento
std::string GameSystem::verifyName() {    // Verifica se o nome é válido
    std::string name;
    while (true) {
        bool validName = true;
        try {
            std::getline(std::cin, name);
            for (char c : name) {
                if (!std::isalpha(c) && !std::isdigit(c) && c != ' ') {
                    validName = false;
                    throw std::runtime_error("The name must contain only letters, numbers, and spaces.");
                }
            }
            if (!std::isupper(name[0]) && !std::isdigit(name[0])) {
                validName = false;
                throw std::runtime_error("The name must start with a capital letter or a number.");
            }
            if (validName) {
                break;
            }
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
            std::getline(std::cin, ageRating);
            bool validAgeRating = true;
            for(char c : ageRating) {
                if(!std::isalpha(c) && !std::isupper(c) && !std::isdigit(c) && c != '+'){
                    validAgeRating = false;
                    throw std::runtime_error("The age rating must contain only capital letters, numbers, and '+'");
                }
            }
            if(validAgeRating){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << " Please try again: ";
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
                if(!std::isdigit(c) && price.size() > 6 && c != '.'){
                    validPrice = false;
                    throw std::runtime_error("The price must contain only numbers, '.' and have a maximum of 6 digits before");
                }
            }
            if(validPrice){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << " Please try again: ";
        }
    }
    return price;
}

std::string GameSystem::verifyAvailability() {
    std::string availability;
    while (true) {
        try{
            std::getline(std::cin, availability);
            bool validAvailability = true;
            if (availability != "Available" && availability != "Unavailable") {
                validAvailability = false;
                throw std::runtime_error("The availability must be 'Available' or 'Unavailable'");
            }

            if (validAvailability) {
                break;  // Sair do loop apenas se a disponibilidade for válida
            }
        }catch (const std::exception& e){
            std::cerr << " Please try again: ";
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
                    throw std::runtime_error("The review must contain only numbers and '.'");
                }
            }
            if(validReview){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << " Please try again: ";
        }
    }
    return review;
}

std::string GameSystem::verifyReleaseDate(){
    int day, month, year;
    while (true){
        try{
            std::cout << "Enter the day: ";
            std::cin >> day;
            std::cout << "Enter the month: ";
            std::cin >> month;
            std::cout << "Enter the year: ";
            std::cin >> year;
            if(std::cin.fail()){
                // Se a entrada não for um número válido, limpe o buffer e solicite a entrada novamente
                std::cin.clear();    // Limpar o buffer de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignorar o restante da linha
                throw std::runtime_error("Invalid input. Please enter numeric values.");
            }
            if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1951){    // Verifica se a data é válida
                throw std::runtime_error("Invalid date");
            }
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){    // Verifica se o ano é bissexto
                if (month == 2 && day > 29) {    // Verifica se o dia é válido para o mês de fevereiro em um ano bissexto
                    throw std::runtime_error("Invalid date");
                }
            }
            else{
                if (month == 2 && day > 28) {    // Verifica se o dia é válido para o mês de fevereiro
                    throw std::runtime_error("Invalid date");
                }
            }
            if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){    // Verifica se o dia é válido para os meses de 30 dias
                throw std::runtime_error("Invalid date");
            }
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){    // Verifica se o dia é válido para os meses de 31 dias
                throw std::runtime_error("Invalid date");
            }
            break;
        }catch(const std::exception& e){    // Caso a data não seja válida, pede para tentar novamente
            std::cerr << " Please try again." << std::endl;
        }

        // Limpar o buffer de entrada para evitar loops infinitos
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::string releaseDate = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
    return releaseDate;
}

std::string GameSystem::verifyGender(){
    std::string gender;
    while(true){
        bool validGender;
        try{
            std::getline(std::cin, gender);
            for(char c : gender){
                if(!std::isalpha(c)){
                    validGender = false;
                    throw std::runtime_error("The name must contain only letters");
                }
            }
            if (!std::isupper(gender[0])) {
                validGender = false;
                throw std::runtime_error("The name must start with a capital letter.");
            }
            if(validGender){
                break;
            }
        }catch (const std::exception& e) {
            std::cerr << e.what() << " Please try again: ";
        }
    }
    return gender;
}