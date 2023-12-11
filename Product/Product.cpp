#include "Product.hpp"

// Constructor
Product::Product(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate){
    _name = name;
    _studio = studio;
    _ageRating = ageRating;
    _price = price;
    _availability = availability;
    _review = review;
    _releaseDate = releaseDate;
}
std::string Product::get_name(){
    return _name;
}
std::string Product::get_studio(){
    return _studio;
}
int Product::get_ageRating(){
    return _ageRating;
}
double Product::get_price(){
    return _price;
}
bool Product::get_availability(){
    return _availability;
}
std::string Product::get_releaseDate(){
    return _releaseDate;
}
void Product::set_availability(bool availability){
    _availability = availability;
}
void Product::set_name(std::string name){
    _name = name;
}
void Product::set_studio(std::string studio){
    _studio = studio;
}
