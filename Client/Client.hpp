#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include<ctime>
#include<string>

// Struct para armazenar a data de nascimento
struct Date
{
    int day, month, year;
};

class Client
{
protected:
    // Dados pessoais do cliente
    std::string _username, _password, _email, _cpf; // Nome de usuario, senha, email e CPF
    Date _birthdate;    // Data de nascimento
    int _id; // Identificador do cliente
    double _balance; // Saldo do cliente
public:
    Client(std::string _username, std::string _password, std::string _email, std::string _cpf, double balance, int id); // Construtor

    // Getters
    std::string get_username(); // Retorna o nome de usuario
    std::string get_password(); // Retorna a senha
    std::string get_email();    // Retorna o email
    std::string get_cpf();  // Retorna o CPF
    int get_id();   // Retorna o ID
    int get_age();  // Retorna a idade
    double get_balance();   // Retorna o saldo
    
    // Setters
    void set_username(std::string username);    // Define o nome de usuario
    void set_password(std::string newPassword); // Define a senha
    void set_email(std::string email);  // Define o email
    void set_cpf(std::string cpf);  // Define o CPF
    void set_id(int id);    // Define o ID
    void set_birthdate(Date birthdate); // Define a data de nascimento 
    void set_balance(double balance);   // Define o saldo
    
    // Método virtual para o menu, igualado a 0 para forçar a classe filha a implementar
    virtual void menu() = 0;
};

#endif