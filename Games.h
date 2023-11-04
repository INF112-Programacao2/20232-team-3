#ifndef GAMES_H
#define GAMES_H
#include <string>
#include "Products.h"


class Games : public Products
{
    // Data
    private:
	std::string _gender;    //Genero do jogo
	std::string _platform;    //Plataforma do jogo
	std::string _languages;    //Idiomas do jogo
	std::string _releaseDate;    //Data de lancamento do jogo

	// Constructor
	public:
	// Console
	Games(std::string name, std::string studio, int ageRating, float price, std::string availability, int reviews, std::string gender, std::string platform, std::string languages, std::string releaseDate);
	
	// Destructor
	~Games();

	// Methods
	// Getters
	std::string get_gender();    //Retorna o genero do jogo
	std::string get_platform();    //Retorna a plataforma do jogo
	std::string get_languages();    //Retorna os idiomas do jogo
	std::string get_releaseDate();    //Retorna a data de lancamento do jogo
	// Setters
	void set_gender(std::string gender);    //Altera o genero do jogo
	void set_platform(std::string platform);    //Altera a plataforma do jogo
	void set_languages(std::string languages);    //Altera os idiomas do jogo
	void set_releaseDate(std::string releaseDate);    //Altera a data de lancamento do jogo
};

#endif
