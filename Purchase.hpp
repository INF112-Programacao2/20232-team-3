#ifndef PURCHASE_HPP
#define PURCHASE_HPP
#include "Product/My_Games.hpp"
#include "Client/Client.hpp"
#include <ctime>
class Purchase : public Client
{
    
public:
    Purchase();
    ~Purchase();
    void buy_game();

};

#endif // PURCHASE_HPP
