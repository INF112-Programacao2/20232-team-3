#include <iostream>
#include <string>
#include "Product.hpp"

// Constructor
Product::Product(std::string name, std::string studio, std::string ageRating, std::string price, std::string availability, std::string review, std::string releaseDate) : 
    _name(name), _studio(studio), _ageRating(ageRating), _price(price), _availability(availability), _review(review), _releaseDate(releaseDate) 
{
}

Product::Product(std::string name, std::string price, std::string availability) : 
    _name(name), _price(price), _availability(availability) 
{
}

// Destructor
Product::~Product() 
{
}

// Getters
std::string Product::get_name() {    //Retorna o nome do produto
    return _name;
}

std::string Product::get_studio() {    //Retorna o nome do studio que produziu o produto
    return _studio;
}

std::string Product::get_ageRating(){ // Retorna a classificacao etaria do produto
    return _ageRating;
}

std::string Product::get_price() {    //Retorna o preco do produto
    return _price;
}

std::string Product::get_availability() {    //Retorna a disponibilidade do produto
    return _availability;
}

std::string Product::get_review() {    //Retorna a avaliacão do produto
    return _review;
}

std::string Product::get_releaseDate() {    //Retorna a data de lancamento do produto
    return _releaseDate;
}