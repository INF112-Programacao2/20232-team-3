#include"Studio.hpp"

Studio::Studio(std::string username, std::string password, std::string email, Date birthdate, std::string CNPJorCPF): Client(username, password, email, birthdate, 2)
{
    int size = 0;
    std::string correctedCPForCNPJ = "";

    for(int i = 0 ; i < CNPJorCPF.size() ; i++)
        if(CNPJorCPF[i] >= '0' && CNPJorCPF[i] <= '9')
        {
            size++;
            correctedCPForCNPJ += CNPJorCPF[i];
        }
    if(size == 14 && checkCNPJ(correctedCPForCNPJ)) // Se o CNPJ tiver 14 caracteres
    {
        _CNPJ = CNPJorCPF;
        _CPF = "";
    }    
    else if(size == 11 && checkCPF(correctedCPForCNPJ)) // Se o CPF tiver 11 caracteres
    {
        _CPF = CNPJorCPF;
        _CNPJ = "";
    }
    else
        std::cout << "Erro ao criar conta\n";
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
