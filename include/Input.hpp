#ifndef INPUT_HPP
#define INPUT_HPP

#include<string>
#include<iostream>
#include<cctype>

class Input
{

    public:
        // Métodos estáticos para receber dados do usuário
        static std::string input_name(std::string text);    // Recebe um texto e retorna uma string com o nome
        static std::string input_name(std::string text, int limit);   // Recebe um texto e retorna uma string com o nome
        static std::string input_email(std::string text);   // Recebe um texto e retorna uma string com o email
        static std::string input_password();    // Recebe um texto e retorna uma string com a senha
        static std::string input_cpf(); // Recebe um texto e retorna uma string com o CPF
        static std::string input_date(std::string text);    // Recebe um texto e retorna uma string com a data
        static int input_int(std::string text, int lower, int upper);   // Recebe um texto e retorna um inteiro
        static int input_posint(std::string text);  // Recebe um texto e retorna um inteiro positivo
        static double input_double(std::string text);   // Recebe um texto e retorna um double
        static int input_bool(std::string txt); // Recebe um texto e retorna um booleano
};
#endif // INPUT_HPP
