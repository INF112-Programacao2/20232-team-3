#include <iostream>
#include <string>
#include <vector>
#include "Client/Client.hpp"
#include "Client/User.hpp"
#include "Client/Developer.hpp"


int main() {
	int aux;
	std::cout << "Bem vindo à Steam!" << std::endl;
	INIT:
	std::cout << "1 - Fazer login\n2 - Regisrar-se" << std::endl;
	std::cin >> aux;
	switch(aux)
	{
		case 1: LOGIN:
			// Pega passwaord e username/email e ve se existe
			Client* client = Autentication::login();
			switch (client->get_id())
			{
			case 1: // Usuario
				User* user = static_cast<User*>(client);
				user->menu();
				break;
			default: // Desenvolvedor
				Developer *dev = static_cast<Developer*>(client);
				dev->menu();
				break;
			}
			break;
		case 2: REGISTER:
			bool didit = Autentication::reg(); // Tenta registrar o usuario
			if(didit)
				goto INIT;
			else
				goto LOGIN;
			break;
	}

	return 0;
}