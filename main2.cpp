#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Database/ClientDB.hpp"

#include<bits/stdc++.h>

int main()
{

    Developer dev("LEANDERSON", "1234", "leleleles@gmail.com", "123456789210", 0);

    std::cout << dev.get_email() << '\n';
    dev.menu();
    std::cout << dev.get_email() << '\n';



    return 0;
}