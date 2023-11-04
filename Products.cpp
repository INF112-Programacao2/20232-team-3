#include <iostream>
#include <string>
#include "Products.h"

// Constructor
Products::Products(std::string name, std::string studio, int ageRating, float price, std::string availability, int reviews) : 
    _name(name), _studio(studio), _ageRating(ageRating), _price(price), _availability(availability), _reviews(reviews) 
{
    // Verifica se os dados inseridos são válidos
    verifyName();
    verifyStudio();
    verifyAgeRating();
    verifyPrice();
    verifyAvailability();
    verifyReviews();
}

// Destructor
Products::~Products() 
{

}

// Methods
// Setters
void Products::verifyName(){    // Verifica se o nome do produto é válido
    std::cout << "Digite o nome do produto: " << std::endl;
    std::string tempname;
    std::cin >> tempname;
    while(tempname.size() > 30){
        std::cout << "Nome invalido" << std::endl;
        std::cout << "Digite um nome valido: " << std::endl;
        std::cin >> tempname;
    }
}

void Products::verifyStudio(){    // Verifica se o nome do studio é válido
    std::cout << "Digite o nome do studio: " << std::endl;
    std::string tempstudio;
    std::cin >> tempstudio;
    while(tempstudio.size() > 30){
        std::cout << "Nome invalido" << std::endl;
        std::cout << "Digite um nome valido: " << std::endl;
        std::cin >> tempstudio;
    }
}

void Products::verifyAgeRating(){    // Verifica se a classificacao etaria do produto é válida
    std::cout << "Digite a classificacao etaria do produto: " << std::endl;
    int tempageRating;
    std::cin >> tempageRating;
    while(tempageRating < 0 || tempageRating > 18){
        std::cout << "Classificacao etaria invalida" << std::endl;
        std::cout << "Digite uma classificacao etaria valida: " << std::endl;
        std::cin >> tempageRating;
    }
}

void Products::verifyPrice(){    // Verifica se o preco do produto é válido
    std::cout << "Digite o preco do produto: " << std::endl;
    float tempprice;
    std::cin >> tempprice;
    while(tempprice < 0){
        std::cout << "Preco invalido" << std::endl;
        std::cout << "Digite um preco valido: " << std::endl;
        std::cin >> tempprice;
    }
}

void Products::verifyAvailability(){    // Verifica se a disponibilidade do produto é válida
    std::cout << "Digite a disponibilidade do produto: " << std::endl;
    std::string tempavailability;
    std::cin >> tempavailability;
    while(tempavailability != "Sim" && tempavailability != "Nao"){
        std::cout << "Disponibilidade invalida" << std::endl;
        std::cout << "Digite uma disponibilidade valida: " << std::endl;
        std::cin >> tempavailability;
    }
}

void Products::verifyReviews(){    // Verifica se as avaliacoes do produto são válidas
    std::cout << "Digite a avaliacao do produto: " << std::endl;
    int tempreviews;
    std::cin >> tempreviews;
    while(tempreviews < 0 || tempreviews > 10){
        std::cout << "Avaliacao invalida" << std::endl;
        std::cout << "Digite uma avaliacao valida: " << std::endl;
        std::cin >> tempreviews;
    }
}
// Getters
std::string Products::get_name() {    //Retorna o nome do produto
    return _name;
}

std::string Products::get_studio() {    //Retorna o nome do studio que produziu o produto
    return _studio;
}

int Products::get_ageRating(){ // Retorna a classificacao etaria do produto
    return _ageRating;
}

float Products::get_price() {    //Retorna o preco do produto
    return _price;
}

std::string Products::get_availability() {    //Retorna a disponibilidade do produto
    return _availability;
}

int Products::get_reviews() {    //Retorna as avaliacoes do produto
    return _reviews;
}