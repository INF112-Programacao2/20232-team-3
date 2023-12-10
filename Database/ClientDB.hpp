#ifndef CLIENTDB_HPP
#define CLIENTDB_HPP

#include "../Client/Developer.hpp"
#include <string>

//class Developer;

class ClientDB
{
public:
    static void edit_info(Developer* dev);
    static bool exist_userName(std::string &username);
    static bool exist_email(std::string &email);
};

#endif // CLIENTDB_HPP
