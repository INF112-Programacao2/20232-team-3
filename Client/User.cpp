#include"User.hpp"

User::User(): Client()
{
    _id = 0;
}

User::~User()
{

}

void User::buy_game(Game game)
{
    if(game.get_price() > _balance)
        std::cout << "Saldo insuficiente\n";
    else if(game.get_ageRating() > get_age())
        std::cout << "Você não tem idade suficiente para comprar esse jogo\n";
    else
    {
        /*
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
        */
    }
}

void User::add_to_wishlist(Game game)
{
    bool alreadyHave = false;
    for(int i = 0; i < _wishlist.size(); i++)
        if(_wishlist[i].get_name() == game.get_name())
            alreadyHave = true;
    /*
    for(int i = 0; i < _library.size(); i++)
        if(_library[i].get_name() == game.get_name())
            alreadyHave = true;
    */
    if(!alreadyHave)
        _wishlist.push_back(game);
    else
        std::cout << "Você já possui esse jogo na sua lista de desejos\n";
}

void User::remove_from_wishlist(Game game)
{
    bool notRemoved = false;
    int index;
    for(int i = 0; i < _wishlist.size(); i++)
        if(_wishlist[i].get_name() == game.get_name())
        {
            notRemoved = true;
            index = i;
        }
    if(notRemoved)
        _wishlist.erase(_wishlist.begin() + index);
    else
        std::cout << "Você não possui esse jogo na sua lista de desejos\n";
}