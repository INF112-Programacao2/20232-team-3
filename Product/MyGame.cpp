#include "MyGame.hpp"

MyGame::MyGame()
{
    username da pessoa e nome do jogo
}

MyGame::~MyGame()
{
}

void MyGame::add_game(Game game)
{
    
}

void MyGame::remove_game(Game game)
{
    
}

void MyGame::show_my_games(){
    std::cout << "Name: " << this->_gamecopy->get_name() << std::endl << "Studio: " << this->_gamecopy->get_studio() << std::endl 
    << "Age rating: " << this->_gamecopy->get_ageRating() << std::endl << "Release Date: " << this->_gamecopy->get_releaseDate() << std::endl 
    << "Reviews: " << this->_gamecopy->get_review() << std::endl;   
}