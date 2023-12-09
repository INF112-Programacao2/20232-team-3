#include "Database.hpp"

using json = nlohmann::json;

void Database::add_user(std::string username, std::string email, 
std::string password,int ID, std::string cpf){
    std::ifstream arquivo("Usuarios.json");
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

    dadosJSON.push_back(novoUsuario);

    std::ofstream arquivoSaida("Usuarios.json");
    arquivoSaida << dadosJSON.dump(7);
    arquivoSaida.close();
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
    // return;
}
void Database::show_info(std::string username, std::string password){
    std::ifstream arquivo("Usuarios.json");
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
void Database::add_game_user(std::string username, std::string password, std::string game){
    std::ifstream arquivo("Usuarios.json");
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
                    std::ofstream arquivoSaida("Usuarios.json");
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
void Database::add_balance(std::string username, std::string password, double balance){
    std::ifstream arquivo("Usuarios.json");
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
                std::ofstream arquivoSaida("Usuarios.json");
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
                            std::ifstream arquivo("Usuarios.json");
                            if (!arquivo.is_open()) {
                                std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
                                //return;
                            }

                            json dadosJSON;
                            arquivo >> dadosJSON;
                            arquivo.close();

                            


                        }