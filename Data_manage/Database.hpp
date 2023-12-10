#ifndef DATABASE_HPP_
#define DATABASE_HPP_
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

    class Database{
        public:
        static void add_user(std::string &username, std::string &email, std::string &password,
        int &ID, std::string &cpf, std::string &birthdate);
        static void show_info(std::string &username, std::string &password);
        static void add_game_user(std::string &username, std::string &password, std::string &ame);
        static void add_balance(std::string &username, std::string &password, double &balance);
        static void show_games();
        static void search_game(std::string &username, std::string &password, std::string &game);
        static void add_to_wishlist(std::string &username, std::string &password, std::string &game);
        static bool check_user(std::string &username, std::string &password);
        static void addGame();    // Adiciona um jogo
        static void removeGame();    // Remove um jogo
        static void changeGame();    // Altera um jogo

    };




#endif // DATABASE_HPP_