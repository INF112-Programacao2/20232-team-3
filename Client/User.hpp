#ifndef USER_HPP_
#define USER_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"
#include<vector>

class User: public Client
{
private:
    std::vector<Game> _library;
    std::vector<Game> _wishlist;
public:
    User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> _library, std::vector<Game> _wishlist);
    virtual void menu();

    void buy_game(Game game, std::string username);
    void print_wishlist();
    void print_library();
    void add_to_wishlist(std::string gameName, std::string username);

};

void load_game_from_json(std::string name, std::vector<Game> &games);

#endif // USER_HPP_