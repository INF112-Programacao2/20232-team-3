#ifndef USER_HPP_
#define USER_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"
#include"../Product/MyGame.hpp"
#include<vector>

class User: public Client
{
private:
    std::vector<MyGame> _library;
    std::vector<Game> _wishlist;
public:
    User();
    ~User();
    void buy_game(Game game);
    void add_to_wishlist(Game game);
    void remove_from_wishlist(Game game);
    virtual void menu();
};

#endif // USER_HPP_