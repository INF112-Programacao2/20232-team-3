#ifndef USER_HPP_
#define USER_HPP_

#include"Client.hpp"
#include"Game.hpp"
#include<vector>

class User: public Client   // Classe filha de Client
{
private:
    // dados do usuário
    std::vector<Game> _library; // biblioteca de jogos
    std::vector<Game> _wishlist;    // lista de desejos
public:
    // Construtor
    User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> _library, std::vector<Game> _wishlist);
    
    virtual void menu();    // Menu do usuário

    void buy_game(Game game, std::string username); // Função que permite que o usuario compre um jogo
    void print_wishlist();  // Imprime a lista de desejos
    void print_library();   // Imprime a biblioteca de jogos
    void add_to_wishlist(std::string gameName, std::string username);   // Adiciona um jogo a lista de desejos

};

void load_game_from_json(std::string name, std::vector<Game> &games);   // Carrega os jogos de um arquivo JSON

#endif // USER_HPP_