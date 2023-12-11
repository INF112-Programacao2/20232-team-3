#include <iostream>
#include <string>
#include "Product.hpp"
#include "Cosmetic.hpp"

// Constructor
Cosmetic::Cosmetic(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string type, std::string description) : Product(name, studio, ageRating, price, availability, review, releaseDate), _type(type), _description(description) 
{

}

// Getters
std::string Cosmetic::get_type() {
    return _type;
}

std::string Cosmetic::get_description() {
    return _description;
}