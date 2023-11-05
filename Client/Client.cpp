#include"Client.hpp"

bool checkCPF(const std::string& cpf) 
{
    int som1 = 0;
    int som2 = 0;

    for (int i = 0; i < 9; i++) {
        int digit = cpf[i] - '0';
        som1 += digit * (10 - i);
        som2 += digit * (11 - i);
    }

    int firstCheckerDigit = (som1 * 10) % 11;
    int secondCheckerDigit = (som2 * 10) % 11;

    if (firstCheckerDigit == 10)
        firstCheckerDigit = 0;
    if (secondCheckerDigit == 10)
        secondCheckerDigit = 0;

    return (firstCheckerDigit == cpf[9] - '0' && secondCheckerDigit == cpf[10] - '0');
}

bool checkCNPJ(const std::string& cnpj) 
{

    int multiplier[] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
    int multiplier[] = {6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

    int som1 = 0;
    int som2 = 0;

    for (int i = 0; i < 12; i++) {
        int digit = cnpj[i] - '0';
        som1 += digit * multiplier[i];
        som2 += digit * multiplier[i];
    }

    int firstCheckerDigit = (som1 % 11 < 2) ? 0 : (11 - som1 % 11);
    int secondCheckerDigit = (som2 % 11 < 2) ? 0 : (11 - som2 % 11);

    return (firstCheckerDigit == cnpj[12] - '0' && secondCheckerDigit == cnpj[13] - '0');
}


Client::Client(std::string username, std::string password, std::string email, Date birthdate, int id)
{
    if(username.size()>30 || get_age() < 12 || (id != 1 && id != 2)) // Se o username tiver mais de 30 caracteres, se o usuário tiver menos de 12 anos ou se o id não for 1 ou 2
        std::cout << "Erro ao criar conta\n";
    else
    {
        this->_username = username;
        this->_password = password;
        this->_email = email;
        this->_birthdate = birthdate;
        this->_id = id;
        this->_balance = 0;
    }
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

void Client::change_password(std::string old_password, std::string new_password)
{
    if(old_password == _password)
        _password = new_password;
    else
        std::cout << "Senha incorreta\n";
}