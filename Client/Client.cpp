#include"Client.hpp"
/*
bool checkCPF(const std::string& cpf) 
{
    if(cpf.size()!=11)
        return false;
    return true;
}

bool checkCNPJ(const std::string& cnpj) 
{
    if(cnpj.size()!=12)
        return false;
    return true;
}
*/
/*
Client::Client()
{
    while (true)
    {
        std::cout << "Digite seu nome de usuário: ";
        std::cin >> _username;
        if(_username.size() > 30)
        {
            std::cout << "Nome de usuário muito grande, digite novamente\n";
        }
        else
            break;
    }
    while (true)
    {
        std::cout << "Digite sua senha: ";
        std::cin >> _password;
        std::string temp;
        std::cout << "Digite sua senha novamente: ";
        std::cin >> temp;

        if(_password != temp)
        {
            std::cout << "As senhas não coincidem, digite novamente\n";
            continue;
        }
        else
        {
            bool hasNumber = false, hasLetter = false;
            for(auto e: _password)
            {
                if(e >= '0' && e <= '9')
                    hasNumber = true;
                else if((e >= 'a' && e <= 'z') || (e >= 'A' && e <= 'Z'))
                    hasLetter = true;
            }
            if(!(hasNumber && hasLetter))
            {
                std::cout << "Senha muito fraca, ela deve ter pelo menos uma letra e um número\n";
                continue;
            }
            else
                break;
        }
    }
    while (true)
    {
        std::cout << "Digite seu email: ";
        std::cin >> _email;
        bool hasAt = false;
        for (auto e: _email)
        {
            if(e == '@')
            {
                hasAt = true;
                break;
            }
        }
        if(hasAt)
            break;
        
    }
    while (true)
    {
        std::cout << "Digite sua data de nascimento dd/mm/aaaa: ";
        char c;
        std::cin >> _birthdate.day >> c >> _birthdate.month >> c >> _birthdate.year;
        if (get_age() < 12)
        {
            std::cout << "Você deve ter pelo menos 12 anos para criar uma conta\n";
            continue;
        }
        else
            break;
    }
    while (true)
    {
        std::cout << "Você deseja criar uma conta como jogador ou desenvolvedor? (j/d)";
        char c;
        std::cin >> c;
        if(c == 'j' || c == 'J')
        {
            _id = 0;
            break;
        }
        else if(c == 'd' || c == 'D')
        {
                _id = 1;
                break;
        }
        else
        {
            std::cout << "Opção inválida, digite novamente\n";
            continue;
        }
    }
    _balance = 0;
}
*/

Client::Client(std::string username, std::string password, std::string email, std::string cpf, double balance, int id)
{
    _username = username;
    _password = password;
    _email = email;
    _cpf = cpf;
    _balance = balance;
    _id = id;
}

Client::~Client()
{
    
}

std::string Client::get_username()
{
    return _username;
}

std::string Client::get_email()
{
    return _email;
}

int Client::get_id()
{
    return _id;
}

int Client::get_age()
{
    std::time_t currentTime = std::time(nullptr);
    std::tm* currentDate = std::localtime(&currentTime);

    Date current;
    current.day = currentDate->tm_mday;
    current.month = currentDate->tm_mon+1;
    current.year = currentDate->tm_year+1900;

    int age = current.year - _birthdate.year;
    if(current.month < _birthdate.month)
        age--;
    else if(current.month == _birthdate.month)
        if(current.day < _birthdate.day)
            age--;
    return age;
}

double Client::get_balance()
{
    return _balance;
}

std::string Client::get_cpf()
{
    return _cpf;
}