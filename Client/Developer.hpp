#ifndef DEVELOPER_HPP_
#define DEVELOPER_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"
#include<vector>
class Developer: public Client
{
private:
    std::string _CNPJ;
    std::string _CPF;
    std::vector<Game> _publishedGames;
public:
    Developer();
    ~Developer();
    void publish_game(Game game);
    void remove_game(Game game);
    std::string get_CNPJ();
    std::string get_CPF();
    virtual void menu();
};

#endif // DEVELOPER_HPP_