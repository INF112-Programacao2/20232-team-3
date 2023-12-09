#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include<ctime>
#include<string>
#include<iostream>

//bool checkCPF(const std::string& cpf);
//bool checkCNPJ(const std::string& cnpj);

struct Date
{
    int day, month, year;
};

class Client
{
protected:
    std::string _username, _password, _email, _cpf;
    int _id;    // Tipo de cliente
    Date _birthdate; // Nascimento do cliente
    double _balance; // Saldo do cliente
public:
    Client(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, int id);
    ~Client();
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