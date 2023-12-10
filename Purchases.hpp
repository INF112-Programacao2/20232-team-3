#ifndef PURCHASES_HPP
#define PURCHASES_HPP
#include "../Product/MyGame.hpp"
#include "Client/User.hpp"
#include <ctime>
class Purchases
{
    
public:
    Purchases();
    ~Purchases();
    void buy_game(Game new_game);

};

#endif // PURCHASES_HPP
