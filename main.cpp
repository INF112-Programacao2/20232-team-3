#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"
#include "Database/ClientDB.hpp"
#include "Database/GameDB.hpp"
#include "Product/Game.hpp"
#include "Product/Product.hpp"

#include <iostream>

int main()
{
    int aux;
    Client* client;
    std::cout << "Bem vindo à Steam!\n";
    MAIN:
    std::cout << "O que deseja fazer?\n1 - Registrar\n2 - Logar\nAperte qualquer outra tecla para sair\n";
    std::cin >> aux;
    std::cin.ignore();
    switch (aux)
    {
    case 1:
        REGISTRO: 
        ClientDB::do_register();
        goto MAIN;
        break;
    case 2:
        LOGIN:
        client = ClientDB::do_login();
        break;
    default:
        break;
    }

    client->menu();

    std::cout << "Obrigado por usar a Steam!\n";


	return 0;
}