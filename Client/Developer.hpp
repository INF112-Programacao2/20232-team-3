#ifndef DEVELOPER_HPP_
#define DEVELOPER_HPP_

#include"Client.hpp"

#include<vector>

class Developer: public Client
{
private:
    std::vector<Game> _publishedGames;
public:
    Developer(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::vector<Game> publishedGames);
    virtual void menu();
};

#endif // DEVELOPER_HPP_