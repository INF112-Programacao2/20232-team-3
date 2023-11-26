#include "Autentication.hpp"


Autentication::Autentication(std::string username, std::string email, std::string password):
    _username(username), _email(email), _password(password){};

std::string Autentication::get_username(){
    return _username;
}
std::string Autentication::get_email(){
    return _email;
}
std::string Autentication::get_password(){
    return _password;
}
using json = nlohmann::json;
std::string Autentication::search_user(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        //return false;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

     if (dadosJSON.is_array()) {
        for (const auto& data: dadosJSON) {
            std::string usernameJSON= data["Username"];
            std::string emailJSON = data["Email"];
            std::string passwordJSON = data["PASSWORD"];
            int idJSON = data["ID"].get<int>();

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if ((usernameJSON == _username || emailJSON == _email) && passwordJSON == _password) {
                if (idJSON==10){
                    return "2";
                }
                else if (idJSON==1){
                    return "1";
                }
            }
        }
    }

    return "Usuario Invalido";
}
void Autentication::add_user(const std::string& nomeArquivo, std::string username, std::string email, std::string password, int ID) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo JSON." << std::endl;
        //return false;
    }

    json dadosJSON;
    arquivo >> dadosJSON;
    arquivo.close();

    if (dadosJSON.is_array()) {
        for (const auto& data: dadosJSON) {
            std::string usernameJSON= data["Username"];
            std::string emailJSON = data["Email"];
            std::string passwordJSON = data["PASSWORD"];
            int idJSON = data["ID"].get<int>();

            // Verifique se o nome e o usuário correspondem aos fornecidos
            if ((usernameJSON == username || emailJSON == email) && passwordJSON == password) {
                std::cout << "Usuario ja cadastrado" << std::endl;
                return;
            }
        }
    }
    json novoUsuario;
    novoUsuario["Username"] = username;
    novoUsuario["Email"] = email;
    novoUsuario["PASSWORD"] = password;
    novoUsuario["ID"] = ID;

    dadosJSON.push_back(novoUsuario);

    std::ofstream arquivoSaida(nomeArquivo);
    arquivoSaida << dadosJSON.dump(4);
    arquivoSaida.close();
    std::cout << "Usuario cadastrado com sucesso" << std::endl;
    return;
}

