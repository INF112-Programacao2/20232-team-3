#include "Game.hpp"

Game::Game(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string gender, std::string platform, std::string language): 
Product(name, studio, ageRating, price, availability, review, releaseDate)  //Chama o construtor da classe base(utilizando polimorfismo e heranca)
{
    _gender = gender;
    _platform = platform;
    _language = language;

}

Game::Game(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string gender, std::string platform, std::string language, std::string os, std::string processor, std::string memory, std::string graphics, int directx, std::string storage): 
Product(name, studio, ageRating, price, availability, review, releaseDate) // Chama o construtor da classe base(utilizando polimorfismo e heranca)
{
    _gender = gender;
    _platform = platform;
    _language = language;
    _os = os;
    _processor = processor;
    _memory = memory;
    _graphics = graphics;
    _directx = directx;
    _storage = storage;

}

Game::~Game() // Destrutor
{

}

std::string Game::get_gender() //Retorna o genero do jogo
{
    return _gender;
}

std::string Game::get_platform() // Retorna a plataforma do jogo
{
    return _platform;
}

std::string Game::get_language()    //Retorna os idiomas do jogo
{
    return _language;
}

std::string Game::get_os()  //Retorna o sistema operacional
{
    return _os;
}

std::string Game::get_processor()   //Retorna o processador
{
    return _processor;
}

std::string Game::get_memory()  //Retorna a memoria
{
    return _memory;
}

std::string Game::get_graphics()    //Retorna a placa de video
{
    return _graphics;
}

int Game::get_directx()     //Retorna o DirectX
{
    return _directx;
}

std::string Game::get_storage()     //Retorna o armazenamento
{
    return _storage;
}

void Game::set_gender(std::string gender)   // Define o genero do jogo
{
    _gender = gender;
}

void Game::set_platform(std::string platform)      // Define a plataforma do jogo
{
    _platform = platform;
}

void Game::set_language(std::string language)   // Define os idiomas do jogo
{
    _language = language;
}

void Game::set_os(std::string os)   // Define o sistema operacional
{
    _os = os;
}

void Game::set_processor(std::string processor)    // Define o processador
{
    _processor = processor;
}

void Game::set_memory(std::string memory)   // Define a memoria
{
    _memory = memory;
}

void Game::set_graphics(std::string graphics)   // Define a placa de video
{
    _graphics = graphics;
}

void Game::set_directx(int directx)    // Define o DirectX
{
    _directx = directx;
}

void Game::set_storage(std::string storage)   // Define o armazenamento
{
    _storage = storage;
}

