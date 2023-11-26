#include <iostream>
#include <string>
#include "Game.hpp"
#include "Product.hpp"

// Console Constructor
Game::Game(std::string name, std::string studio, std::string ageRating, std::string price, std::string availability, std::string review, std::string releaseDate, std::string gender, std::string platform, std::string language) : 
    Product(name, studio, ageRating, price, availability, review, releaseDate), _gender(gender), _platform(platform), _language(language)
{
}

// PC Constructor
Game::Game(std::string name, std::string studio, std::string ageRating, std::string price, std::string availability, std::string review, std::string releaseDate, std::string gender, std::string platform, std::string language, std::string os, std::string processor, std::string memory, std::string graphics, std::string directx, std::string storage) : 
    Product(name, studio, ageRating, price, availability, review, releaseDate), _gender(gender), _platform(platform), _language(language), _os(os), _processor(processor), _memory(memory), _graphics(graphics), _directx(directx), _storage(storage)
{
}

// Destructor
Game::~Game() 
{
}

// Getters
std::string Game::get_gender() {    //Retorna o genero do jogo
	return _gender;
}

std::string Game::get_platform() {    //Retorna a plataforma do jogo
	return _platform;
}

std::string Game::get_language() {    //Retorna os idiomas do jogo
	return _language;
}

std::string Game::get_os() {    //Retorna o sistema operacional
	return _os;
}

std::string Game::get_processor() {    //Retorna o processador
	return _processor;
}

std::string Game::get_memory() {    //Retorna a memoria
	return _memory;
}

std::string Game::get_graphics() {    //Retorna a placa de video
	return _graphics;
}

std::string Game::get_directx() {    //Retorna o DirectX
	return _directx;
}

std::string Game::get_storage() {    //Retorna o armazenamento
	return _storage;
}