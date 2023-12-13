#include "Client/Client.hpp"
#include "Client/Developer.hpp"
#include "Client/User.hpp"

#include <iostream>

int main()
{
    int aux, output;
    std::cout << "Bem vindo à Steam!\n";    // Mensagem de boas vindas
    std::cout << "O que deseja fazer?\n1 - Registrar\n2 - Logar\n";
    std::cin >> aux;    // Variavel auxiliar para escolher entre registrar e logar
    switch (aux)
    {
    case 1:
        REGISTRO: 
        switch (output)
        {
        case 0:
            std::cout << "Erro ao registrar! O que gostaria de fazer?\n1 - Tentar novamente\n2 - Fazer login\n";
            std::cin >> aux;
            switch (aux)
            {
            case 1:
                goto REGISTRO;
                break;
            case 2:
                goto LOGIN;
                break;
            }
            break;
        default:
            break;
        }
        break;
    case 2:
        LOGIN:
        //output = funcaoLogar(cliente);
        // 1 se logou, 0 se não
        switch (output)
        {
        case 0:
            std::cout << "Erro ao logar! O que gostaria de fazer?\n1 - Tentar novamente\n2 - Registrar\n";
            std::cin >> aux;
            switch (aux)
            {
            case 1:
                goto LOGIN;
                break;
            case 2:
                goto REGISTRO;
                break;
            }
            break;
        }
        break;
    default:
        break;
    }

    //client->menu();


	return 0;
}