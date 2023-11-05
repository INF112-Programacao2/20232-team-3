#ifndef STUDIO_HPP_
#define STUDIO_HPP_

#include"Client.hpp"
#include"../Game.hpp"
#include<vector>
class Studio: public Client
{
private:
    std::string _CNPJ;
    std::string _CPF;
    std::vector<Game> _publishedGames;
public:
    Studio(std::string username, std::string password, std::string email, Date birthdate, std::string CNPJorCPF);
    ~Studio();
    void publish_game(Game game);
    void remove_game(Game game);
    //void add_DLC(Game game, DLC dlc);
    //void remove_DLC(Game game, DLC dlc);
    std::string get_CNPJ();
    std::string get_CPF();
};

#endif // STUDIO_HPP_