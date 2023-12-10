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
    User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::vector<MyGame> _library, std::vector<Game> _wishlist);
    ~User();
    void buy_game();
    void add_to_wishlist(Game game);
    void remove_from_wishlist(Game game);
    virtual void menu();
    bool check_index(int index);
};

#endif // USER_HPP_