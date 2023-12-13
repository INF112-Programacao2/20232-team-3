#include <iostream>
#include <string>
#include "Product.hpp"
#include "Cosmetic.hpp"

// Constructor
Cosmetic::Cosmetic(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string type, std::string description) : Product(name, studio, ageRating, price, availability, review, releaseDate), _type(type), _description(description) 
{

}
//retorna o tipo de cosmético
std::string Cosmetic::get_type() {
    return _type;
}
//retorna a descrição do cosmético
std::string Cosmetic::get_description() {
    return _description;
}