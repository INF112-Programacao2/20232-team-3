#ifndef _GAME_DB_HPP_
#define _GAME_DB_HPP_

#include "Game.hpp"
#include <string>

class GameDB
{
    public:
        static Game* add_game();    // Adiciona um jogo
        static void edit_game(Game* game);  // Edita um jogo
        static void delete_game(std::string game);      // Deleta um jogo
        static void list_games();   // Lista os jogos

};

#endif // _GAME_DB_HPP_