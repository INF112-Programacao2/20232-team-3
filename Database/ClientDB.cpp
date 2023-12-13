#include "ClientDB.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

void change_clientValue(std::string key, std::string value, std::string username)   // Função que altera um valor do cliente no banco de dados
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open())           // Verifica se o arquivo foi aberto corretamente
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
            std::string usernameJSON = data["Username"];    // Pega o username do cliente

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username)    
            {
                data[key] = value;  // Altera o valor do cliente
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

void change_clientValue(std::string key, double value, std::string username)    // Função que altera um valor do cliente no banco de dados
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) //verifica se o arquivo foi aberto corretamente     
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array())   //verifica se o arquivo é um array   
    {
        for (auto& data : dadosJSON)    //pecorre o array 
        {
            std::string usernameJSON = data["Username"];    // Pega o username do cliente

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) 
            {
                data[key] = value;      // Altera o valor do cliente
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

bool ClientDB::exist_username(std::string &username)    // Função que verifica se o username já existe
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) {   // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array()) { // Verifica se o arquivo é um array
        for (const auto& data : dadosJSON) {    // Percorre o array
            std::string usernameJSON = data["Username"];    // Pega o username do cliente

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username) { 
                return true;
            }
        }
    }
    return false;
}

bool ClientDB::exist_email(std::string &email)  // Função que verifica se o email já existe
{
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) {   // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array()) { // Verifica se o arquivo é um array
        for (const auto& data : dadosJSON) {    // Percorre o array
            std::string emailJSON = data["Email"];  // Pega o email do cliente

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (emailJSON == email) {
                return true;
            }
        }
    }
    return false;
}

void ClientDB::edit_info(Client* client)    // Função que permite que o usuario veja seus dados e edite eles
{
    int aux;
    std::string temp, temp2;
    std::cout << "O que deseja alterar?\n1 - Username;\n2 - Password;\n3 - Email;\n4 - Voltar\n";   // Menu de opções
    std::cin >> aux;
    switch (aux)
    {
        case 1:
            while (true)
            {
                std::cout << "Digite seu novo nome de usuário: ";
                std::cin >> temp;   // Pega o novo nome de usuário
                if(temp.size() > 30)    // Verifica se o nome de usuário é válido
                {
                    std::cout << "Nome de usuário muito grande, digite novamente\n";
                }
                else if(exist_username(temp))   // Verifica se o nome de usuário já existe
                {
                    std::cout << "Nome de usuário já existente, digite novamente\n";
                }
                else    // Caso o nome de usuário seja válido
                {
                    change_clientValue("Username", temp, client->get_username());   // Altera o nome de usuário no banco de dados
                    client->set_username(temp); // Altera o nome de usuário no objeto
                    break;
                }
            }
        break;
        case 2:
            while (true)
            {
                std::cout << "Digite sua senha antiga: ";
                std::cin >> temp;   // Pega a senha antiga
                if(temp == client->get_password())  // Verifica se a senha antiga está correta
                {
                    std::cout << "Digite sua nova senha: ";
                    std::cin >> temp2;  // Pega a nova senha

                    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
                    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
                    {
                        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                    }

                    json dadosJSON; // Cria um objeto JSON
                    arquivo >> dadosJSON;   // Lê o arquivo JSON
                    arquivo.close();    // Fecha o arquivo

                    change_clientValue("Password", temp2, client->get_username());  // Altera a senha no banco de dados
                    client->set_password(temp); // Altera a senha no objeto
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
                std::cin >> temp;   // Pega o novo email
                if(temp.size() > 30)    // Verifica se o email é válido
                {
                    std::cout << "E-mail muito grande, digite novamente\n";
                }
                else if(exist_email(temp))  // Verifica se o email já existe
                {
                    std::cout << "E-mail já existente, digite novamente\n";
                }
                else        // Caso o email seja válido
                {
                    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
                    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
                    {
                        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                    }

                    json dadosJSON; // Cria um objeto JSON
                    arquivo >> dadosJSON;   // Lê o arquivo JSON
                    arquivo.close();    // Fecha o arquivo

                    change_clientValue("Email", temp, client->get_username());  // Altera o email no banco de dados
                    client->set_email(temp);    // Altera o email no objeto
                    break;
                }
            }
        break;
    }
}

void ClientDB::redeem_balance(Developer* dev)   // Função que permite que o usuario veja seu saldo atual e resgate um valor
{
    while (true)
    {
        std::cout << "Seu saldo atual é de: R$" << dev->get_balance() << '\n';  // Printa o saldo atual
        std::cout << "Digite o valor que deseja resgatar: ";    
        double aux;
        std::cin >> aux;    // Pega o valor que o usuario deseja resgatar
        if(aux > dev->get_balance())    // Verifica se o valor é maior que o saldo atual
        {
            std::cout << "Valor maior que o saldo atual, tente novamente\n";
        }
        else if (aux < 0)   // Verifica se o valor é válido
        {
            std::cout << "Valor inválido, tente novamente\n";
        }
        else    // Caso o valor seja válido
        {

            std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
            if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
            {
                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
            }

            json dadosJSON; // Cria um objeto JSON
            arquivo >> dadosJSON;   // Lê o arquivo JSON
            arquivo.close();    // Fecha o arquivo

            dev->set_balance(dev->get_balance() - aux);  // Altera o saldo no objeto
            change_clientValue("Balance", dev->get_balance(), dev->get_username());  // Altera o saldo no banco de dados
            break;      
        }
    }
    
}

void ClientDB::add_balance(User* usr)   // Função que permite que o usuario veja seu saldo atual e resgate um valor
{
    while (true)
    {
        std::cout << "Seu saldo atual é de: R$" << usr->get_balance() << '\n';  // Printa o saldo atual
        std::cout << "Digite o valor que deseja adicionar: ";
        double aux;
        std::cin >> aux;    // Pega o valor que o usuario deseja adicionar
        if (aux < 0)    // Verifica se o valor é válido
        {
            std::cout << "Valor inválido, tente novamente\n";
        }
        else    // Caso o valor seja válido
        {

            std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
            if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
            {
                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
            }

            json dadosJSON; // Cria um objeto JSON
            arquivo >> dadosJSON;   // Lê o arquivo JSON
            arquivo.close();    // Fecha o arquivo

            usr->set_balance(usr->get_balance() + aux); // Altera o saldo no objeto
            change_clientValue("Balance", usr->get_balance(), usr->get_username()); // Altera o saldo no banco de dados
            break;
        }
    }
}

std::string input_username()    // Função que pega o nome de usuário
{
    std::string _username;  // Variável que armazena o nome de usuário
    std::cout << "Digite seu nome de usuário: ";
    while (true)
    {
        try{
            std::getline(std::cin, _username);  // Pega o nome de usuário
            if(_username.empty())   // Verifica se o nome de usuário é vazio
                throw std::invalid_argument("Nome de usuário vazio.\n");
            if(_username.size() > 30)   // Verifica se o nome de usuário é válido
                throw std::out_of_range("Nome de usuário muito grande.\n");
            break;
        } catch(const std::exception& e){
            std::cerr << e.what() << " Digite novamente: ";
        } 
    }
    return _username;   // Retorna o nome de usuário
}

std::string input_email()   // Função que pega o email
{
    std::string _email; // Variável que armazena o email
    std::cout << "Digite seu email: ";
    bool has = false;
    while (true)
    {
        try{
            std::getline(std::cin, _email); // Pega o email
            if(_email.empty()){ // Verifica se o email é vazio
                throw std::invalid_argument("Email vazio.\n");
            }
            if(_email.size() > 30){ // Verifica se o email é válido
                throw std::out_of_range("Email muito grande.\n");
            }
            for (auto e: _email){   // Verifica se o email é válido
                if(e == '@')    
                {
                    has = true;
                }
            }
            if(!has){   // Verifica se o email é válido
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

std::string input_password()    // Função que pega a senha
{
    std::string _password;  // Variável que armazena a senha
    std::string temp;   // Variável auxiliar
    bool hasdigit = false, hasalpha = false;
    while (true){
        try{
            std::cout << "Digite sua senha: ";
            std::cin >> _password;  // Pega a senha
            std::cout << "Digite sua senha novamente: ";
            std::cin >> temp;   // Pega a senha novamente

            if(_password != temp){  // Verifica se as senhas coincidem
                throw std::invalid_argument("As senhas não coincidem. ");
            }

            for(auto e: _password){ // Verifica se a senha é válida
                if(std::isdigit(e)){    
                    hasdigit = true;
                }
                if(std::isalpha(e)){    
                    hasalpha = true;
                }
            }
            if(!hasdigit || !hasalpha)  // Verifica se a senha é válida
                throw std::invalid_argument("Senha muito fraca, ela deve ter pelo menos um número e uma letra.");
    
            break;
        } catch(const std::exception& e){
            std::cerr << e.what() << " Por favor tente novamente.\n";
        }
    }
    return _password;
}

std::string input_cpf() // Função que pega o CPF
{
    std::string _cpf;   // Variável que armazena o CPF
    while (true){
        try{
            std::cout << "Digite seu CPF: ";
            std::cin >> _cpf;   // Pega o CPF
            if(_cpf.empty()){   // Verifica se o CPF é vazio
                throw std::invalid_argument("O CPF nao pode ser vazio.");
            }
            if(_cpf.size() != 11){  // Verifica se o CPF é válido
                throw std::out_of_range("O CPF deve ter 11 digitos.");
            }
            for(auto e: _cpf){  // Verifica se o CPF é válido
                if(!std::isdigit(e)){   
                    throw std::invalid_argument("O CPF so pode ter numeros.");
                }
            }
            for(int i = 0; i < 10; i++){    // Verifica se o CPF é válido
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
    std::string strday = std::to_string(day), strmonth = std::to_string(month), stryear = std::to_string(year); // Converte os inteiros para string
    if(strday.size() == 1) strday = "0" + strday;
    if(strmonth.size() == 1) strmonth = "0" + strmonth;
    if(stryear.size() == 1) stryear = "0" + stryear;
    std::string releaseDate = strday + '/' + strmonth + '/' + stryear;  // Concatena as strings
    return releaseDate;
}

// Função que adiciona um cliente ao banco de dados
void add_client(std::string &username, std::string &email, std::string &password,int &ID, std::string &cpf, std::string &birthdate){    
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) {   // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    json novoUsuario;   // Cria um novo objeto JSON
    novoUsuario["Username"] = username; // Adiciona o nome de usuário ao objeto
    novoUsuario["Email"] = email;   // Adiciona o email ao objeto
    novoUsuario["Password"] = password; // Adiciona a senha ao objeto
    novoUsuario["ID"] = ID; // Adiciona o ID ao objeto
    novoUsuario["CPF"] = cpf;   // Adiciona o CPF ao objeto
    novoUsuario["Balance"] = 0.0;   // inicializa o saldo ao objeto
    novoUsuario["Jogos"] = {};  // Inicializa os jogos ao objeto
    novoUsuario["Wishlist"] = {};   // Inicializa a lista de desejos ao objeto
    novoUsuario["Birthdate"] = birthdate;   // Adiciona a data de nascimento ao objeto
    novoUsuario["Publicacoes"] = {};    // Inicializa as publicações ao objeto

    dadosJSON.push_back(novoUsuario);   // Adiciona o novo objeto ao array

    std::ofstream arquivoSaida("clients.json"); // Abre o arquivo JSON
    arquivoSaida << dadosJSON.dump(7);  // Escreve no arquivo JSON
    arquivoSaida.close();   // Fecha o arquivo
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
}

void ClientDB::do_register()    // Função que registra um cliente no banco de dados
{
    std::string name, email, password, cpf, birthdate;  // Variáveis que armazenam os dados do cliente
    int ID;
    while(true)
    {
        std::cout << "Voce deseja registrar-se como Usuario ou como um desenvolvedor?\n";   // Menu de opções
        std::cout << "1 - Usuario\n";
        std::cout << "2 - Desenvolvedor\n";
        int op;
        std::cin >> op; // Pega a opção
        std::cin.ignore();
            if (op == 1){   
                ID = 1;     // Define o ID do cliente
                break;
            }else if (op == 2){
                ID = 10;    // Define o ID do desenvolvedor
                break;
            }else{
                std::cout << "Opcao invalida tente novamente\n";
                continue;
            }
    }
    name = input_username();    // Pega o nome de usuário
    email = input_email();  // Pega o email
    if (!exist_username(name) && !exist_email(email))   // Verifica se o nome de usuário e o email já existem
    {
        password = input_password();    // Pega a senha
        cpf = input_cpf();  // Pega o CPF
        birthdate = verify_date();  // Pega a data de nascimento
        add_client(name, email, password, ID, cpf, birthdate);  // Adiciona o cliente ao banco de dados
    }
    else
        std::cout << "Usuario ja cadastrado\n";
}

void search_game2(std::string &game, std::vector<Game> &games){   // Função que procura um jogo no banco de dados
    std::ifstream arquivo("games.json");    // Abre o arquivo JSON
    if (!arquivo.is_open())     // Verifica se o arquivo foi aberto corretamente
    {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array()) { // Verifica se o arquivo é um array
        for (auto& data : dadosJSON) {  // Percorre o array
            std::string gameJSON = data["Name"];    // Pega o nome do jogo
            if (gameJSON == game)   // Verifica se o nome do jogo é igual ao nome do jogo procurado
            {
                std::string name = data["Name"];    // Pega o nome do jogo
                std::string platform = data["Platform"];    // Pega a plataforma do jogo
                std::string release_date = data["Release Date"];    // Pega a data de lançamento do jogo
                std::string studio = data["Studio"];    // Pega o estúdio do jogo
                int age = data["Age Rating"];   // Pega a classificação indicativa do jogo
                bool available = data["Availability"].get<int>();   // Pega a disponibilidade do jogo
                int directx = data["DirectX"];  // Pega o directx do jogo
                double price = data["Price"];   //pega o preço do jogo
                std::string gender = data["Gender"];    // Pega o gênero do jogo
                std::string graphics =data["Graphics"]; // Pega a placa de vídeo do jogo
                std::string language = data["Language"];    // Pega o idioma do jogo
                std::string memory = data["Memory"];    // Pega a memória do jogo
                std::string os = data["OS"];    // Pega o sistema operacional do jogo
                std::string processor = data["Processor"];  // Pega o processador do jogo
                std::string storage = data["Storage"];  // Pega o armazenamento do jogo
                std::vector <std::string> review;   // Vetor que armazena as reviews do jogo
                for(auto& rev : data["Review"]) // Percorre o array de reviews
                {
                    review.push_back(rev);  // Adiciona a review ao vetor
                }   
                // Cria um objeto do tipo jogo
                Game jogo(name, studio, age, price, available, review, release_date, gender, platform, language, os, processor, memory, graphics, directx, storage);    
                games.push_back(jogo);  // Adiciona o jogo ao vetor
            }
        }
    }
}

static Client* CreateaclientfromJson(std::string username)  // Função que cria um cliente a partir do banco de dados
{
    std::vector <Game> wishlist;    // Vetor que armazena a lista de desejos
    std::vector <Game> library; // Vetor que armazena a biblioteca de jogos
    std::vector <Game> published_games; // Vetor que armazena os jogos publicados
    std::string jogo;   // Variável que armazena o nome do jogo
    std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
    if (!arquivo.is_open()) {   // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
    }

    json dadosJSON; // Cria um objeto JSON
    arquivo >> dadosJSON;   // Lê o arquivo JSON
    arquivo.close();    // Fecha o arquivo

    if (dadosJSON.is_array()) { // Verifica se o arquivo é um array
        for (const auto& data : dadosJSON)  // Percorre o array
        {
            if (data["Username"] == username)   // Verifica se o nome de usuário é igual ao nome de usuário procurado
            {
                double balance = data["Balance"].get<double>(); // Pega o saldo do cliente
                std::string cpf = data["CPF"];  // Pega o CPF do cliente      
                std::string email = data["Email"];      // Pega o email do cliente
                int id = data["ID"].get<int>();    // Pega o ID do cliente
                std::string password = data["Password"];      // Pega a senha do cliente
                std::string username = data["Username"];    // Pega o nome de usuário do cliente
                std::string birthdate = data["Birthdate"];  // Pega a data de nascimento do cliente

                if (data["ID"] == 1)    // Verifica se o cliente é um usuário ou um desenvolvedor
                {
                    for (const auto& games : data["Jogos"]){    // Percorre o array de jogos
                        jogo = games;   // Pega o nome do jogo
                        search_game2(jogo, library);    // Procura o jogo no banco de dados
                    }
                    for (const auto& games : data["Wishlist"]){ // Percorre o array de jogos
                        jogo = games;   // Pega o nome do jogo
                        search_game2(jogo, wishlist);   // Procura o jogo no banco de dados
                    }
                    // Cria um objeto do tipo usuário
                    return new User(username, password, email, cpf, balance, birthdate,  library, wishlist);    
                }else
                {
                    for (const auto& games : data["Publicacoes"]){  // Percorre o array de jogos
                        jogo = games;   // Pega o nome do jogo
                        search_game2(jogo, published_games);    // Procura o jogo no banco de dados
                    }
                    // Cria um objeto do tipo desenvolvedor
                    return new Developer(username, password, email, cpf, balance, birthdate, published_games);
                }
            }
        }
    }
    return nullptr; // Retorna nullptr caso o cliente não seja encontrado
}

Client* ClientDB::do_login()    // Função que faz o login do cliente
{
    std::string username;   // Variável que armazena o nome de usuário
    std::string password;   // Variável que armazena a senha
    while(true)
    {
        std::cout << "Digite seu nome de usuario\n";    
        std::cin >> username;   // Pega o nome de usuário
        std::cout << "Digite sua senha\n";
        std::cin >> password;   // Pega a senha
        if(exist_username(username))    // Verifica se o nome de usuário existe
        {
            std::ifstream arquivo("clients.json");  // Abre o arquivo JSON
            if (!arquivo.is_open()) {   // Verifica se o arquivo foi aberto corretamente
                std::cerr << "Erro ao abrir o arquivo JSON.1" << std::endl;
            }

            json dadosJSON; // Cria um objeto JSON
            arquivo >> dadosJSON;   // Lê o arquivo JSON
            arquivo.close();    // Fecha o arquivo

            if (dadosJSON.is_array()) { // Verifica se o arquivo é um array
                for (const auto& data : dadosJSON) {    // Percorre o array
                    std::string usernameJSON = data["Username"];    // Pega o nome de usuário do cliente

                    // Verifique se o nome e o usuário correspondem aos fornecidos
                    if (usernameJSON == username && data["Password"] == password) { // Verifica se a senha está correta
                        std::cout << "Login efetuado com sucesso\n";
                        return CreateaclientfromJson(username); // Cria o cliente a partir do banco de dados
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