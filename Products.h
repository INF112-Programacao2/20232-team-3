#ifndef PRODUCTS_H
#define PRODUCTS_H
#include <string>

class Products{
    // Data
    protected:
	std::string _name;    //Nome do produto
	std::string _studio;    //Nome do studio que produziu o produto
	int _ageRating;    //Classificacao etaria do produto
	float _price;    //Preco do produto
	std::string _availability;    //Disponibilidade do produto
	int _reviews;    //Avaliacoes do produto

	// Constructor
    public:
	Products(std::string name, std::string studio, int ageRating, float price, std::string availability, int reviews);

	// Destructor
	~Products();

	// Methods
	void verifyName();
	void verifyStudio();
	void verifyAgeRating();
	void verifyPrice();
	void verifyAvailability();
	void verifyReviews();

    // Getters
	std::string get_name();    //Retorna o nome do produto
	std::string get_studio();    //Retorna o nome do studio que produziu o produto
	int get_ageRating();    //Retorna a classificacao etaria do produto
	float get_price();    //Retorna o preco do produto
	std::string get_availability();    //Retorna a disponibilidade do produto
	int get_reviews();    //Retorna as avaliacoes do produto
	// Setters
	/*void set_name(std::string name);    //Altera o nome do produto
	void set_studio(std::string studio);    //Altera o nome do studio que produziu o produto
	void set_ageRating(int ageRating);    //Altera a classificacao etaria do produto
	void set_price(float price);    //Altera o preco do produto
	void set_availability(std::string availability);    //Altera a disponibilidade do produto
	void set_reviews(int reviews);    //Altera as avaliacoes do produto*/
};

#endif
