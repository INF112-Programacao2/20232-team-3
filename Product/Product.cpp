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

// Construtor sem parametros
Product::Product() 
{
}

 //Retorna o nome do produto
std::string Product::get_name()
{
    return _name;
}

//Define o nome do produto
void Product::set_name(std::string name) 
{
    _name = name;
}

//Retorna o nome do studio que produziu o produto
std::string Product::get_studio()   
{
    return _studio;
}

//Define o nome do studio que produziu o produto
void Product::set_studio(std::string studio)    
{
    _studio = studio;
}

//Retorna a classificacao etaria do produto
int Product::get_ageRating()    
{
    return _ageRating;
}

//Retorna o preco do produto
double Product::get_price()     
{
    return _price;
}

//Retorna a disponibilidade do produto
bool Product::get_availability()    
{
    return _availability;
}

//Retorna a data de lancamento do produto
std::string Product::get_releaseDate()  
{
    return _releaseDate;
}

//Define a disponibilidade do produto
void Product::set_availability(bool availability) 
{
    _availability = availability;
}

//Define o preco do produto
void Product::set_price(double price)   
{
    _price = price;
}

//Define a classificacao etaria do produto
void Product::set_ageRating(std::string ageRating) 
{
    _ageRating = stoi(ageRating);
}

//Retorna as avaliacoes do produto
std::vector <std::string> Product::get_review() 
{
    return _review;
}

//Define as avaliacoes do produto
void Product::set_review(std::vector <std::string> review) 
{
    _review = review;
}

//Define a data de lancamento do produto
void Product::set_releaseDate(std::string releaseDate) 
{
    _releaseDate = releaseDate;
}