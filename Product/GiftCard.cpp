#include <iostream>
#include <string>
#include <time.h>
#include "GiftCard.hpp"

// Constructor
GiftCard::GiftCard(std::string name, std::string price, std::string availability, std::string code) : 
    Product(name, price, availability), _code(code) 
{
}

// Destructor
GiftCard::~GiftCard() 
{
}

std::string GiftCard::generateCode() {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int codeLength = 15;

    std::string code = "";
    std::srand(std::time(0));  // Seed para geração aleatória

    for (int i = 0; i < codeLength; ++i) {
        code += chars[std::rand() % chars.length()];
    }

    return code;
}

std::string GiftCard::get_code() {    // Retorna o código do cartão
    return _code;
}