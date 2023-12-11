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
    void set_username(std::string username);
    std::string get_password();
    void set_password(std::string newPassword);
    std::string get_email();
    void set_email(std::string email);
    std::string get_cpf();
    int get_id();
    int get_age();
    double get_balance();
    void set_balance(double balance);
    
    virtual void menu() = 0;

};

#endif