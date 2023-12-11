#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Database/ClientDB.hpp"

#include<bits/stdc++.h>

int main()
{

    Developer dev("LEANDERSON", "1234", "joaoL@gmail.com", "123456789210", 400.00);

    std::cout << dev.get_balance() << '\n';
    dev.menu();
    std::cout << dev.get_balance() << '\n';



    return 0;
}