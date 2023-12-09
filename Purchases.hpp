#ifndef PURCHASES_HPP
#define PURCHASES_HPP
#include "Product/My_Games.hpp"
#include "Client/Client.hpp"
#include <ctime>
class Purchases : public Client
{
    
public:
    Purchases();
    ~Purchases();
    bool checkAge(Date birthdate, std::string ageRating);
    bool checkBalance(double balance, double price);
    void buy_game(My_Games new_game, Game game);

};

#endif // PURCHASES_HPP
