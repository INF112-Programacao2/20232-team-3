#ifndef DEVELOPER_HPP_
#define DEVELOPER_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"

#include<vector>

class Developer: public Client // Herda de Client
{
    private:
        // Data
        std::vector<Game> _publishedGames; // Vetor de jogos publicados pelo desenvolvedor
    public:
        // Construtor
        Developer(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> publishedGames);
        
        // printa os jogos publicados pelo desenvolvedor
        void print_published_games();
        
        //menu do desenvolvedor
        virtual void menu();
};

#endif // DEVELOPER_HPP_