#include "Database.hpp"
#include "Autentication.hpp"

using json = nlohmann::json;

const std::string bd = "../users.json";

void Database::add_user(std::string &username, std::string &email, 
std::string &password,int &ID, std::string &cpf, std::string &birthdate){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string emailJSON = data["Email"];
            std::string passwordJSON = data["Password"];
            int idJSON = data["ID"].get<int>();
            std::string cpfJSON = data["CPF"];
            double balanceJSON = data["Balance"].get<double>();
            std::string Age = data["Age"];

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if ((usernameJSON == username && emailJSON == email) && passwordJSON == password) {
                std::cout << "Usuario ja cadastrado" << std::endl;
                return;
            }
        }
    }

    json novoUsuario;
    novoUsuario["Username"] = username;
    novoUsuario["Email"] = email;
    novoUsuario["Password"] = password;
    novoUsuario["ID"] = ID;
    novoUsuario["CPF"] = cpf;
    novoUsuario["Balance"] = 0.0;
    novoUsuario["Jogos"] = {"Gta"};
    novoUsuario["Wishlist"] = {};
    novoUsuario["Age"] = birthdate;
    novoUsuario["Publicacoes"] = {};

    dadosJSON.push_back(novoUsuario);

    std::ofstream arquivoSaida(bd);
    arquivoSaida << dadosJSON.dump(7);
    arquivoSaida.close();
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
    // return;
}
void Database::show_info(std::string &username, std::string &password){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string passwordJSON = data["Password"];
            int idJSON = data["ID"].get<int>();
            std::string cpfJSON = data["CPF"];
            double balanceJSON = data["Balance"].get<double>();

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username && passwordJSON == password) {
                std::cout << "Username: " << usernameJSON << std::endl;
                std::cout << "ID: " << idJSON << std::endl;
                std::cout << "CPF: " << cpfJSON << std::endl;
                std::cout << "Balance: " << balanceJSON << std::endl;
                // Verifica se o campo "Jogos" é um array antes de tentar iterar sobre ele
                if (data["Jogos"].is_array()) {
                    std::cout << "Jogos:" << std::endl;
                    for (const auto& jogo : data["Jogos"]) {
                        std::cout << "  - " << jogo << std::endl;
                    }
                } else if (data["Jogos"].is_null()) {
                    std::cout << "Jogos: Nenhum jogo registrado." << std::endl;
                } else {
                    std::cerr << "Erro: O campo 'Jogos' não é um array nem nulo no JSON." << std::endl;
                    // Trate o erro conforme necessário
                }
                
                return;
            }
        }
    }
    std::cout << "Usuario nao encontrado" << std::endl;
    // return;
}
void Database::add_game_user(std::string &username, std::string &password, std::string &game){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string passwordJSON = data["Password"];
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username && passwordJSON == password) {
                // Verifica se o campo "Jogos" é um array antes de tentar iterar sobre ele
                if (data["Jogos"].is_array()) {
                    for (const auto& jogo : data["Jogos"]) {
                        if(jogo == game){
                            std::cout << "Jogo ja cadastrado" << std::endl;
                            return;
                        }
                    }
                    data["Jogos"].push_back(game);
                    std::cout << "Jogo cadastrado com sucesso" << std::endl;
                    std::ofstream arquivoSaida(bd);
                    arquivoSaida << dadosJSON.dump(7);
                    arquivoSaida.close();
                    return;
                } else if (data["Jogos"].is_null()) {
                    std::cout << "Jogos: Nenhum jogo registrado." << std::endl;
                } else {
                    std::cerr << "Erro: O campo 'Jogos' não é um array nem nulo no JSON." << std::endl;
                    // Trate o erro conforme necessário
                }
                
                return;
            }
        }
    }
    std::cout << "Usuario nao encontrado" << std::endl;
    // return;
}
void Database::add_balance(std::string &username, std::string &password, double &balance){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string passwordJSON = data["Password"];
            int idJSON = data["ID"].get<int>();
            std::string cpfJSON = data["CPF"];
            double balanceJSON = data["Balance"].get<double>();

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username && passwordJSON == password) {
                data["Balance"] = balanceJSON + balance;
                std::cout << "Saldo atualizado com sucesso" << std::endl;
                std::ofstream arquivoSaida(bd);
                arquivoSaida << dadosJSON.dump(7);
                arquivoSaida.close();
                return;
            }
        }
    }
    std::cout << "Usuario nao encontrado" << std::endl;
    // return;
}
void Database::show_games(){
    std::ifstream arquivo("games.json");
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }
    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) {
            //Extração de dados do JSON de um jogo
                std::string ageRatingJSON = data["Age Rating"];
                std::string availabilityJSON = data["Availability"];
                std::string genderJSON = data["Gender"];
                std::string languageJSON = data["Language"];
                std::string nameJSON = data["Name"];
                std::string platformJSON = data["Platform"];
                std::string priceJSON = data["Price"];
                std::string releaseDateJSON = data["Release Date"];
                std::string reviewJSON = data["Review"];
                std::string studioJSON = data["Studio"];
                // Adicione outras variáveis conforme necessário

                // Imprimir os dados extraídos
                std::cout << "Dados do Jogo:" << std::endl;
                std::cout << "Name: " << nameJSON << std::endl;
                std::cout << "Age Rating: " << ageRatingJSON << std::endl;
                std::cout << "Availability: " << availabilityJSON << std::endl;
                std::cout << "Gender: " << genderJSON << std::endl;
                std::cout << "Language: " << languageJSON << std::endl;
                std::cout << "Platform: " << platformJSON << std::endl;
                std::cout << "Price: " << priceJSON << std::endl;
                std::cout << "Release Date: " << releaseDateJSON << std::endl;
                std::cout << "Review: " << reviewJSON << std::endl;
                std::cout << "Studio: " << studioJSON << std::endl;
        }

    }
}
void Database::search_game(std::string &username, std::string &password, std::string &game){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string passwordJSON = data["Password"];
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username && passwordJSON == password) {
                // Verifica se o campo "Jogos" é um array antes de tentar iterar sobre ele
                if (data["Jogos"].is_array()) {
                    for (const auto& jogo : data["Jogos"]) {
                        if(jogo == game){
                            std::cout << "Jogo encontrado" << std::endl;
                            return;
                        }
                    }
                    std::cout << "Jogo nao encontrado" << std::endl;
                    return;
                } else if (data["Jogos"].is_null()) {
                    std::cout << "Jogos: Nenhum jogo registrado." << std::endl;
                } else {
                    std::cerr << "Erro: O campo 'Jogos' não é um array nem nulo no JSON." << std::endl;
                    // Trate o erro conforme necessário
                }
                
                return;
            }
        }
    }
    std::cout << "Usuario nao encontrado" << std::endl;
    // return;

}
void Database::add_to_wishlist(std::string &username, std::string &password, std::string &game){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        // return;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string passwordJSON = data["Password"];
            // Verifique se o nome e o usuário correspondem aos fornecidos
            if (usernameJSON == username && passwordJSON == password) {
                // Verifica se o campo "Jogos" é um array antes de tentar iterar sobre ele
                if (data["Wishlist"].is_array()) {
                    data["Wishlist"].push_back(game);
                    std::cout << "Jogo cadastrado com sucesso" << std::endl;
                    std::ofstream arquivoSaida(bd);
                    arquivoSaida << dadosJSON.dump(7);
                    arquivoSaida.close();
                    return;
                } else if (data["Wishlist"].is_null()) {
                    std::cout << "Jogos: Nenhum jogo registrado." << std::endl;
                } else {
                    std::cerr << "Erro: O campo 'Jogos' não é um array nem nulo no JSON." << std::endl;
                    // Trate o erro conforme necessário
                }
                
                return;
            }
        }
    }
    std::cout << "Usuario nao encontrado" << std::endl;
    // return;
}
bool check_user(std::string &username, std::string &password){
    std::ifstream arquivo(bd);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        return false;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data : dadosJSON) {
            std::string usernameJSON = data["Username"];
            std::string passwordJSON = data["Password"];
            std::string emailJSON = data["Email"];

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if ((usernameJSON == username || emailJSON == username) && passwordJSON == password) {
                return true;
            }
        }
    }
    return false;
}
void Database::addGame(){
    std::string nameFile = "games.json";
    double price;
    std::string name, studio, ageRating, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;

    std::ifstream inputFile(nameFile);

    if(!inputFile.is_open()){
        std::cerr << "Erro ao abrir o arquivo json" << std::endl;
        return;
    }

    json dadosJSON;
    inputFile >> dadosJSON;
    inputFile.close();
    std::cout << "Digite o nome do jogo: ";
    name = Autentication::verifyName();
    
    auto it = std::find_if(dadosJSON.begin(), dadosJSON.end(), [&](const auto& data) {    // Verifica se o jogo já existe
        return data["Name"] == name;
    });

    if(it != dadosJSON.end()){    // Se o jogo já existir, não adiciona
        std::cout << "Esse jogo ja existe!" << std::endl;
        return;

    }
    else{    // Jogo não existe, crie um novo jogo
        std::cout << "Digite o nome do studio: ";
        studio = Autentication::verifyStudio();
        std::cout << "Digite a classificação etaria: ";
        ageRating = Autentication::verifyAgeRating();
        std::cout << "Digite o preco: ";
        price = Autentication::verifyPrice();
        std::cout << "Digite a disponibilidade: ";
        availability = Autentication::verifyAvailability();
        std::cout << "Digite o review: ";
        review = Autentication::verifyReview();
        std::cout << "Digite o dia, mes e ano do lancamento: " << std::endl;
        releaseDate = Autentication::verifyReleaseDate();
        std::cout << "Digite o genero: ";
        gender = Autentication::verifyName();
        std::cout << "Digite a plataforma: ";
        platform = Autentication::verifyName();
        std::cout << "Digite o idioma: ";
        language = Autentication::verifyName();
 
        if(platform != "PC"){    // Se a plataforma for diferente de PC, não pede as informações de PC
            json newGame;    // Cria um novo jogo
            // Adiciona as informações do jogo
            newGame["Name"] = name;
            newGame["Studio"] = studio;
            newGame["Age Rating"] = ageRating;
            newGame["Price"] = price;
            newGame["Availability"] = availability;
            newGame["Review"] = review;
            newGame["Release Date"] = releaseDate;
            newGame["Gender"] = gender;
            newGame["Platform"] = platform;
            newGame["Language"] = language;

            dadosJSON.push_back(newGame);
            std::ofstream fileout(nameFile);    // Abre o arquivo JSON
            fileout << dadosJSON.dump(10);  // Use o valor apropriado para a formatação desejada
            fileout.close();
            std::cout << "Jogo adicionado com sucesso!" << std::endl;
        }
        else{    // Se a plataforma for PC, pede as informações de PC
            std::cout << "Digite o sistema operacional: ";
            os = Autentication::verifyName();
            std::cout << "Digite o processador: ";
            processor = Autentication::verifyName();
            std::cout << "Digite o tamanho da memoria: ";
            memory = Autentication::verifyName();
            std::cout << "Digite a placa de video: ";
            graphics = Autentication::verifyName();
            std::cout << "Digite o directx: ";
            directx = Autentication::verifyName();
            std::cout << "Digite o tamanho do armazenamento: ";
            storage = Autentication::verifyName();

            json newGame;
            // Adiciona as informações do jogo
            newGame["Name"] = name;
            newGame["Studio"] = studio;
            newGame["Age Rating"] = ageRating;
            newGame["Price"] = price;
            newGame["Availability"] = availability;
            newGame["Review"] = review;
            newGame["Release Date"] = releaseDate;
            newGame["Gender"] = gender;
            newGame["Platform"] = platform;
            newGame["Language"] = language;
            newGame["OS"] = os;
            newGame["Processor"] = processor;
            newGame["Memory"] = memory;
            newGame["Graphics"] = graphics;
            newGame["DirectX"] = directx;
            newGame["Storage"] = storage;

            dadosJSON.push_back(newGame);
            std::ofstream fileout(nameFile);    // Abre o arquivo JSON
            fileout << dadosJSON.dump(16);
            fileout.close();
            std::cout << "Jogo adicionado com sucesso!" << std::endl;
        }
    }
}
void Database::removeGame(){    // Remove um jogo
    std::string name;
    bool gameExists = false;
    std::cout << "Digite o nome do jogo que deseja remover: ";

    while (true) {
        name = Autentication::verifyName();

        std::ifstream inputFile("games.json");    // Abre o arquivo JSON
        if (!inputFile.is_open()) {    // Verifica se o arquivo foi aberto corretamente
            std::cerr << "Erro ao abrir o arquivo json" << std::endl;
            return;
        }

        json dadosJSON;    // Cria um vetor JSON
        inputFile >> dadosJSON;    // Lê o arquivo JSON
        inputFile.close();    // Fecha o arquivo

        auto it = std::find_if(dadosJSON.begin(), dadosJSON.end(), [&](const json& game) {    // Verifica se o jogo existe
            return game["Name"] == name;
        });

        if (it != dadosJSON.end()) {    // Se o jogo existir, remove
            dadosJSON.erase(it);

            std::ofstream fileout("games.json");
            fileout << dadosJSON.dump(4);  // Ajuste o valor de indentação conforme necessário
            fileout.close();

            std::cout << "Jogo removido com sucesso!" << std::endl;
            gameExists = true;
        }
        else{    // Jogo não encontrado, pede para tentar novamente
            std::cout << "Jogo nao encontrado. Por favor tente novamente: " << std::endl;
        }

        if(gameExists){
            break;
        }
    }
}

void Database::changeGame(){    // Altera um jogo
    double price;
    std::string name, studio, ageRating, availability, review, releaseDate, gender, platform, language, os, processor, memory, graphics, directx, storage;
    bool gameExists = false;

    while(true){
        std::cout << "Digite o nome do jogo que deseja alterar: ";
        name = Autentication::verifyName();

        std::ifstream inputFile("games.json");    // Abre o arquivo JSON
        if(!inputFile.is_open()){    // Verifica se o arquivo foi aberto corretamente
            std::cerr << "Erro ao abrir o arquivo json" << std::endl;
            return;
        }

        json dadosJSON;    // Cria um vetor JSON
        inputFile >> dadosJSON;    // Lê o arquivo JSON
        inputFile.close();

        for(auto& game : dadosJSON){    // Procura o jogo no vetor JSON
            if (game["Name"] == name){    // Se o jogo existir, altera as informações
                gameExists = true;
                // Apenas o preço e a disponibilidade podem ser alterados
                std::cout << "Digite o novo preco: ";
                price = Autentication::verifyPrice();
                game["Price"] = price;

                std::cout << "Digite a nova disponibilidade ('Disponivel' ou 'Nao disponivel'): ";
                availability = Autentication::verifyAvailability();
                game["Availability"] = availability;

                std::ofstream fileout("games.json");
                fileout << dadosJSON.dump(4);  // Ajuste o valor de indentação conforme necessário
                fileout.close();

                std::cout << "Jogo alterado com sucesso!" << std::endl;
            }
        }
        if(!gameExists){    // Jogo não encontrado, pede para tentar novamente
            std::cout << "Jogo nao encontrado. Por favor tente novamente: " << std::endl;
        }
        else{
            break;
        }
    }
}


