#ifndef CLIENTDB_HPP
#define CLIENTDB_HPP

#include "../Client/Developer.hpp"
#include "../Client/User.hpp"
#include "../Client/Client.hpp"

#include <string>

class ClientDB
{
    public:
        static void edit_info(Client* client);  // Edita as informações do cliente
        static void redeem_balance(Developer* dev); // Resgata o saldo do desenvolvedor
        static void add_balance(User* usr); // Adiciona saldo ao usuário

        static void do_register();  // Registra um novo cliente
        static Client* do_login();  // Faz o login de um cliente
};

#endif // CLIENTDB_HPP
