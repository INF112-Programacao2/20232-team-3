#include"Client.hpp"

Client::Client(std::string username, std::string password, std::string email, std::string cpf, double balance, int id)
{
    _username = username;
    _password = password;
    _email = email;
    _cpf = cpf;
    _balance = balance;
    _id = id;
}

std::string Client::get_username()
{
    return _username;
}

void Client::set_username(std::string username)
{
    _username = username;
}

std::string Client::get_password()
{
    return _password;
}

std::string Client::get_email()
{
    return _email;
}

std::string Client::get_cpf()
{
    return _cpf;
}

int Client::get_id()
{
    return _id;
}

int Client::get_age()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);

    Date current;
    current.day = currentDate->tm_mday;
    current.month = currentDate->tm_mon+1;
    current.year = currentDate->tm_year+1900;

    int age = current.year - _birthdate.year;
    if(current.month < _birthdate.month)
        age--;
    else if(current.month == _birthdate.month)
        if(current.day < _birthdate.day)
            age--;
    return age;
}

double Client::get_balance()
{
    return _balance;
}