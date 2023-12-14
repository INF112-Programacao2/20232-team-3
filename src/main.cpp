#include "../include/Client.hpp"
#include "../include/Developer.hpp"
#include "../include/User.hpp"
#include "../include/ClientDB.hpp"
#include "../include/GameDB.hpp"
#include "../include/Game.hpp"
#include "../include/Product.hpp"

#include <iostream>

int main()
{
    int aux;
    Client* client;
    client = nullptr;
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
    if (client != nullptr)
        client->menu();

    std::cout << "Obrigado por usar a Steam!\n";


	return 0;
}