#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "Product.hpp"
#include "Game.hpp"

class GameSystem{
    private:
        static int numberOfGames;    // Número de jogos
    public:
        // Funções principais do menu
        static void gameMenu();    // Menu de jogos
        static void addGame();    // Adiciona um jogo
        static void removeGame();    // Remove um jogo
        static void changeGame();    // Altera um jogo
        static void searchGame();    // Procura um jogo
        
        // Funções de verificação
        static std::string verifyName();    // Verifica se o nome é válido
        static std::string verifyStudio();    // Verifica se o nome do studio é válido
        static std::string verifyAgeRating();    // Verifica se a classificacao etaria é válida
        static std::string verifyPrice();    // Verifica se o preco é válido
        static std::string verifyAvailability();    // Verifica se a disponibilidade é válida
        static std::string verifyReview();    // Verifica se a avaliacão é válida
        static std::string verifyReleaseDate();    // Verifica se a data de lancamento é válida
};

#endif    // GAMESYSTEM_HPP_