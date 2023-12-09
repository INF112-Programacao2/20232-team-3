#include <iostream>
#include <string>
#include <vector>
#include "Product.hpp"
#include "Game.hpp"
#include "Data_manage/GameSystem.hpp"
#include "Autentication.hpp"
#include "Database.hpp"


int main() {
    std::cout << "Welcome to Steam!" << std::endl;
	//menu
	int opcao;
	while(true){
		std::cout << "1 - User menu" << std::endl;
		std::cout << "2 - Game menu" << std::endl;
		std::cout << "3 - Exit" << std::endl;
		std::cin >> opcao;
		switch(opcao){
			case 1:
				//UserSystem::userMenu();    //falta implementar
				break;
			case 2:
				GameSystem::gameMenu();    // Função principal do sistema de jogos
				break;
			case 3:
				return 0;
		}
	}
	return 0;
}