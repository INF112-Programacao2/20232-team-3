#include <iostream>
#include <string>
#include "Game.hpp"

// Constructor
// Console
Game::Game(std::string name, std::string studio, int ageRating, float price, std::string availability, int reviews, std::string gender, std::string platform, std::string languages, std::string releaseDate) : 
    Product(name, studio, ageRating, price, availability, reviews), _gender(gender), _platform(platform), _languages(languages), _releaseDate(releaseDate)
{

}

// Destructor
Game::~Game() 
{

}

// Methods
// Getters
std::string Game::get_gender() {    //Retorna o genero do jogo
	return _gender;
}

std::string Game::get_platform() {    //Retorna a plataforma do jogo
	return _platform;
}

std::string Game::get_languages() {    //Retorna os idiomas do jogo
	return _languages;
}

std::string Game::get_releaseDate() {    //Retorna a data de lancamento do jogo
	return _releaseDate;
}
// Setters
void Game::set_gender(std::string gender){    //Altera o genero do jogo
	_gender = gender;
}

void Game::set_platform(std::string platform){    //Altera a plataforma do jogo
	_platform = platform;
}

void Game::set_languages(std::string languages){    //Altera os idiomas do jogo
	_languages = languages;
}

void Game::set_releaseDate(std::string releaseDate){    //Altera a data de lancamento do jogo
	_releaseDate = releaseDate;
}