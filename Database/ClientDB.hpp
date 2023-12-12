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
    static void edit_info(Client* client);
    static void redeem_balance(Developer* dev);
    static void add_balance(User* usr);

    static void do_register();
    static Client* do_login();
};

#endif // CLIENTDB_HPP
