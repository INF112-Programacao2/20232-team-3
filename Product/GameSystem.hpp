#ifndef GAMESYSTEM_HPP_
#define GAMESYSTEM_HPP_

#include <vector>
#include <string>
#include "Product.hpp"
#include "Game.hpp"

class GameSystem{
    private:
        static std::vector<Game*> games;    // Vetor de jogos
        static int numberOfGames;    // Número de jogos

    public:
        static void gameMenu();    // Menu de jogos
        static void addGame();    // Adiciona um jogo
        static void removeGame();    // Remove um jogo
        static void changeGame();    // Altera um jogo
        static void searchGame();    // Procura um jogo

        static std::string verifyName();    // Verifica se o nome é válido
        //static std::string verifyStudio();    // Verifica se o nome do studio é válido
        static std::string verifyAgeRating();    // Verifica se a classificacao etaria é válida
        static std::string verifyPrice();    // Verifica se o preco é válido
        static std::string verifyAvailability();    // Verifica se a disponibilidade é válida
        static std::string verifyReview();    // Verifica se a avaliacão é válida
        static std::string verifyReleaseDate();    // Verifica se a data de lancamento é válida
        //static std::string verifyGender();    // Verifica se o genero é válido
        //static std::string verifyPlatform();    // Verifica se a plataforma é válida
        //static std::string verifyLanguage();    // Verifica se os idiomas são válidos
        //static std::string verifyOS();    // Verifica se o sistema operacional é válido
        //static std::string verifyProcessor();    // Verifica se o processador é válido
        //static std::string verifyMemory();    // Verifica se a memoria é válida
        //static std::string verifyGraphics();    // Verifica se a placa de video é válida
        //static std::string verifyDirectx();    // Verifica se o DirectX é válido
        //static std::string verifyStorage();    // Verifica se o armazenamento é válido
};

#endif    // GAMESYSTEM_HPP_