#include "ClientDB.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void change_value(std::string key, std::string value, std::string username)
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

void change_value(std::string key, double value, std::string username)
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

bool ClientDB::exist_userName(std::string &username)
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
                else if(exist_userName(temp))
                {
                    std::cout << "Nome de usuário já existente, digite novamente\n";
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

                    change_value("Username", temp, client->get_username());
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

                    change_value("Password", temp2, client->get_username());
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

                    change_value("Email", temp, client->get_username());
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
            change_value("Balance", dev->get_balance(), dev->get_username());
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
            change_value("Balance", usr->get_balance(), usr->get_username());
            break;
        }
    }
}