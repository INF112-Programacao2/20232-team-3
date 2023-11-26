#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include<ctime>
#include<string>
#include<iostream>

bool checkCPF(const std::string& cpf);
bool checkCNPJ(const std::string& cnpj);

struct Date
{
    int day, month, year;
};

class Client
{
protected:
    std::string _username, _password, _email;
    int _id;    // Tipo de cliente
    Date _birthdate;
    double _balance; // Saldo do cliente
public:
    Client();
    ~Client();
    std::string get_username();
    std::string get_password();
    std::string get_email();
    int get_id();
    int get_age();
    double get_balance();
    void change_password(std::string old_password, std::string new_password);

};

#endif