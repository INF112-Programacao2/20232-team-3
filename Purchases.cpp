#include "Purchases.hpp"

Purchases::Purchases()
{
}

Purchases::~Purchases()
{
}

void Purchases::buy_game(User use){
    if(game.get_price() > _balance)
        std::cout << "Saldo insuficiente\n";
    else if(game.get_ageRating() > get_age())
        std::cout << "Você não tem idade suficiente para comprar esse jogo\n";
    else
    {
        bool alreadyHave = false;
        for(int i = 0; i < _library.size(); i++)
            if(_library[i].get_name() == game.get_name())
                alreadyHave = true;
        
        if(!alreadyHave)
        {
            _library.push_back(game);
            remove_from_wishlist(game);
            _balance -= game.get_price();
        }
        else
            std::cout << "Você já possui esse jogo\n";
}
}