#include "Autentication.hpp"
#include "Database.hpp"

const std::string bd = "../users.json";
using json = nlohmann::json;


void Autentication::Registrar(){
    std::string name, email, password, cpf, birthdate;
    int ID;
    while(true){
    std::cout << "Voce deseja registrar-se como Usuario ou como um desenvolvedor?\n";
    std::cout << "1 - Usuario\n";
    std::cout << "2 - Desenvolvedor\n";
    int op;
    std::cin >> op;
        if (op == 1){
            ID = 1;
            break;
        }else if (op == 2){
            ID = 2;
            break;
        }else{
            std::cout << "Opcao invalida tente novamente\n";
            continue;
        }
    }
    name = user_name();
    email = user_email();
    password = user_password();
    cpf = user_cpf();
    birthdate = user_birthdate();
    if (!Database::check_user(name, password))
        Database::add_user(name, email, password, ID, cpf, birthdate);
    else
        std::cout << "Usuario ja cadastrado\n";
        //falta colocar o que fazer se for cadatrado
}
std::string Autentication::user_name(){
    std::string _username;
    while (true)
    {
        std::cout << "Digite seu nome de usuário: ";
        std::cin >> _username;
        if(_username.size() > 30)
        {
            std::cout << "Nome de usuário muito grande, digite novamente\n";
        }
        else
            return _username;
            break;
    }
    
}
std::string Autentication::user_email(){
    std::string _email;
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
    
}
std::string Autentication::user_password(){
    std::string _password;
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
                return _password;
                break;
        }
    }

    
}
std::string Autentication::user_cpf(){
    std::string _cpf;
    while (true)
    {
        std::cout << "Digite seu CPF: ";
        std::cin >> _cpf;
        if(_cpf.size() != 11)
        {
            std::cout << "CPF inválido, digite novamente\n";
            continue;
        }
        else
        {
            bool hasOnlyNumbers = true;
            for(auto e: _cpf)
            {
                if(e < '0' || e > '9')
                {
                    hasOnlyNumbers = false;
                    break;
                }
            }
            if(!hasOnlyNumbers)
            {
                std::cout << "CPF inválido, digite novamente\n";
                continue;
            }
            else
            {
                bool hasRepeated = false;
                for(int i = 0; i < 10; i++)
                {
                    if(_cpf[i] == _cpf[i + 1])
                    {
                        hasRepeated = true;
                        break;
                    }
                }
                if(hasRepeated)
                {
                    std::cout << "CPF inválido, digite novamente\n";
                    continue;
                }
                else
                {
                    int sum = 0;
                    for(int i = 0; i < 9; i++)
                        sum += (_cpf[i] - '0') * (10 - i);
                    int digit1 = (sum * 10) % 11;
                    if(digit1 == 10)
                        digit1 = 0;
                    if(digit1 != _cpf[9] - '0')
                    {
                        std::cout << "CPF inválido, digite novamente\n";
                        continue;
                    }
                    else
                    {
                        sum = 0;
                        for(int i = 0; i < 10; i++)
                            sum += (_cpf[i] - '0') * (11 - i);
                        int digit2 = (sum * 10) % 11;
                        if(digit2 == 10)
                            digit2 = 0;
                        if(digit2 != _cpf[10] - '0')
                        {
                            std::cout << "CPF inválido, digite novamente\n";
                            continue;
                        }
                        else
                            return _cpf;
                            break;
                    }
                }
            }
        }
    }
    
}
std::string Autentication::user_birthdate(){
    

    
}
void Autentication::Login(std::string usermail, std::string password){
    while(true){
        std::cout << "Digite seu email ou nome de usuario: ";
        std::cin >> usermail;
        std::cout << "Digite sua senha: ";
        std::cin >> password;
        if (Database::check_user(usermail, password))
            //retornar o ponteiro para client para carregar os dados do usuario
            break;
        else
            std::cout << "Usuario ou senha incorretos\n";
    }
}
std::string Autentication::verifyName() {    // Verifica se o nome é válido
    std::string name;
    while (true) {
        try {
            std::getline(std::cin, name);
            if (name.empty()) {
                throw std::invalid_argument("O nome nao pode ser vazio.");
            }
            for (char c : name) {    // Verifica se o nome contém apenas letras, números e espaços
                if (!std::isalnum(c) && c != ' ') {
                    throw std::invalid_argument("O nome deve ter apenas letras, numeros e espacos.");
                }
            }
            if (!std::isupper(name[0]) && !std::isdigit(name[0])) {    // Verifica se o nome começa com uma letra maiúscula ou um número
                throw std::invalid_argument("O nome deve comecar com letra maiuscula ou numero.");
            }
        
            if(name.size() > 50){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("O nome deve ter no maximo 50 caracteres.");
            }
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return name;
}

std::string Autentication::verifyStudio() {    // Verifica se o nome é válido
    std::string name;
    while (true) {
        try {
            std::getline(std::cin, name);
            if (name.empty()) {
                throw std::invalid_argument("O nome nao pode ser vazio.");
            }
            for (char c : name) {    // Verifica se o nome contém apenas letras, números e espaços
                if (!std::isalnum(c) && c != ' ') {
                    throw std::invalid_argument("O nome deve ter apenas letras, numeros e espacos.");
                }
            }
            if (!std::isupper(name[0])) {    // Verifica se o nome começa com uma letra maiúscula
                throw std::invalid_argument("O nome deve comecar com letra maiuscula ou numero.");
            }
        
            if(name.size() > 30){    // Verifica se o nome tem mais de 30 caracteres
                throw std::out_of_range("O nome deve ter no maximo 30 caracteres.");
            }
            break;

        } catch (const std::exception& e) {
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return name;
}

std::string Autentication::verifyAgeRating(){
    std::string ageRating;
    while(true){
        try{
            bool validAgeRating = true;
            std::getline(std::cin, ageRating);
            if(ageRating != "L" && ageRating != "10" && ageRating != "12" && ageRating != "14" && ageRating != "16" && ageRating != "18"){    // Verifica se a classificação etária é válida
                validAgeRating = false;
                throw std::invalid_argument("A classificacao etaria deve ser 'L', '10', '12', '14', '16' ou '18'.");
            }
            if(validAgeRating){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return ageRating;
}

double Autentication::verifyPrice() {
    double price;
    while (true) {
        try {
            std::string input;
            std::getline(std::cin, input);

            // Cria um stringstream para converter a string para double
            std::istringstream iss(input);
            iss >> price;

            // Verifica se a conversão foi bem-sucedida e se o número está no intervalo desejado
            if (iss.fail() || price < 0 || price > 1000) {
                throw std::invalid_argument("A entrada deve ser um número válido entre 0 e 1000.");
            }

            // Verifica se a string contém apenas dígitos e um ponto (.)
            if (input.find_first_not_of("0123456789.") != std::string::npos) {
                throw std::invalid_argument("A entrada deve conter apenas números e um ponto (.)");
            }

            break;
        } catch (const std::exception& e) {
            std::cerr << e.what() << " Por favor, tente novamente: ";
        }
    }

    return price;
}

std::string Autentication::verifyAvailability() {
    std::string availability;
    while (true) {
        try {
            bool validAvailability = true;
            std::getline(std::cin, availability);
            
            if (availability != "Disponivel" && availability != "Nao disponivel") {
                validAvailability = false;
                throw std::invalid_argument("Disponibilidade deve ser 'Disponivel' ou 'Nao disponivel'.");
            }
            if (validAvailability) {
                break;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return availability;
}

std::string Autentication::verifyReview() {    // Verifica se a avaliação é válida
    std::string review;
    while (true) {
        try{
            std::getline(std::cin, review);
            if (review.empty()) {
                throw std::invalid_argument("O nome nao pode ser vazio.");
            }
            bool validReview = true;
            for(char c : review) {
                if(!std::isalnum(c) && std::islower(review[0]) && c != '.'){
                    validReview = false;
                    throw std::invalid_argument("O review deve ter apenas letras, numeros e '.'");
                }
            }
            if(review.size() > 50){    // Verifica se o nome tem mais de 50 caracteres
                throw std::out_of_range("O review deve ter no maximo 50 caracteres.");
            }
            if(validReview){
                break;
            }
        }catch (const std::exception& e){
            std::cerr << e.what() << " Por favor tente novamente: ";
        }
    }
    return review;
}
std::string Autentication::verifyReleaseDate(){    // Verifica se a data de lançamento é válida
    int day, month, year;
    while (true){
        try{
            std::cout << "Dia: ";
            std::cin >> day;
            if(day)
            std::cout << "Mes: ";
            std::cin >> month;
            std::cout << "Ano: ";
            std::cin >> year;
            std::cin.ignore();
            if(std::cin.fail()){
                // Se a entrada não for um número válido, limpe o buffer e solicite a entrada novamente
                std::cin.clear();    // Limpar o buffer de entrada
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // Ignorar o restante da linha
                throw std::invalid_argument("A data deve ter apenas numeros.");
            }
            if(day < 1 || day > 31 || month < 1 || month > 12 || year < 1951){    // Verifica se a data é válida
                throw std::out_of_range("O dia deve estar entre 1 e 31, o mes entre 1 e 12 e o ano entre 1951 e o ano atual.");
            }
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){    // Verifica se o ano é bissexto
                if (month == 2 && day > 29) {    // Verifica se o dia é válido para o mês de fevereiro em um ano bissexto
                    throw std::out_of_range("O dia deve estar entre 1 e 29.");
                }
            }
            else{
                if (month == 2 && day > 28) {    // Verifica se o dia é válido para o mês de fevereiro
                    throw std::out_of_range("O dia deve estar entre 1 and 28.");
                }
            }
            if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){    // Verifica se o dia é válido para os meses de 30 dias
                throw std::out_of_range("O dia deve estar entre 1 e 30.");
            }
            if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){    // Verifica se o dia é válido para os meses de 31 dias
                throw std::out_of_range("O dia deve estar entre 1 e 31.");
            }
            break;
        }catch(const std::exception& e){    // Caso a data não seja válida, pede para tentar novamente
            std::cerr << " Por favor tente novamente." << std::endl;
        }
    }
    std::string releaseDate = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
    return releaseDate;
}
void Autentication::editar_dados(){
    std::string username, password, new_username, new_password, new_email;
    std::cout << "Digite o seu username: ";
    std::cin >> username;
    std::cout << "Digite a sua senha: ";
    std::cin >> password;
    Database::check_user(username, password);
    if(Database::check_user(username,password)){
        std::cout << "Bem vindo a seção de edição de dados" << username << std::endl;
        std::cout << "Digite seus novos dados" << std::endl;
        new_username = user_name();
        new_email = user_email();
        new_password = user_password();
        Database::modify_user(username,password,new_username,new_password,new_email);
    }else
        std::cout << "Usuario ou senha incorretos" << std::endl;
        
}





