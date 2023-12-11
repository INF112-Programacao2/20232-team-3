#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"
#include "Database/ClientDB.hpp"

#include<bits/stdc++.h>

int main()
{

    User usr("LEANDERSON", "1234", "leleleles@gmail.com", "123456789210", 400.00);

    std::cout << usr.get_balance() << '\n';
    usr.menu();
    std::cout << usr.get_balance() << '\n';



    return 0;
}