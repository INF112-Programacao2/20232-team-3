#ifndef COSMETICHPP
#define COSMETICHPP

#include "Product.hpp"
#include <string>

class Cosmetic : public Product{
    private:
        // Data
        std::string _type;
        std::string _description;

    public:
        // Constructor
        Cosmetic(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string type, std::string description);

        // Getters
        std::string get_type(); //retorna o tipo do cosmético
        std::string get_description();  //retorna a descrição do cosmético
};

#endif