#include "Product.hpp"

// Constructor
Product::Product(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate) // Construtor
{
    _name = name;
    _studio = studio;
    _ageRating = ageRating;
    _price = price;
    _availability = availability;
    _review = review;
    _releaseDate = releaseDate;
}

std::string Product::get_name() //Retorna o nome do produto
{
    return _name;
}

void Product::set_name(std::string name) //Define o nome do produto
{
    _name = name;
}

std::string Product::get_studio()   //Retorna o nome do studio que produziu o produto
{
    return _studio;
}

void Product::set_studio(std::string studio)    //Define o nome do studio que produziu o produto
{
    _studio = studio;
}

int Product::get_ageRating()    //Retorna a classificacao etaria do produto
{
    return _ageRating;
}

double Product::get_price()     //Retorna o preco do produto
{
    return _price;
}

bool Product::get_availability()    //Retorna a disponibilidade do produto
{
    return _availability;
}
std::string Product::get_releaseDate()  //Retorna a data de lancamento do produto
{
    return _releaseDate;
}

void Product::set_availability(bool availability) //Define a disponibilidade do produto
{
    _availability = availability;
}

void Product::set_price(double price)   //Define o preco do produto
{
    _price = price;
}

void Product::set_releaseDate(std::string releaseDate) //Define a data de lancamento do produto
{
    _releaseDate = releaseDate;
}

void Product::set_ageRating(std::string ageRating) //Define a classificacao etaria do produto
{
    _ageRating = stoi(ageRating);
}

std::vector <std::string> Product::get_review() //Retorna as avaliacoes do produto
{
    return _review;
}

void Product::set_review(std::vector <std::string> review) //Define as avaliacoes do produto
{
    _review = review;
}



void Product::set_releaseDate(std::string releaseDate) //Define a data de lancamento do produto
{
    _releaseDate = releaseDate;
}