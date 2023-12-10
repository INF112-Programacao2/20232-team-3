#include "ClientDB.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;


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

void ClientDB::edit_info(Developer* dev)
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

                    if (dadosJSON.is_array()) 
                    {
                        for (auto& data : dadosJSON) 
                        {
                            std::string usernameJSON = data["Username"];

                            // Verifique se o nome e o usuário correspondem aos fornecidos
                            if (usernameJSON == dev->get_username()) 
                            {
                                data["Username"] = temp;
                                std::ofstream arquivoSaida("clients.json");
                                arquivoSaida << dadosJSON.dump(10);
                                arquivoSaida.close();
                                dev->set_username(temp);
                                return;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
                    }
                }
            }
        break;
        case 2:
            while (true)
            {
                std::cout << "Digite sua senha antiga: ";
                std::cin >> temp;
                if(temp == dev->get_password())
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

                    if (dadosJSON.is_array()) 
                    {
                        for (auto& data : dadosJSON) 
                        {
                            std::string usernameJSON = data["Username"];

                            // Verifique se o nome e o usuário correspondem aos fornecidos
                            if (usernameJSON == dev->get_username()) 
                            {
                                data["Password"] = temp2;
                                std::ofstream arquivoSaida("clients.json");
                                arquivoSaida << dadosJSON.dump(10);
                                arquivoSaida.close();
                                dev->set_password(temp2);
                                return;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
                    }

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

                    if (dadosJSON.is_array()) 
                    {
                        for (auto& data : dadosJSON) 
                        {
                            std::string emailJSON = data["Email"];

                            // Verifique se o email do usuario corresponde ao fornecidos
                            if (emailJSON == dev->get_email()) 
                            {
                                data["Email"] = temp;
                                std::ofstream arquivoSaida("clients.json");
                                arquivoSaida << dadosJSON.dump(10);
                                arquivoSaida.close();
                                dev->set_email(temp);
                                return;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
                    }
                }
            }
        break;
    }
}

