#ifndef PRODUCT_HPP_
#define PRODUCT_HPP_
#include <string>

class Product{
    protected:
	    // Data
	    std::string _name;    //Nome do produto
	    std::string _studio;    //Nome do studio que produziu o produto
	    std::string _ageRating;    //Classificacao etaria do produto
	    std::string _price;    //Preco do produto
	    std::string _availability;    //Disponibilidade do produto
	    std::string _review;    //Avaliacoes do produto
	    std::string _releaseDate;    //Data de lancamento do produto

    public:
	    // Constructor
	    Product(std::string name, std::string studio, std::string ageRating, std::string price, std::string availability, std::string review, std::string releaseDate);

	    // Destructor
	    ~Product();

        // Getters
	    std::string get_name();    //Retorna o nome do produto
	    std::string get_studio();    //Retorna o nome do studio que produziu o produto
	    std::string get_ageRating();    //Retorna a classificacao etaria do produto
	    std::string get_price();    //Retorna o preco do produto
	    std::string get_availability();    //Retorna a disponibilidade do produto
	    std::string get_review();    //Retorna as avaliacoes do produto
	    std::string get_releaseDate();    //Retorna a data de lancamento do produto
};

#endif    // PRODUCT_HPP_
