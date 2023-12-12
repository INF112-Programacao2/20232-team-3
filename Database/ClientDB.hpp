#ifndef CLIENTDB_HPP
#define CLIENTDB_HPP

#include "../Client/Developer.hpp"
#include "../Client/User.hpp"
#include "../Client/Client.hpp"
#include <string>

//class Developer;

class ClientDB
{
public:
    // Auxiliares
    static bool exist_username(std::string &username);
    static bool exist_email(std::string &email);

    static void edit_info(Client* client);
    static void redeem_balance(Developer* dev);
    static void add_balance(User* usr);

    static void do_register();
    static Client* do_login();
};

#endif // CLIENTDB_HPP
