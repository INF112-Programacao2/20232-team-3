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
    void buy_game();

};

#endif // PURCHASES_HPP
