#ifndef MY_GAME_HPP
#define MY_GAME_HPP
#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>

class MyGame
{
private:
    std::vector<Game> _my_games;
public:
    MyGame();
    ~MyGame();
    void add_game(Game game);
    void remove_game(Game game);
    void show_my_games();
};

#endif // MY_GAME_HPP
