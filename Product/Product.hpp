#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_
#include <bits/stdc++.h>

class Product{
    protected:
	    // Data
	    std::string _name;    //Nome do produto
	    std::string _studio;    //Nome do studio que produziu o produto
	    int  _ageRating;    //Classificacao etaria do produto
	    double _price;    //Preco do produto
	    bool _availability;    //Disponibilidade do produto
	    std::vector <std::string> _review;    //Avaliacoes do produto
	    std::string _releaseDate;    //Data de lancamento do produto

    public:
	    // Constructor com parametros
	    Product(std::string name, std::string studio, int ageRating, double price, bool availability, std::vector<std::string> review, std::string releaseDate);
		Product();	// Construtor sem parametros

        // Getters
	    std::string get_name();    //Retorna o nome do produto
	    std::string get_studio();    //Retorna o nome do studio que produziu o produto
	    int get_ageRating();    //Retorna a classificacao etaria do produto
		double get_price();		//Retorna o preco do produto
		bool get_availability();    //Retorna a disponibilidade do produto
		std::vector <std::string> get_review();    //Retorna as avaliacoes do produto
		std::string get_releaseDate();    //Retorna a data de lancamento do produto
		
		//setters
        void set_name(std::string name);	//Define o nome do produto
		void set_studio(std::string studio);	//Define o nome do studio que produziu o produto
		void set_ageRating(std::string ageRating);		//Define a classificação etaria do produto
		void set_price(double price);	//Define o preco do produto
		void set_availability(bool availability); //Define a disponibilidade do produto
		void set_review(std::vector <std::string> review);	//Define as avaliacoes do produto
        void set_releaseDate(std::string releaseDate);	//Define a data de lancamento do produto

};

#endif    // PRODUCT_HPP_