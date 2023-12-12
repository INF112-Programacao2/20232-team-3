#include"Client.hpp"

// Constructor
Client::Client(std::string username, std::string password, std::string email, std::string cpf, double balance, std::string birthdate, int id) 
{
    _username = username;
    _password = password;
    _email = email;
    _cpf = cpf;
    _balance = balance;
    _id = id;
    _birthdate = birthdate;
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
    struct Date
    {
        int day, month, year;
    };
    Date _birthdatef = {(_birthdate[0]-'0')*10+(_birthdate[1]-'0'), (_birthdate[3]-'0')*10+(_birthdate[4]-'0'), (_birthdate[6]-'0')*1000+(_birthdate[7]-'0')*100+(_birthdate[8]-'0')*10+(_birthdate[9]-'0')};
    // Define a data atual
    Date current;
    current.day = currentDate->tm_mday;
    current.month = currentDate->tm_mon+1;
    current.year = currentDate->tm_year+1900;

    // Calcula a idade
    int age = current.year - _birthdatef.year;
    if(current.month < _birthdatef.month)
        age--;
    else if(current.month == _birthdatef.month)
        if(current.day < _birthdatef.day)
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