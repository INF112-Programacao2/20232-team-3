#include "Game.hpp"

// Chama o construtor da classe base
Game::Game(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string genre, std::string platform, std::string language, std::string os, std::string processor, std::string memory, std::string graphics, int directx, std::string storage): 
Product(name, studio, ageRating, price, availability, review, releaseDate)
{
    _genre = genre;
    _platform = platform;
    _language = language;
    _os = os;
    _processor = processor;
    _memory = memory;
    _graphics = graphics;
    _directx = directx;
    _storage = storage;
}

Game::Game() 
{
}

// Destrutor
Game::~Game() 
{

}

//Retorna o genero do jogo
std::string Game::get_genre() 
{
    return _genre;
}

// Retorna a plataforma do jogo
std::string Game::get_platform() 
{
    return _platform;
}

//Retorna os idiomas do jogo
std::string Game::get_language()    
{
    return _language;
}

//Retorna o sistema operacional
std::string Game::get_os()  
{
    return _os;
}

//Retorna o processador
std::string Game::get_processor()   
{
    return _processor;
}

//Retorna a memoria
std::string Game::get_memory()  
{
    return _memory;
}

//Retorna a placa de video
std::string Game::get_graphics()    
{
    return _graphics;
}

//Retorna o DirectX
int Game::get_directx()     
{
    return _directx;
}

//Retorna o armazenamento
std::string Game::get_storage()     
{
    return _storage;
}

// Define o genero do jogo
void Game::set_genre(std::string genre)   
{
    _genre = genre;
}

// Define a plataforma do jogo
void Game::set_platform(std::string platform)      
{
    _platform = platform;
}

// Define os idiomas do jogo
void Game::set_language(std::string language)   
{
    _language = language;
}

// Define o sistema operacional
void Game::set_os(std::string os)   
{
    _os = os;
}

// Define o processador
void Game::set_processor(std::string processor)    
{
    _processor = processor;
}

// Define a memoria
void Game::set_memory(std::string memory)  
{
    _memory = memory;
}

// Define a placa de video
void Game::set_graphics(std::string graphics)   
{
    _graphics = graphics;
}

// Define o DirectX
void Game::set_directx(int directx)    
{
    _directx = directx;
}

// Define o armazenamento
void Game::set_storage(std::string storage)   
{
    _storage = storage;
}

void Game::set_age_rating(int ageRating)  // Define a classificacao etaria do jogo
{
    _ageRating = ageRating;
}

