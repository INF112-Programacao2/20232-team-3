#ifndef COSMETICHPP
#define COSMETICHPP

#include "Product.hpp"
#include <string>

class Cosmetic : public Product    // Classe que representa um cosmético, herda de produto
{    
    private:
        // Data
        std::string _type;  // Tipo de cosmético
        std::string _description;   // Descrição do cosmético

    public:
        // Constructor
        Cosmetic(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate, std::string type, std::string description);

        // Getters
        std::string get_type(); // Retorna o tipo de cosmético
        std::string get_description();  // Retorna a descrição do cosmético
};

#endif