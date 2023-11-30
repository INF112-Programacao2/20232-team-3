#ifndef STUDIO_HPP_
#define STUDIO_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"
#include<vector>
class Studio: public Client
{
private:
    std::string _CNPJ;
    std::string _CPF;
    std::vector<Game> _publishedGames;
public:
    Studio();
    ~Studio();
    void publish_game(Game game);
    void remove_game(Game game);
    std::string get_CNPJ();
    std::string get_CPF();
};

#endif // STUDIO_HPP_