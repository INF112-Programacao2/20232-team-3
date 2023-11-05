#ifndef USER_HPP_
#define USER_HPP_

#include"Client.hpp"
#include"Game.hpp"
#include<vector>

class User: public Client
{
private:
    //std::vector<Game_Copy> _library;
    std::vector<Game> _wishlist;
public:
    User(std::string username, std::string password, std::string email, Date birthdate);
    ~User();
    void buy_game(Game game);
    void add_to_wishlist(Game game);
    void remove_from_wishlist(Game game);
};

#endif // USER_HPP_