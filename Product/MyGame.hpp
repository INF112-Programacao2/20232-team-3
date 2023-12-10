#ifndef MY_GAME_HPP
#define MY_GAME_HPP
#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>

class MyGame
{
private:
    std::string gamecopy_name;
    std::string gamecopy_username;
    Game _gamecopy;
public:
    MyGame();
    ~MyGame();
    void add_game(Game game);
    void remove_game(Game game);
    void show_my_games();
};

#endif // MY_GAME_HPP
