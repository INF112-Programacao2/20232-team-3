#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include<ctime>
#include<string>

struct Date
{
    int day, month, year;
};

class Client
{
protected:
    // Dados pessoais do cliente
    std::string _username, _password, _email, _cpf;
    Date _birthdate;
    int _id; // Identificador do cliente
    double _balance; // Saldo do cliente
public:
    Client(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, int id);

    std::string get_username();
    std::string get_password();
    std::string get_email();
    std::string get_cpf();
    int get_id();
    int get_age();
    double get_balance();
    
    virtual void menu() = 0;

};

#endif