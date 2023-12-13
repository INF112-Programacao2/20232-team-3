#ifndef USER_HPP_
#define USER_HPP_

#include"Client.hpp"
#include"../Product/Game.hpp"
#include<vector>

class User: public Client   // herda de cliente
{
private:
    std::vector<Game> _library; // Biblioteca de jogos do usuario
    std::vector<Game> _wishlist;    // Lista de desejos do usuario
public:
    // Construtor
    User(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, std::string birthdate, std::vector<Game> _library, std::vector<Game> _wishlist);   
    
    virtual void menu(); // Menu do usuario

    void buy_game(std::string gameName, std::string username);  // Função que permite que o usuario compre um jogo
    void print_wishlist();  // Função que printa a lista de desejos do usuario
    void print_library();   // Função que printa a biblioteca de jogos do usuario
    void add_to_wishlist(std::string gameName, std::string username);   // Função que permite que o usuario adicione um jogo a sua lista de desejos

};

#endif // USER_HPP_