#ifndef GIFTCARD_HPP_
#define GIFTCARD_HPP_

#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "Product.hpp"

class GiftCard : public Product{
    public:
        // Data
        std::string _code;    // Código do cartão
    public:
        // Constructor
        GiftCard(std::string name, std::string price, std::string availability, std::string code);

        // Destructor
        ~GiftCard();

        // Methods
        static std::string generateCode();    // Gera um código aleatório

        // Getters
        std::string get_code();    // Retorna o código do cartão
};

#endif    // GIFTCARD_HPP_