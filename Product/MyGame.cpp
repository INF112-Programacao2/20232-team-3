#include "MyGame.hpp"

MyGame::MyGame()
{
}

MyGame::~MyGame()
{
}

void MyGame::add_game(Game game)
{
    _my_games.push_back(game);
}

void MyGame::remove_game(Game game)
{
    for (int i = 0; i < _my_games.size(); i++)
    {
        if (_my_games[i].get_name() == game.get_name())
        {
            _my_games.erase(_my_games.begin() + i);
            break;
        }
    }
}

void MyGame::show_my_games(){
    std::cout << "My Games:" << std::endl;
    for (auto e : _my_games)
    {
        std::cout << "Name: " << e.get_name() << std::endl;
        std::cout << "Studio: " << e.get_studio() << std::endl;
    }
    
}