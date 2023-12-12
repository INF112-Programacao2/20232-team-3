#ifndef INPUT_HPP
#define INPUT_HPP

#include<string>
#include<iostream>
#include<cctype>

class Input
{
private:
public:
    static std::string input_name(std::string text);
    static std::string input_name(std::string text, int limit);
    static std::string input_email(std::string text);
    static std::string input_password();
    static std::string input_cpf();
    static std::string input_date(std::string text);
    static int input_int(std::string text, int lower, int upper);
    static int input_posint(std::string text);
    static double input_double(std::string text);
    static int input_bool(std::string txt);
};
#endif // INPUT_HPP
