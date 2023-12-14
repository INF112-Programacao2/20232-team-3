#ifndef DEVELOPER_HPP_
#define DEVELOPER_HPP_

#include"Client.hpp"
#include"Game.hpp"

#include<vector>

class Developer: public Client  // Classe filha de Client
{
    private:
        // jogos publicados pelo desenvolvedor
        std::vector<Game> _publishedGames;
    public:
        // Construtor
        Developer(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> publishedGames);
        void print_published_games();   // Imprime os jogos publicados pelo desenvolvedor
        virtual void menu();    // Menu do desenvolvedor
};

#endif // DEVELOPER_HPP_