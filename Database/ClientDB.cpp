#include "../Auxiliar/Input.hpp"
#include "ClientDB.hpp"

#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

void change_clientValue(std::string key, std::string value, std::string username) // AUXILIAR
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

void change_clientValue(std::string key, double value, std::string username) // AUXILIAR
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

// INPUT USERNAME
// INPUT EMAIL
// INPUT PASSWORD
// INPUT CPF
// VERIFY DATE

void add_client(std::string &username, std::string &email, std::string &password,int &ID, std::string &cpf, std::string &birthdate) // AUXILIAR
{
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
    name = Input::input_name("Digite seu nome de usuário: ", 30);
    email = Input::input_email("Digite seu nome de email: ");
    if (!exist_username(name) && !exist_email(email))
    {
        password = Input::input_password();
        cpf = Input::input_cpf();
        //balance = 0
        birthdate = Input::input_date("Digite sua data de nascimento:");
        // ID
        add_client(name, email, password, ID, cpf, birthdate);
    }
    else
        std::cout << "Usuario ja cadastrado\n";
        //falta colocar o que fazer se for cadatrado
}

void search_game2(std::string &game, std::vector<Game> &games) // AUXILIAR
{
    std::ifstream arquivo("games.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (auto& data : dadosJSON) {
            std::string gameJSON = data["Name"];
            if (gameJSON == game)
            {
                std::string name = data["Name"];
                std::string platform = data["Platform"];
                std::string release_date = data["Release Date"];
                std::string studio = data["Studio"];
                int age = data["Age Rating"];
                bool available = data["Availability"].get<int>();
                int directx = data["DirectX"];
                double price = data["Price"];
                std::string gender = data["Gender"];
                std::string graphics =data["Graphics"];
                std::string language = data["Language"];
                std::string memory = data["Memory"];
                std::string os = data["OS"];
                std::string processor = data["Processor"];
                std::string storage = data["Storage"];
                std::vector <std::string> review;
                for(auto& rev : data["Review"])
                {
                    review.push_back(rev);
                }
                Game jogo(name, studio, age, price, available, review, release_date, gender, platform, language, os, processor, memory, graphics, directx, storage);
                games.push_back(jogo);
            }
        }
    }
}

static Client* CreateaclientfromJson(std::string username)
{
    std::vector <Game> wishlist;
    std::vector <Game> library;
    std::vector <Game> published_games;
    std::string jogo;
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) 
        {
            if (data["Username"] == username)
            {
                //std::cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n";
                double balance = data["Balance"].get<double>();
                std::string cpf = data["CPF"];
                std::string email = data["Email"];
                int id = data["ID"].get<int>();
                std::string password = data["Password"];
                std::string username = data["Username"];
                std::string birthdate = data["Birthdate"];

                if (data["ID"] == 1)
                {
                    for (const auto& games : data["Jogos"]){
                        jogo = games;
                        search_game2(jogo, library);
                    }
                    for (const auto& games : data["Wishlist"]){
                        jogo = games;
                        search_game2(jogo, wishlist);
                    }
                    return new User(username, password, email, cpf, balance, birthdate,  library, wishlist);
                }else
                {
                    for (const auto& games : data["Publicacoes"]){
                        jogo = games;
                        search_game2(jogo, published_games);
                    }
                    return new Developer(username, password, email, cpf, balance, birthdate, published_games);
                }
            }
        }
    }
    return nullptr;
}

Client* ClientDB::do_login()
{
    std::string username;
    std::string password;
    while(true)
    {
        std::cout << "Digite seu nome de usuario\n";
        std::cin >> username;
        std::cout << "Digite sua senha\n";
        std::cin >> password;
        if(exist_username(username))
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
                    if (usernameJSON == username && data["Password"] == password) {
                        std::cout << "Login efetuado com sucesso\n";
                        return CreateaclientfromJson(username);
                    }
                    else
                    {
                        std::cout << "Senha incorreta, tente novamente. \n";
                        continue;
                    }
                }
            }
        }
    }   
}