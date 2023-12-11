#ifndef CLIENTDB_HPP
#define CLIENTDB_HPP

#include "../Client/Developer.hpp"
#include <string>

//class Developer;

class ClientDB
{
public:
    // Auxiliares
    static bool exist_userName(std::string &username);
    static bool exist_email(std::string &email);

    static void edit_info(Developer* dev);
    static void redeem_balance(Developer* dev);
};

#endif // CLIENTDB_HPP
