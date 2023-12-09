#include"Developer.hpp"

Developer::Developer(): Client()
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

Developer::~Developer()
{
}

void Developer::publish_game(Game game)
{
    for(int i = 0 ; i < _publishedGames.size() ; i++)
        if(_publishedGames[i].get_name() == game.get_name())
        {
            std::cout << "Jogo já publicado\n";
            return;
        }
    _publishedGames.push_back(game);
}

void Developer::remove_game(Game game)
{
    for(int i = 0 ; i < _publishedGames.size() ; i++)
        if(_publishedGames[i].get_name() == game.get_name())
        {
            _publishedGames.erase(_publishedGames.begin() + i);
            return;
        }
    std::cout << "Jogo nao publicado\n";
}

std::string Developer::get_CNPJ()
{
    if(_CNPJ != "")
        return _CNPJ;
    else
        return "Nao possui CNPJ";
}

std::string Developer::get_CPF()
{
    if(_CPF != "")
        return _CPF;
    else
        return "Nao possui CPF";
}

void Developer::menu()
{
    int aux;
    std::cout << "Bem vindo, " << _username << "!\n";
    INIT:
    std::cout << "O que deseja fazer?\n1 - Ver/Alterar Dados;\n2 - Ver/Resgatar Saldo;\n3 - Ver jogos;\n";
    std::cin >> aux;
    switch (aux)
    {
    case 1:
        // Mostra os dados e pergunta se quer alterar alguns deles
        break;
    case 2:
        // Mostra o saldo e pergunta se quer resgatar e quanto quer resgatar
        break;
    case 3:
        for(int i = 0 ; i < _publishedGames.size() ; i++)
            std::cout << i+1 << " " << _publishedGames[i].get_name() << '\n';

        std::cout << "O que deseja fazer?\n1 - Publicar novo jogo;\n2 - Remover jogo;\n3 - Editar jogo;\n";
        std::cin >> aux;
        switch (aux)
        {
        case 1:
            // Criar um obj do tipo game com os dados do jogo e depois adiciona no banco de dados
            break;
        case 2:
            // Pede para identificar o jogo para deletar e remove ele do banco de dados
            break;
        case 3:
            // Pede para identificar o jogo para editar e o que deseja editar e edita no banco de dados
            break;
        }
    default:
        break;
    }
}