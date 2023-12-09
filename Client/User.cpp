#include"User.hpp"
#include "../Data_manage/Database.hpp"

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

void User::menu()
{
    int aux;
    std::cout << "Bem vindo, " << _username << "!\n";
    INIT:
    std::cout << "O que deseja fazer?\n1 - Ver/Alterar Dados;\n2 - Ver/Adicionar Saldo;\n3 - Ver biblioteca;\n4 - Loja;\n5 - Ver lista de desejos;\n6 - Resgatar gift card;\n7 gerar gift card;\n";
    std::cin >> aux;
    switch (aux)
    {
    case 1:
        // Mostra os dados e pergunta se quer alterar alguns deles
        break;
    case 2:
        // Mostra o saldo e pergunta se quer adicionar mais dinheiro por gift card ou outro método
        break;
    case 3:
        for(int i = 0 ; i < _library.size() ; i++)
            std::cout << i+1 << " " << _library[i].get_name() << '\n';
        break;
    case 4:
        Database::show_games();
        // Pergunta se ele quer comprar um jogo e se quiser, faz a compra
        break;
    case 5:
        for(int i = 0 ; i < _wishlist.size() ; i++)
            std::cout << i+1 << " " << _wishlist[i].get_name() << '\n';
        // Pergunta se ele quer comprar um jogo e se quiser, faz a compra (Quando comprar, tira da wishlist)
        // Pergunta se ele quer remover um jogo da lista de desejos e se quiser, remove
        break;
    case 6:
        // Pergunta o código do gift card e se estiver certo, adiciona o saldo
        break;
    case 7:
        // Pergunta o valor do gift card e gera um código, removendo o valor do saldo
        break;
    default:
        break;
    }
}