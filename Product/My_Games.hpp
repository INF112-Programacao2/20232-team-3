#ifndef MY_GAMES_HPP
#define MY_GAMES_HPP
#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>

class My_Games
{
private:
    std::vector<Game> _my_games;
public:
    My_Games();
    ~My_Games();
    void add_game(Game game);
    void remove_game(Game game);
    void show_my_games();
};

#endif // MY_GAMES_HPP
