#include"Studio.hpp"

Studio::Studio(): Client()
{
    std::string CNPJorCPF = "", aux = "";
    std::cout << "Digite seu CNPJ ou CPF: ";
    while(true)
    {
        std::cin >> CNPJorCPF;
        for(int i = 0 ; i < CNPJorCPF.size() ; i++)
        {
            if(CNPJorCPF[i] >= '0' && CNPJorCPF[i] <= '9')
            {
                aux += CNPJorCPF[i];
            }
        }
        CNPJorCPF = aux;
        if(CNPJorCPF.size() == 11) // É CPF
        {
            _CPF = CNPJorCPF;
            _CNPJ = "";
            break;
        }
        else if(CNPJorCPF.size() == 14) // É CNPJ
        {
            _CNPJ = CNPJorCPF;
            _CPF = "";
            break;
        }
        else
        {
            std::cout << "CNPJ ou CPF inválido. Digite novamente!\n";
            continue;
        }
    }   
}

Studio::~Studio()
{
}

void Studio::publish_game(Game game)
{
    for(int i = 0 ; i < _publishedGames.size() ; i++)
        if(_publishedGames[i].get_name() == game.get_name())
        {
            std::cout << "Jogo já publicado\n";
            return;
        }
    _publishedGames.push_back(game);
}

void Studio::remove_game(Game game)
{
    for(int i = 0 ; i < _publishedGames.size() ; i++)
        if(_publishedGames[i].get_name() == game.get_name())
        {
            _publishedGames.erase(_publishedGames.begin() + i);
            return;
        }
    std::cout << "Jogo nao publicado\n";
}

std::string Studio::get_CNPJ()
{
    if(_CNPJ != "")
        return _CNPJ;
    else
        return "Nao possui CNPJ";
}

std::string Studio::get_CPF()
{
    if(_CPF != "")
        return _CPF;
    else
        return "Nao possui CPF";
}
