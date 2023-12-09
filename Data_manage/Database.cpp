#include "Database.hpp"

using json = nlohmann::json;

void Database::add_user(std::string &username, std::string &email, 
std::string &password,int &ID, std::string &cpf, int &Age){
    std::ifstream arquivo("users.json");
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
            int ageJSON = data["Age"].get<int>();

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
    novoUsuario["Age"] = Age;

    dadosJSON.push_back(novoUsuario);

    std::ofstream arquivoSaida("users.json");
    arquivoSaida << dadosJSON.dump(7);
    arquivoSaida.close();
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
    // return;
}
void Database::show_info(std::string &username, std::string &password){
    std::ifstream arquivo("users.json");
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
    std::ifstream arquivo("users.json");
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
                    std::ofstream arquivoSaida("users.json");
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
    std::ifstream arquivo("users.json");
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
                std::ofstream arquivoSaida("users.json");
                arquivoSaida << dadosJSON.dump(7);
                arquivoSaida.close();
                return;
            }
        }
    }
    std::cout << "Usuario nao encontrado" << std::endl;
    // return;
}
void Database::add_game(
                            std::string name,
                            std::string studio,
                            std::string ageRating,
                            std::string price,
                            std::string availability,
                            std::string review,
                            std::string releaseDate,
                            std::string gender,
                            std::string platform,
                            std::string language,
                            std::string os,
                            std::string processor,
                            std::string memory,
                            std::string graphics,
                            std::string directx,
                            std::string storage
                        ){
                            std::ifstream arquivo("users.json");
                            if (!arquivo.is_open()) {
                                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                                //return;
                            }

                            json dadosJSON;
                            arquivo >> dadosJSON;
                            arquivo.close();

                            


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
    std::ifstream arquivo("users.json");
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
    std::ifstream arquivo("users.json");
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
                    std::ofstream arquivoSaida("users.json");
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

