#ifndef USER_HPP_
#define USER_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"
#include<vector>

class User: public Client
{
private:
    //std::vector<Game_Copy> _library;
    std::vector<Game> _wishlist;
public:
    User();
    ~User();
    void buy_game(Game game);
    void add_to_wishlist(Game game);
    void remove_from_wishlist(Game game);
};

#endif // USER_HPP_