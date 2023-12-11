#include"Client.hpp"

// Constructor
Client::Client(std::string username, std::string password, std::string email, std::string cpf, double balance, int id) 
{
    _username = username;
    _password = password;
    _email = email;
    _cpf = cpf;
    _balance = balance;
    _id = id;
}

// retorna o nome de usuario
std::string Client::get_username()
{
    return _username;
}

// define o nome de usuario
void Client::set_username(std::string username)
{
    _username = username;
}

// retorna a senha
std::string Client::get_password()
{
    return _password;
}

// define a senha
void Client::set_password(std::string newPassword)
{
    _password = newPassword;
}

// retorna o email
std::string Client::get_email()
{
    return _email;
}

// define o email
void Client::set_email(std::string email)
{
    _email = email;
}

// retorna o CPF
std::string Client::get_cpf()
{
    return _cpf;
}

// retorna o id
int Client::get_id()
{
    return _id;
}

// calcula a idade do cliente em relação a data atual
int Client::get_age()
{
    // Pega a data atual
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);

    // Define a data atual
    Date current;
    current.day = currentDate->tm_mday;
    current.month = currentDate->tm_mon+1;
    current.year = currentDate->tm_year+1900;

    // Calcula a idade
    int age = current.year - _birthdate.year;
    if(current.month < _birthdate.month)
        age--;
    else if(current.month == _birthdate.month)
        if(current.day < _birthdate.day)
            age--;
    return age;     // Retorna a idade
}

// retorna o saldo
double Client::get_balance()
{
    return _balance;
}

// define o saldo
void Client::set_balance(double balance)
{
    _balance = balance;
}

// define o CPF
void Client::set_cpf(std::string cpf)
{
    _cpf = cpf;
}

// define o ID
void Client::set_id(int id)
{
    _id = id;
}

// define a data de nascimento
void Client::set_birthdate(Date birthdate)
{
    _birthdate = birthdate;
}


