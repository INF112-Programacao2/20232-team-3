#ifndef AUTENTICATION_HPP_
#define AUTENTICATION_HPP_
#include <bits/stdc++.h>
#include "json_fwd.hpp"
#include "json.hpp"

    class Autentication{
private:
    std::string _username, _email, _password;
public:
    Autentication(std::string username, std::string email, std::string password); // Construtor que coloca username passaword e email como 
    std::string search_user(const std::string& nomeArquivo); // Entra no txt/json e confere o tipo do cliente, se for user retorna 1, se for studio retorna 2, se não encontrar retorna 0
    //User load_user(); // Entra no txt/json e carrega os dados do user;
    //Studio load_studio(); // Entra no txt/json e carrega os dados do studio;
    std::string get_username();
    std::string get_password();
    std::string get_email();

};


#endif // AUTENTICATION_HPP_