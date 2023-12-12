#include "ClientDB.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void change_clientValue(std::string key, std::string value, std::string username)
{
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) 
    {
        for (auto& data : dadosJSON) 
        {
            std::string usernameJSON = data["Username"];

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) 
            {
                data[key] = value;
                std::ofstream arquivoSaida("clients.json");
                arquivoSaida << dadosJSON.dump(10);
                arquivoSaida.close();
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void change_clientValue(std::string key, double value, std::string username)
{
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) 
    {
        for (auto& data : dadosJSON) 
        {
            std::string usernameJSON = data["Username"];

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) 
            {
                data[key] = value;
                std::ofstream arquivoSaida("clients.json");
                arquivoSaida << dadosJSON.dump(10);
                arquivoSaida.close();
                //dev->set_username(temp);
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

bool ClientDB::exist_username(std::string &username)
{
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) {
                return true;
            }
        }
    }
    return false;
}

bool ClientDB::exist_email(std::string &email)
{
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) {
            std::string emailJSON = data["Email"];

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (emailJSON == email) {
                return true;
            }
        }
    }
    return false;
}

void ClientDB::edit_info(Client* client)
{
    int aux;
    std::string temp, temp2;
    std::cout << "O que deseja alterar?\n1 - Username;\n2 - Password;\n3 - Email;\n4 - Voltar\n";
    std::cin >> aux;
    switch (aux)
    {
        case 1:
            while (true)
            {
                std::cout << "Digite seu novo nome de usuário: ";
                std::cin >> temp;
                if(temp.size() > 30)
                {
                    std::cout << "Nome de usuário muito grande, digite novamente\n";
                }
                else if(exist_username(temp))
                {
                    std::cout << "Nome de usuário já existente, digite novamente\n";
                }
                else
                {
                    change_clientValue("Username", temp, client->get_username());
                    client->set_username(temp);
                    break;
                }
            }
        break;
        case 2:
            while (true)
            {
                std::cout << "Digite sua senha antiga: ";
                std::cin >> temp;
                if(temp == client->get_password())
                {
                    std::cout << "Digite sua nova senha: ";
                    std::cin >> temp2;

                    std::ifstream arquivo("clients.json");
                    if (!arquivo.is_open()) 
                    {
                        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                    }

                    json dadosJSON;
                    arquivo >> dadosJSON;
                    arquivo.close();

                    change_clientValue("Password", temp2, client->get_username());
                    client->set_password(temp);
                    break;

                }
                else
                {
                    std::cout << "Senha incorreta, tente novamente\n";
                }
            }
        break;
        case 3:
            while (true)
            {
                std::cout << "Digite seu novo e-mail: ";
                std::cin >> temp;
                if(temp.size() > 30)
                {
                    std::cout << "E-mail muito grande, digite novamente\n";
                }
                else if(exist_email(temp))
                {
                    std::cout << "E-mail já existente, digite novamente\n";
                }
                else
                {
                    std::ifstream arquivo("clients.json");
                    if (!arquivo.is_open()) 
                    {
                        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                    }

                    json dadosJSON;
                    arquivo >> dadosJSON;
                    arquivo.close();

                    change_clientValue("Email", temp, client->get_username());
                    client->set_email(temp);
                    break;
                }
            }
        break;
    }
}

void ClientDB::redeem_balance(Developer* dev)
{
    while (true)
    {
        std::cout << "Seu saldo atual é de: R$" << dev->get_balance() << '\n';
        std::cout << "Digite o valor que deseja resgatar: ";
        double aux;
        std::cin >> aux;
        if(aux > dev->get_balance())
        {
            std::cout << "Valor maior que o saldo atual, tente novamente\n";
        }
        else if (aux < 0)
        {
            std::cout << "Valor inválido, tente novamente\n";
        }
        else
        {

            std::ifstream arquivo("clients.json");
            if (!arquivo.is_open()) 
            {
                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
            }

            json dadosJSON;
            arquivo >> dadosJSON;
            arquivo.close();

            dev->set_balance(dev->get_balance() - aux);
            change_clientValue("Balance", dev->get_balance(), dev->get_username());
            break;
        }
    }
    
}

void ClientDB::add_balance(User* usr)
{
    while (true)
    {
        std::cout << "Seu saldo atual é de: R$" << usr->get_balance() << '\n';
        std::cout << "Digite o valor que deseja adicionar: ";
        double aux;
        std::cin >> aux;
        if (aux < 0)
        {
            std::cout << "Valor inválido, tente novamente\n";
        }
        else
        {

            std::ifstream arquivo("clients.json");
            if (!arquivo.is_open()) 
            {
                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
            }

            json dadosJSON;
            arquivo >> dadosJSON;
            arquivo.close();

            usr->set_balance(usr->get_balance() + aux);
            change_clientValue("Balance", usr->get_balance(), usr->get_username());
            break;
        }
    }
}

std::string input_username()
{
    std::string _username;
    std::cout << "Digite seu nome de usuário: ";
    while (true)
    {
        try{
            std::getline(std::cin, _username);
            if(_username.empty())
                throw std::invalid_argument("Nome de usuário vazio.\n");
            if(_username.size() > 30)
                throw std::out_of_range("Nome de usuário muito grande.\n");
            break;
        } catch(const std::exception& e){
            std::cerr << e.what() << " Digite novamente: ";
        } 
    }
    return _username;
}

std::string input_email()
{
    std::string _email;
    std::cout << "Digite seu email: ";
    bool has = false;
    while (true)
    {
        try{
            std::getline(std::cin, _email);
            if(_email.empty()){
                throw std::invalid_argument("Email vazio.\n");
            }
            if(_email.size() > 30){
                throw std::out_of_range("Email muito grande.\n");
            }
            for (auto e: _email){
                if(e == '@')
                {
                    has = true;
                }
            }
            if(!has){
                throw std::invalid_argument("Email invalido.\n");
                continue;
            }
            break;
        } catch(const std::exception& e){
            std::cerr << e.what() << " Digite novamente: ";
        }
    }
    return _email;
}

std::string input_password()
{
    std::string _password;
    std::string temp;
    bool hasdigit = false, hasalpha = false;
    while (true){
        try{
            std::cout << "Digite sua senha: ";
            std::cin >> _password;
            std::cout << "Digite sua senha novamente: ";
            std::cin >> temp;

            if(_password != temp){
                throw std::invalid_argument("As senhas não coincidem. ");
            }

            for(auto e: _password){
                if(std::isdigit(e)){
                    hasdigit = true;
                }
                if(std::isalpha(e)){
                    hasalpha = true;
                }
            }
            if(!hasdigit || !hasalpha)
                throw std::invalid_argument("Senha muito fraca, ela deve ter pelo menos um número e uma letra.");
    
            break;
        } catch(const std::exception& e){
            std::cerr << e.what() << " Por favor tente novamente.\n";
        }
    }
    return _password;
}

std::string input_cpf()
{
    std::string _cpf;
    while (true){
        try{
            std::cout << "Digite seu CPF: ";
            std::cin >> _cpf;
            if(_cpf.empty()){
                throw std::invalid_argument("O CPF nao pode ser vazio.");
            }
            if(_cpf.size() != 11){
                throw std::out_of_range("O CPF deve ter 11 digitos.");
            }
            for(auto e: _cpf){
                if(!std::isdigit(e)){
                    throw std::invalid_argument("O CPF so pode ter numeros.");
                }
            }
            for(int i = 0; i < 10; i++){
                if(_cpf[i] == _cpf[i + 1]){
                    throw std::invalid_argument("O CPF nao pode ter digito repetido em sequencia.");
                }
            }
            break;
        } catch(const std::exception& e){  
            std::cerr << e.what() << " Por favor tente novamente.\n";
        }
    }
    return _cpf;      
}

std::string verify_date()
{    // Verifica se a data de lançamento é válida
    int day, month, year;
    while (true){
        try{
            std::cout << "Day: ";
            std::cin >> day;
            std::cout << "Month: ";
            std::cin >> month;
            std::cout << "Year: ";
            std::cin >> year;
            if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1951){    // Verifica se a data é válida
                throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 31, the month must be between 1 and 12 and the year must be between 1951 and the current year.");
            }
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){    // Verifica se o ano é bissexto
                if (month == 2 && day > 29) {    // Verifica se o dia é válido para o mês de fevereiro em um ano bissexto
                    throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 29.");
                }
            }
            else{
                if (month == 2 && day > 28) {    // Verifica se o dia é válido para o mês de fevereiro
                    throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 28.");
                }
            }
            if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){    // Verifica se o dia é válido para os meses de 30 dias
                throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 30.");
            }
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){    // Verifica se o dia é válido para os meses de 31 dias
                throw std::out_of_range("The date is out of a valid range. The day must be between 1 and 31.");
            }
            break;
        }catch(const std::exception& e){    // Caso a data não seja válida, pede para tentar novamente
            std::cerr << " Please try again." << std::endl;
        }
    }
    std::string strday = std::to_string(day), strmonth = std::to_string(month), stryear = std::to_string(year);
    if(strday.size() == 1) strday = "0" + strday;
    if(strmonth.size() == 1) strmonth = "0" + strmonth;
    if(stryear.size() == 1) stryear = "0" + stryear;
    std::string releaseDate = strday + '/' + strmonth + '/' + stryear;
    return releaseDate;
}

void add_client(std::string &username, std::string &email, std::string &password,int &ID, std::string &cpf, std::string &birthdate){
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    json novoUsuario;
    novoUsuario["Username"] = username;
    novoUsuario["Email"] = email;
    novoUsuario["Password"] = password;
    novoUsuario["ID"] = ID;
    novoUsuario["CPF"] = cpf;
    novoUsuario["Balance"] = 0.0;
    novoUsuario["Jogos"] = {};
    novoUsuario["Wishlist"] = {};
    novoUsuario["Birthdate"] = birthdate;
    novoUsuario["Publicacoes"] = {};

    dadosJSON.push_back(novoUsuario);

    std::ofstream arquivoSaida("clients.json");
    arquivoSaida << dadosJSON.dump(7);
    arquivoSaida.close();
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
    // return;
}

void ClientDB::do_register()
{
    std::string name, email, password, cpf, birthdate;
    int ID;
    while(true)
    {
        std::cout << "Voce deseja registrar-se como Usuario ou como um desenvolvedor?\n";
        std::cout << "1 - Usuario\n";
        std::cout << "2 - Desenvolvedor\n";
        int op;
        std::cin >> op;
        std::cin.ignore();
            if (op == 1){
                ID = 1;
                break;
            }else if (op == 2){
                ID = 10;
                break;
            }else{
                std::cout << "Opcao invalida tente novamente\n";
                continue;
            }
    }
    name = input_username();
    email = input_email();
    if (!exist_username(name) && !exist_email(email))
    {
        password = input_password();
        cpf = input_cpf();
        //balance = 0
        birthdate = verify_date();
        // ID
        add_client(name, email, password, ID, cpf, birthdate);
    }
    else
        std::cout << "Usuario ja cadastrado\n";
        //falta colocar o que fazer se for cadatrado
}