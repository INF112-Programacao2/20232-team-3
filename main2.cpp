#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"
#include "Database/ClientDB.hpp"
#include "Database/GameDB.hpp"

#include<bits/stdc++.h>

int main()
{
    Client* client = ClientDB::do_login();  // Faz o login do cliente  
    client->menu();     // Chama o menu do cliente(dev ou user) 
    return 0;
}