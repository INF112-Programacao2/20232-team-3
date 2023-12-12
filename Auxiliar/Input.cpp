#include"Input.hpp"

std::string Input::input_name(std::string text, int limit)
{
    std::string name;
    std::cout << text << std::endl;
    while (true)
    {
        try
        {
            std::getline(std::cin, name);
            if(name.empty())
            {
                throw std::invalid_argument("Nome vazio.");
            }
            if(name.size() > limit)
            {
                throw std::out_of_range("Nome muito grande.");
            }
            break;
        } 
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " Digite novamente: ";
        } 
    }
    return name;
}

std::string Input::input_name(std::string text)
{
    std::string name;
    std::cout << text << std::endl;
    while (true)
    {
        try
        {
            std::getline(std::cin, name);
            if(name.empty())
            {
                throw std::invalid_argument("Nome vazio.");
            }
            break;
        } 
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " Digite novamente: ";
        } 
    }
    return name;
}

std::string Input::input_email(std::string text)
{
    std::string email;
    bool hasAtSign = false;
    std::cout << text;
    while (true)
    {
        try{
            std::getline(std::cin, email);
            if(email.empty())
            {
                throw std::invalid_argument("Email vazio.");
            }
            if(email.size() > 30)
            {
                throw std::out_of_range("Email muito grande.");
            }
            for (const char c: email)
            {
                if(c == '@')
                {
                    hasAtSign = true;
                }
            }
            if(!hasAtSign)
            {
                throw std::invalid_argument("Email inválido.");
            }
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " Digite novamente: ";
        }
    }
    return email;
}

std::string Input::input_password()
{
    std::string password;
    std::string password2;
    bool hasdigit = false, hasalpha = false;
    while (true)
    {
        try
        {
            std::cout << "Digite sua senha: ";
            std::getline(std::cin, password);
            std::cout << "Digite sua senha novamente: ";
            std::getline(std::cin, password2);

            if(password != password)
            {
                throw std::invalid_argument("As senhas não coincidem.");
            }

            for(const char c: password)
            {
                if(std::isdigit(c))
                {
                    hasdigit = true;
                }
                if(std::isalpha(c))
                {
                    hasalpha = true;
                }
            }
            if(!hasdigit || !hasalpha)
            {
                throw std::invalid_argument("Senha muito fraca, ela deve ter pelo menos um número e uma letra.");
            }
            break;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << " Por favor tente novamente.\n";
        }
    }
    return password;
}

std::string Input::input_cpf()
{
    std::string cpf;
    while (true)
    {
        try
        {
            std::cout << "Digite seu CPF sem pontuação: ";
            std::getline(std::cin, cpf);

            if(cpf.empty())
            {
                throw std::invalid_argument("O CPF não pode ser vazio.");
            }
            if(cpf.size() != 11)
            {
                throw std::out_of_range("O CPF deve ter 11 digitos.");
            }
            for(char c: cpf)
            {
                if(!std::isdigit(c))
                {
                    throw std::invalid_argument("O CPF só pode ter numeros.");
                }
            }
            break;
        } 
        catch(const std::exception& e)
        {  
            std::cerr << e.what() << " Por favor tente novamente.\n";
        }
    }
    return cpf;      
}

std::string Input::input_date(std::string text)
{
    int day, month, year;
    while (true)
    {
        try
        {
            std::cout << text << std::endl;
            std::cout << "Dia: ";
            std::cin >> day;
            std::cin.ignore();
            std::cout << "Mês: ";
            std::cin >> month;
            std::cin.ignore();
            std::cout << "Ano: ";
            std::cin >> year;
            std::cin.ignore();

            if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1923)
            {
                throw std::out_of_range("A data fornecida é invalida. O dia deve estar entre 1 e 31, o mês deve estar entre 1 e 12 e o ano deve estar entre 1923.");
            }
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // Verifica se o ano é bissexto
            {
                if (month == 2 && day > 29) {    // Verifica se o dia é válido para o mês de fevereiro em um ano bissexto
                    throw std::out_of_range("A data fornecida é invalida. O dia deve estar entre 1 e 29.");
                }
            }
            else{
                if (month == 2 && day > 28) {    // Verifica se o dia é válido para o mês de fevereiro
                    throw std::out_of_range("A data fornecida é invalida. O dia deve estar entre 1 e 28.");
                }
            }
            if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){    // Verifica se o dia é válido para os meses de 30 dias
                throw std::out_of_range("A data fornecida é invalida. O dia deve estar entre 1 e 30.");
            }
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){    // Verifica se o dia é válido para os meses de 31 dias
                throw std::out_of_range("A data fornecida é invalida. O dia deve estar entre 1 e 31.");
            }
            break;
        }catch(const std::exception& e){    // Caso a data não seja válida, pede para tentar novamente
            std::cerr << " Tente novamente." << std::endl;
        }
    }
    std::string strday = std::to_string(day), strmonth = std::to_string(month), stryear = std::to_string(year);

    if(strday.size() == 1) strday = "0" + strday;
    if(strmonth.size() == 1) strmonth = "0" + strmonth;
    if(stryear.size() == 1) stryear = "0" + stryear;

    std::string releaseDate = strday + '/' + strmonth + '/' + stryear;

    return releaseDate;
}

int Input::input_int(std::string text, int lower, int upper)
{
    int num;

    std::cout << text << std::endl;

    while(true)
    {
        try
        {
            bool validNum = true;
            std::cin >> num;
            std::cin.ignore();

            if(num > upper || num < lower)
            {
                validNum = false;
                throw std::invalid_argument("O valor deve estar entre " + std::to_string(lower) + " e " + std::to_string(upper) + ".");
            }
            if(validNum)
            {
                break;
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << " Tente novamente: ";
        }
    }
    return num;
}

int Input::input_posint(std::string text)
{
    return input_int(text, 0, 2147483647);
}

double Input::input_double(std::string txt)
{
    std::cout << txt << std::endl;
    std::string num;
    while (true)
    {
        try
        {
            std::cin >> num;
            std::cin.ignore(); 
            bool validnum = true;
            for(char c : num) 
            {
                if(!std::isdigit(c) && c != '.')
                {
                    validnum = false;
                    throw std::invalid_argument("O valor só pode conter números e '.'.");
                }
            }
            if(num.size() > 6) // Verifica se o nome tem mais de 50 caracteres
            {
                throw std::out_of_range("O valor deve conter no máximo 6 caracteres.");
            }
            if(validnum)
            {
                break;
            }
        }catch (const std::exception& e)
        {
            std::cerr << e.what() << " Tente novamente.: ";
        }
    }
    return std::stod(num);
}

int Input::input_bool(std::string txt) 
{    
    std::cout << txt << std::endl;
    int availability;
    while (true) 
    {
        try 
        {
            bool validAvailability = true;
            std::cin >> availability;
            std::cin.ignore();
            if (availability != 0 && availability != 1) 
            {
                validAvailability = false;
                throw std::invalid_argument("Valor deve ser 0 ou 1");
            }
            if(validAvailability)
            {
                break;
            }
        } 
        catch (const std::exception& e) 
        {
            std::cerr << e.what() << " Tente novamente: ";

        }
    }
    return availability == 0 ? 0 : 1;
}














