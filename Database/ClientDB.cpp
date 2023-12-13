#include "../Auxiliar/Input.hpp"
#include "ClientDB.hpp"

#include <iostream>
#include <fstream>
#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;    

void change_clientValue(std::string key, std::string value, std::string username) // Função auxiliar - Muda um valor string de um cliente no json
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())            // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o arquivo é um array 
    {
        for (auto& data : dadosJSON)    // Percorre o array
        {
            std::string usernameJSON = data["Username"];    // Pega o username do arquivo JSON

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username)   // Verifica se o username do arquivo JSON é igual ao username fornecido
            {
                data[key] = value;  // Muda o valor da chave para o valor fornecido
                std::ofstream arquivoSaida("clients.json"); // Abre o arquivo JSON
                arquivoSaida << dadosJSON.dump(10); // Escreve no arquivo JSON
                arquivoSaida.close();   // Fecha o arquivo
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

void change_clientValue(std::string key, double value, std::string username) // Função auxiliar - Muda um valor double de um cliente no json
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())     // verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   //verifica se o tipo json é um array        
    {
        for (auto& data : dadosJSON)    //pecorre o array        
        {
            std::string usernameJSON = data["Username"];    // Pega o username do arquivo JSON

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) 
            {
                data[key] = value;  // Muda o valor da chave para o valor fornecido
                std::ofstream arquivoSaida("clients.json"); // Abre o arquivo JSON
                arquivoSaida << dadosJSON.dump(10); // Escreve no arquivo JSON
                arquivoSaida.close();   // Fecha o arquivo
                return;
            }
        }
    }
    else
    {
        std::cout << "Ocorreu algum erro inesperado, tente novamente" << std::endl;
    }
}

bool username_exist(std::string &username) // Função auxiliar - Retorna se um username existe em clients.json
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o arquivo é um array
    {
        for (const auto& data : dadosJSON)  // Percorre o array
        {
            std::string usernameJSON = data["Username"];    // Pega o username do arquivo JSON

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) 
            {
                return true;
            }
        }
    }
    return false;
}

bool email_exist(std::string &email) // Função auxiliar - Retorna se um email existe em clients.json
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())    // Verifica se o arquivo foi aberto corretamente 
    {
        std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   // Verifica se o arquivo é um array
    {
        for (const auto& data : dadosJSON)  // Percorre o array
        {
            std::string emailJSON = data["Email"];  // Pega o email do arquivo JSON

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (emailJSON == email)     
            {
                return true;
            }
        }
    }
    return false;
}

void ClientDB::edit_info(Client* client)    // Edita as informações do cliente
{
    int aux;
    std::string temp, temp2;
    std::cout << "O que deseja alterar?\n1 - Username;\n2 - Password;\n3 - Email;\nAperte qualquer outra tecla para voltar\n";
    std::cin >> aux;
    std::cin.ignore();
    switch (aux)
    {
        case 1:
            while (true)
            {
                temp = Input::input_name("Digite seu novo nome de usuário: ", 30);      // Recebe o novo username
                if(username_exist(temp))    // Verifica se o username já existe
                {
                    std::cout << "Nome de usuário já existente, digite novamente\n";
                }
                else
                {
                    change_clientValue("Username", temp, client->get_username());   // Muda o username no json
                    client->set_username(temp); // Muda o username no objeto
                    break;
                }
            }
        break;
        case 2:
            while (true)
            {
                std::cout << "Digite sua senha antiga: ";
                std::cin >> temp;
                std::cin.ignore();
                if(temp == client->get_password())  // Verifica se a senha antiga está correta
                {
                    temp2 = Input::input_password();    // Recebe a nova senha

                    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
                    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
                    {
                        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                    }

                    json dadosJSON; // Cria um objeto JSON
                    arquivo >> dadosJSON;   // Lê o arquivo JSON
                    arquivo.close();    // Fecha o arquivo

                    change_clientValue("Password", temp2, client->get_username());  // Muda a senha no json
                    client->set_password(temp2);    // Muda a senha no objeto
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
                temp = Input::input_email("Digite seu novo email: ");   // Recebe o novo email
                if(email_exist(temp))   // Verifica se o email já existe
                {
                    std::cout << "E-mail já existente, digite novamente\n";
                }
                else
                {
                    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
                    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
                    {
                        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                    }

                    json dadosJSON; // Cria um objeto JSON
                    arquivo >> dadosJSON;   // Lê o arquivo JSON
                    arquivo.close();    // Fecha o arquivo

                    change_clientValue("Email", temp, client->get_username());  // Muda o email no json
                    client->set_email(temp);    // Muda o email no objeto
                    break;
                }
            }
        break;
    }
}

void ClientDB::redeem_balance(Developer* dev)   // Resgata o saldo do desenvolvedor
{
    while (true)
    {
        std::cout << "Seu saldo atual é de: R$" << dev->get_balance() << '\n';
        double aux;
        aux = Input::input_double("Digite o valor que deseja resgatar: ");  // Recebe o valor a ser resgatado
        if(aux > dev->get_balance())    // Verifica se o valor é maior que o saldo atual
        {
            std::cout << "Valor maior que o saldo atual, tente novamente\n";
        }
        else if (aux < 0)   // Verifica se o valor é negativo
        {
            std::cout << "Valor inválido, tente novamente\n";
        }
        else
        {

            std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
            if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
            {
                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
            }

            json dadosJSON; // Cria um objeto JSON
            arquivo >> dadosJSON;   // Lê o arquivo JSON
            arquivo.close();    // Fecha o arquivo

            dev->set_balance(dev->get_balance() - aux);  // Muda o saldo no objeto
            change_clientValue("Balance", dev->get_balance(), dev->get_username());  // Muda o saldo no json
            break;
        }
    }
    
}

void ClientDB::add_balance(User* usr)   // Adiciona saldo ao usuário
{
    while (true)
    {
        std::cout << "Seu saldo atual é de: R$" << usr->get_balance() << '\n';  // Imprime o saldo atual
        double aux;
        aux = Input::input_double("Digite o valor que deseja adicionar: ");
        if (aux < 0)    // Verifica se o valor é negativo
        {
            std::cout << "Valor inválido, tente novamente\n";
        }
        else
        {

            std::ifstream arquivo("clients.json");
            if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
            {
                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
            }

            json dadosJSON; // Cria um objeto JSON
            arquivo >> dadosJSON;   // Lê o arquivo JSON
            arquivo.close();    // Fecha o arquivo

            usr->set_balance(usr->get_balance() + aux); // Muda o saldo no objeto
            change_clientValue("Balance", usr->get_balance(), usr->get_username()); // Muda o saldo no json
            break;
        }
    }
}

void add_client(std::string &username, std::string &email, std::string &password,int &ID, std::string &cpf, std::string &birthdate) // AUXILIAR
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) {         // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;  
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;       // Lê o arquivo JSON
    arquivo.close();        // Fecha o arquivo

    json novoUsuario;
    novoUsuario["Username"] = username; // Adiciona o username ao json
    novoUsuario["Email"] = email;   // Adiciona o email ao json
    novoUsuario["Password"] = password; // Adiciona a senha ao json
    novoUsuario["ID"] = ID; // Adiciona o ID ao json
    novoUsuario["CPF"] = cpf;   // Adiciona o CPF ao json
    novoUsuario["Balance"] = 0.0;   // Adiciona o saldo ao json
    novoUsuario["Jogos"] = {};  // Adiciona a biblioteca de jogos ao json
    novoUsuario["Wishlist"] = {};   // Adiciona a lista de desejos ao json
    novoUsuario["Birthdate"] = birthdate;   // Adiciona a data de nascimento ao json
    novoUsuario["Publicacoes"] = {};    // Adiciona os jogos publicados ao json

    dadosJSON.push_back(novoUsuario);   // Adiciona o novo usuário ao array

    std::ofstream arquivoSaida("clients.json"); // Abre o arquivo JSON
    arquivoSaida << dadosJSON.dump(7);  // Escreve no arquivo JSON
    arquivoSaida.close();   // Fecha o arquivo
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
}

void ClientDB::do_register()    // Registra um novo cliente
{
    std::string name, email, password, cpf, birthdate;
    int ID;
    while(true)
    {   // Recebe o ID do cliente
        ID = Input::input_int("Voce deseja registrar-se como Usuario ou como um desenvolvedor?\n1 - Usuario\n2 - Desenvolvedor ", 1, 2);    
        if (ID == 1)    // Verifica se o ID é 1 ou 2
        {
            break;
        }
        else
        {
            ID = 10;    // ID de desenvolvedor
            break;
        }
    }
        name = Input::input_name("Digite seu nome de usuário: ", 30);   // Recebe o username
        email = Input::input_email("Digite seu nome de email: ");   // Recebe o email
        if (!username_exist(name) && !email_exist(email))   // Verifica se o username e o email já existem
        {
            password = Input::input_password(); // Recebe a senha
            cpf = Input::input_cpf();   // Recebe o CPF
            birthdate = Input::input_date("Digite sua data de nascimento:");    // Recebe a data de nascimento
            add_client(name, email, password, ID, cpf, birthdate);  // Adiciona o cliente ao json
        }
        else
            std::cout << "Usuario ja cadastrado\n";
}

static Client* load_client_from_json(std::string username)  // Carrega um cliente do json
{
    std::vector <Game> wishlist;    // Cria uma lista de desejos
    std::vector <Game> library; // Cria uma biblioteca de jogos
    std::vector <Game> published_games; // Cria uma lista de jogos publicados
    std::string jogo;   // Cria uma string para armazenar os jogos
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) {      // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array()) {    // Verifica se o arquivo é um array
        for (const auto& data : dadosJSON)  // Percorre o array
        {
            if (data["Username"] == username)       // Verifica se o username do arquivo JSON é igual ao username fornecido
            {  
                double balance = data["Balance"].get<double>(); // Pega o saldo do arquivo JSON
                std::string cpf = data["CPF"];  // Pega o CPF do arquivo JSON
                std::string email = data["Email"];  // Pega o email do arquivo JSON
                int id = data["ID"].get<int>(); // Pega o ID do arquivo JSON
                std::string password = data["Password"];    // Pega a senha do arquivo JSON
                std::string username = data["Username"];    // Pega o username do arquivo JSON
                std::string birthdate = data["Birthdate"];  // Pega a data de nascimento do arquivo JSON

                if (data["ID"] == 1)    // Verifica se o ID é 1 ou 10
                {
                    for (const auto& games : data["Jogos"]){    // Percorre a biblioteca de jogos
                        jogo = games;   // Armazena o jogo
                        load_game_from_json(jogo, library); // Carrega os jogos da biblioteca
                    }
                    for (const auto& games : data["Wishlist"]){ // Percorre a lista de desejos
                        jogo = games;   // Armazena o jogo
                        load_game_from_json(jogo, wishlist);    // Carrega os jogos da lista de desejos
                    }
                    return new User(username, password, email, cpf, balance, birthdate,  library, wishlist);    // Retorna um novo usuário
                }else
                {
                    for (const auto& games : data["Publicacoes"]){  // Percorre a lista de jogos publicados
                        jogo = games;
                        load_game_from_json(jogo, published_games); // Carrega os jogos da lista de jogos publicados
                    }
                    return new Developer(username, password, email, cpf, balance, birthdate, published_games);  // Retorna um novo desenvolvedor
                }
            }
        }
    }
    return nullptr; // Retorna nulo
}

Client* ClientDB::do_login()    // Faz o login do cliente
{
    std::string username;
    std::string password;
    while(true)
    {
        username = Input::input_name("Digite seu nome de usuário: ", 30);   // Recebe o username
        std::cout << "Digite sua senha: \n";
        std::cin >> password;   // Recebe a senha
        std::cin.ignore();
        if(username_exist(username))    // Verifica se o username existe
        {
            std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
            if (!arquivo.is_open()) {    // Verifica se o arquivo foi aberto corretamente
                std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
            }

            json dadosJSON; // Cria um objeto JSON
            arquivo >> dadosJSON;   // Lê o arquivo JSON
            arquivo.close();    // Fecha o arquivo

            if (dadosJSON.is_array()) {   // Verifica se o arquivo é um array
                for (const auto& data : dadosJSON) {    // Percorre o array
                    std::string usernameJSON = data["Username"];    // Pega o username do arquivo JSON

                    // Verifique se o nome e o usuário correspondem aos fornecidos
                    if (usernameJSON == username && data["Password"] == password) {  // Verifica se o username e a senha estão corretos
                        std::cout << "Login efetuado com sucesso\n";    // Imprime que o login foi efetuado com sucesso
                        return load_client_from_json(username); // Carrega o cliente do json
                    }
                    else if(usernameJSON == username)   // Verifica se o username está correto
                    {
                        std::cout << "Senha incorreta, tente novamente. \n";
                        continue;
                    }
                }
            }
        }
        else
        {
            std::cout << "Usuário não cadastrado, tente novamente\n";
            continue;}
    }   
}

void ClientDB::add_publication(Developer* dev, std::string game_name) // Adiciona uma publicação no json do usuário
{
    std::ifstream arquivo("clients.json");
    if (!arquivo.is_open()) 
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    bool existe = false;
    std::string jogo;
    for (auto& data : dadosJSON) 
    {
        if (data["Username"] == dev->get_username())
        {
            for (auto it = data["Publicacoes"].begin(); it != data["Publicacoes"].end(); ++it) 
                {
                    if (*it == game_name) 
                    {
                        existe = true;
                        std::cout << "Jogo já está na lista de publicaçoes\n";
                        break;
                    } 
                }
                // Adiciona à wishlist no objeto
                if(!existe)
                {
                    data["Publicacoes"].push_back(game_name);
                }
            }
        }
    std::ofstream arquivoSaida("clients.json");
    arquivoSaida << dadosJSON.dump(10);
    arquivoSaida.close();
    }