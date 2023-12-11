#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"
#include "Database/ClientDB.hpp"
#include "Database/GameDB.hpp"

#include<bits/stdc++.h>

int main()
{
    std::vector<Game> meusjogos;
    Game game("Valorant", "Riot Games", 18, 0, 1, {"Mo bosta", "Muito bom"}, "20/5/2020", "FPS", "PC", "Portugues", "Windows 11", "Intel core i5", "8 GB", "RTX 3050", 12, "35 GB");
    
    std::cout << game.get_name() << '\n';
    meusjogos.push_back(game);
    Developer dev("Pedro", "pedro123", "Pedro@gmail.com", "123456789", 0, meusjogos);
    dev.menu();
    std::cout << game.get_name() << '\n';


    return 0;
}