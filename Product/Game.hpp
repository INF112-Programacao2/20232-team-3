#ifndef GAMES_HPP_
#define GAMES_HPP_
#include <string>
#include "Product.hpp"

class Game : public Product {    // Classe Game herda da classe Product
    private:
    // Data
	    std::string _gender;    //Genero do jogo
	    std::string _platform;    //Plataforma do jogo
	    std::string _language;    //Idiomas do jogo
	    std::string _os;    //Sistema operacional
	    std::string _processor;    //Processador
	    std::string _memory;    //Memoria
	    std::string _graphics;    //Placa de video
	    int  _directx;    //DirectX
	    std::string _storage;    //Armazenamento

	public:
	    // Console constructor
	    Game(std::string name, std::string studio, std::string ageRating, std::string price, std::string availability, std::string review, std::string releaseDate, std::string gender, std::string platform, std::string language);
	    // PC constructor
	    Game(std::string name, std::string studio, std::string ageRating, std::string price, std::string availability, std::string review, std::string releaseDate, std::string gender, std::string platform, std::string language, std::string os, std::string processor, std::string memory, std::string graphics, int directx, std::string storage);
	
	    // Destructor
	    ~Game();

	    // Getters
	    std::string get_gender();    //Retorna o genero do jogo
	    std::string get_platform();    //Retorna a plataforma do jogo
	    std::string get_language();    //Retorna os idiomas do jogo
	    std::string get_os();    //Retorna o sistema operacional
	    std::string get_processor();    //Retorna o processador
	    std::string get_memory();    //Retorna a memoria
	    std::string get_graphics();    //Retorna a placa de video
	    std::string get_directx();    //Retorna o DirectX
	    std::string get_storage();    //Retorna o armazenamento
};

#endif    // GAMES_HPP_