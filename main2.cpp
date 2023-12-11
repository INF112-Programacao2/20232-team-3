#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"
#include "Database/ClientDB.hpp"
#include "Database/GameDB.hpp"

#include<bits/stdc++.h>

int main()
{
    //std::vector<Game> meusjogos;
    Game game("Valorant", "Riot Games", 18, 0, 1, {"Mo bosta", "Muito bom"}, "20/5/2020", "FPS", "PC", "Portugues", "Windows 11", "Intel core i5", "8 GB", "RTX 3050", 12, "35 GB"), game2("Minecraft", "Mojang", 0, 125, 1, {}, "21/04/2008", "Sandbox", "PC", "Portugues", "Windows", "Intelcorei2", "4GB", "IIntelGraphics", 10, "5");
    
    //meusjogos.push_back(game);
    //meusjogos.push_back(game2);
    //Developer dev("Pedro", "pedro123", "Pedro@gmail.com", "123456789", 0, meusjogos);
    //dev.print_published_games();
    //dev.menu();
    //dev.print_published_games();
    User usr("Leles", "1234", "leleleles@gmail.com", "123456789210", 400, {}, {game, game2});
    usr.print_library();
    usr.print_wishlist();
    usr.menu();
    usr.print_library();
    usr.print_wishlist();


    return 0;
}