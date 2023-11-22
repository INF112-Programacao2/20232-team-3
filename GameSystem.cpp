#include <iostream>
#include <string>
#include <vector>
#include "ctype.h"
#include "Product.hpp"
#include "Game.hpp"
#include "GameSystem.hpp"

std::vector<Game*> GameSystem::games;    // Vetor de jogos

int GameSystem::numberOfGames = 0;    // Número de jogos

void GameSystem::gameMenu(){
    int opcao;
    while(true){
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - Add Game" << std::endl;
        std::cout << "2 - Remove Game" << std::endl;
        std::cout << "3 - Change Game" << std::endl;
        std::cout << "4 - Search Game" << std::endl;
        std::cout << "5 - Back" << std::endl;
        std::cin >> opcao;
        switch(opcao){
            case 1:
                GameSystem::addGame();
                break;
            case 2:
                GameSystem::removeGame();
                break;
            case 3:
                GameSystem::changeGame();
                break;
            case 4:
                GameSystem::searchGame();
                break;
            case 5:
                return;
        }
    }
}

void GameSystem::addGame() {
    std::string name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;
    bool gameExists;

    std::cout << "Enter the name of the game: ";

    while (true) {
        gameExists = false;
        name = GameSystem::verifyName();
        std::cin.ignore();

        for (int i = 0; i < games.size(); i++) {
            if (games[i]->get_name() == name) {
                std::cout << "Game already exists. Please try again: ";
                gameExists = true;
                break;
            }
        }

        if (!gameExists) {
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
            std::cout << "Enter the release date: ";
            releaseDate = GameSystem::verifyReleaseDate();
            std::cout << "Enter the gender: ";
            gender = GameSystem::verifyName();
            std::cout << "Enter the platform: ";
            platform = GameSystem::verifyName();
            std::cout << "Enter the language: ";
            language = GameSystem::verifyName();

            if (platform != "PC") {
                Game* game = new Game(name, studio, ageRating, price, availability, review, releaseDate, gender, platform, language);
                games.push_back(game);
                numberOfGames++;
                std::cout << "Game added successfully!" << std::endl;
            } else {
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


void GameSystem::removeGame(){

}

void GameSystem::changeGame(){

}

void GameSystem::searchGame(){

}

// Verificações
std::string GameSystem::verifyName(){
    std::string name;
    while (true){
        std::getline(std::cin, name);
        std::cin.ignore();
        bool validName = true;
        for(char c : name) {
            if(!std::isalpha(c) && c != ' '){
                validName = false;
                break;
            }
        }
        if(validName && std::isupper(name[0])){
            break;
        } 
        else{
            //std::cout << "Invalid name. Please try again: " << std::endl;
            break;
        }
    }
    return name;
}

std::string GameSystem::verifyAgeRating() {
    std::string ageRating;

    while (true) {
        std::getline(std::cin, ageRating);
        std::cin.ignore();

        bool validAgeRating = true;

        for (char c : ageRating) {
            if (!std::isalpha(c) && !std::isdigit(c) && c != '+') {
                validAgeRating = false;
                break;
            }
        }

        if (validAgeRating) {
            break;  // Sair do loop apenas se a classificação etária for válida
        } else {
            std::cout << "Invalid age rating. Please try again: ";
        }
    }

    return ageRating;
}

std::string GameSystem::verifyPrice() {
    std::string price;
    while (true) {
        std::getline(std::cin, price);
        std::cin.ignore();
        bool validPrice = true;
        for (char c : price) {
            if (!std::isdigit(c) && c != '.') {
                validPrice = false;
                break;
            }
        }
        if (validPrice) {
            break;  // Sair do loop apenas se o preço for válido
        }
        else {
            std::cout << "Invalid price. Please try again: ";
        }
    }

    return price;
}

std::string GameSystem::verifyAvailability() {
    std::string availability;

    while (true) {
        std::getline(std::cin, availability);
        std::cin.ignore();

        bool validAvailability = true;

        // Comparação sem diferenciar maiúsculas de minúsculas
        if (availability != "Available" && availability != "Unavailable") {
            validAvailability = false;
        }

        if (validAvailability) {
            break;  // Sair do loop apenas se a disponibilidade for válida
        } else {
            std::cout << "Invalid availability. Please enter 'Available' or 'Unavailable': ";
        }
    }

    return availability;
}



std::string GameSystem::verifyReview(){    // Verifica se a avaliacão é válida
    std::string review;
    std::cout << "Enter the review: ";
    while(true){
        std::getline(std::cin, review);
        std::cin.ignore();
        bool validReview = true;
        for(char c : review){
            if(!std::isalpha(c) && !std::isdigit(c) && c != ',' && c != '.'){    // Se a avaliacão não for composta apenas por letras e os símbolos ',' e '.', a avaliacão é inválida
                validReview = false;    
                break;
            }
        }
        if(validReview && std::isupper(review[0])){    // Se a avaliacão for válida e a primeira letra for maiúscula, a avaliacão é válida
            break;
        }
        else{
            std::cout << "Invalid review. Please try again: ";
        }
    }
    return review;
}

std::string GameSystem::verifyReleaseDate(){    // Verifica se a data de lancamento é válida
    std::string releaseDate;
    while(true){
        std::getline(std::cin, releaseDate);
        std::cin.ignore();
        bool validReleaseDate = true;
        for(char c : releaseDate){
            if(!std::isdigit(c) && c != '/'){    // Se a data de lancamento não for composta apenas por números e o símbolo '/', a data de lancamento é inválida
                validReleaseDate = false;    
                break;
            }
        }
        if(validReleaseDate){    // Se a data de lancamento for válida
            break;
        }
        else{
            std::cout << "Invalid release date. Please try again: ";
        }
    }
    return releaseDate;
}


