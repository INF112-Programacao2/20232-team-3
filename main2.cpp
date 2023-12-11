#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"
#include "Database/ClientDB.hpp"
#include "Database/GameDB.hpp"

#include<bits/stdc++.h>

int main()
{
    std::vector<Game> meusjogos;
    Game game("Valorant", "Riot Games", 18, 0, 1, {"Mo bosta", "Muito bom"}, "20/5/2020", "FPS", "PC", "Portugues", "Windows 11", "Intel core i5", "8 GB", "RTX 3050", 12, "35 GB"), game2("Minecraft", "Mojang", 0, 125, 1, {}, "21/04/2008", "Sandbox", "PC", "Portugues", "Windows 11", "Intel core i3", "4 GB", "Intel graphics", 10, "5 GB");
    
    meusjogos.push_back(game);
    Developer dev("Pedro", "pedro123", "Pedro@gmail.com", "123456789", 0, meusjogos);
    dev.print_published_games();
    dev.menu();
    dev.print_published_games();


    return 0;
}