#ifndef AUTENTICATION_HPP_
#define AUTENTICATION_HPP_
#include <nlohmann/json.hpp>
#include <bits/stdc++.h>

    class Autentication{
        public:
        void Registrar();
        void Login(std::string usermail, std::string password);
        std::string user_name();
        std::string user_email();
        std::string user_password();
        std::string user_cpf();
        std::string user_birthdate();
        static std::string verifyName();    // Verifica se o nome é válido
        static std::string verifyStudio();    // Verifica se o nome do studio é válido
        static std::string verifyAgeRating();    // Verifica se a classificacao etaria é válida
        static double verifyPrice();    // Verifica se o preco é válido
        static std::string verifyAvailability();    // Verifica se a disponibilidade é válida
        static std::string verifyReview();    // Verifica se a avaliacão é válida
        static std::string verifyReleaseDate();    // Verifica se a data de lancamento é válida



    

};


#endif // AUTENTICATION_HPP_