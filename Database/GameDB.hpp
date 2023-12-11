#ifndef _GAME_DB_HPP_
#define _GAME_DB_HPP_

#include "../Product/Game.hpp"

#include <string>

class GameDB
{
private:
    
public:
    static Game* add_game();
    static void edit_game(Game* game);
    static void delete_game(std::string game);
    static void list_games();


};

#endif // _GAME_DB_HPP_