#ifndef CLIENTDB_HPP
#define CLIENTDB_HPP

#include "../Client/Developer.hpp"
#include "../Client/User.hpp"
#include "../Client/Client.hpp"
#include <string>

class ClientDB
{
    public:
        // Auxiliares
        static bool exist_username(std::string &username);  // Verifica se o username já existe
        static bool exist_email(std::string &email);    // Verifica se o email já existe

        // principais
        static void edit_info(Client* client);  // Função que permite que o usuario veja seus dados e edite eles
        static void redeem_balance(Developer* dev); // Função que permite que o usuario veja seu saldo atual e resgate um valor
        static void add_balance(User* usr); // Função que permite que o usuario veja seu saldo atual e resgate um valor

        // Login e registro
        static void do_register();  // Função que permite que o usuario se registre
        static Client* do_login();  // Função que permite que o usuario faça login
};

#endif // CLIENTDB_HPP
