#ifndef _GAME_DB_HPP_
#define _GAME_DB_HPP_

#include "../Product/Game.hpp"
#include <string>

class GameDB    // Classe que representa o banco de dados de jogos
{
    public:
        static Game* add_game();    // Função que adiciona um jogo ao banco de dados
        static void edit_game(Game* game);  // Função que permite que o usuario veja seus jogos e edite eles
        static void delete_game(std::string game);  // Função que permite que o usuario veja seus jogos e edite eles
        static void list_games();   // Função que mostra os jogos disponiveis para compra


};

#endif // _GAME_DB_HPP_