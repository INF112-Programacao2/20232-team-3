#ifndef DATABASE_HPP_
#define DATABASE_HPP_
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

    class Database{
        public:
        static void add_user(std::string username, std::string email, std::string password,
        int ID, std::string cpf);
        static void show_info(std::string username, std::string password);
        static void add_game_user(std::string username, std::string password, std::string game);
        static void add_balance(std::string username, std::string password, double balance);
        static void add_game(
                            std::string name,
                            std::string studio,
                            std::string ageRating,
                            std::string price,
                            std::string availability,
                            std::string review,
                            std::string releaseDate,
                            std::string gender,
                            std::string platform,
                            std::string language,
                            std::string os,
                            std::string processor,
                            std::string memory,
                            std::string graphics,
                            std::string directx,
                            std::string storage
                            );
        };




#endif // DATABASE_HPP_