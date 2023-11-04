#include <iostream>
#include <string>
#include "Games.h"

// Constructor
// Console
Games::Games(std::string name, std::string studio, int ageRating, float price, std::string availability, int reviews, std::string gender, std::string platform, std::string languages, std::string releaseDate) : 
    Products(name, studio, ageRating, price, availability, reviews), _gender(gender), _platform(platform), _languages(languages), _releaseDate(releaseDate)
{

}

// Destructor
Games::~Games() 
{

}

// Methods
// Getters
std::string Games::get_gender() {    //Retorna o genero do jogo
	return _gender;
}

std::string Games::get_platform() {    //Retorna a plataforma do jogo
	return _platform;
}

std::string Games::get_languages() {    //Retorna os idiomas do jogo
	return _languages;
}

std::string Games::get_releaseDate() {    //Retorna a data de lancamento do jogo
	return _releaseDate;
}
// Setters
void Games::set_gender(std::string gender){    //Altera o genero do jogo
	_gender = gender;
}

void Games::set_platform(std::string platform){    //Altera a plataforma do jogo
	_platform = platform;
}

void Games::set_languages(std::string languages){    //Altera os idiomas do jogo
	_languages = languages;
}

void Games::set_releaseDate(std::string releaseDate){    //Altera a data de lancamento do jogo
	_releaseDate = releaseDate;
}