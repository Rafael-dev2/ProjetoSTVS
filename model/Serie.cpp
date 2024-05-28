#include "Serie.hpp"

Serie::Serie(
    int id,
    string nome,
    int anoDeLancamento,
    int temporada,
    int numEpisodios,
    string principaisAtores,
    string personagensPrincipais,
    string canal,
    int nota)
{
    this->id = id;
    this->nome = nome;
    this->anoDeLancamento = anoDeLancamento;
    this->temporada = temporada;
    this->numEpisodios = numEpisodios;
    this->principaisAtores = principaisAtores;
    this->personagensPrincipais = personagensPrincipais;
    this->canal = canal;
    this->nota = nota;
}

Serie::Serie(
    string nome,
    int anoDeLancamento,
    int temporada,
    int numEpisodios,
    string principaisAtores,
    string personagensPrincipais,
    string canal,
    int nota)
{
    this->nome = nome;
    this->anoDeLancamento = anoDeLancamento;
    this->temporada = temporada;
    this->numEpisodios = numEpisodios;
    this->principaisAtores = principaisAtores;
    this->personagensPrincipais = personagensPrincipais;
    this->canal = canal;
    this->nota = nota;
}

int Serie::getId() const
{
    return id;
}
void Serie::setId(int id)
{
    this->id = id;
}

string Serie::getNome() const
{
    return nome;
}
void Serie::setNome(const string &nome)
{
    this->nome = nome;
}

int Serie::getAnoDeLancamento() const
{
    return anoDeLancamento;
}
void Serie::setAnoDeLancamento(int ano_de_lancamento)
{
    anoDeLancamento = ano_de_lancamento;
}

int Serie::getTemporada() const
{
    return temporada;
}
void Serie::setTemporada(int temporada)
{
    this->temporada = temporada;
}

int Serie::getNumEpisodios() const
{
    return numEpisodios;
}
void Serie::setNumEpisodios(int num_episodios)
{
    numEpisodios = num_episodios;
}

string Serie::getPrincipaisAtores() const
{
    return principaisAtores;
}
void Serie::setPrincipaisAtores(const string &principais_atores)
{
    principaisAtores = principais_atores;
}

string Serie::getPersonagensPrincipais() const
{
    return personagensPrincipais;
}
void Serie::setPersonagensPrincipais(const string &personagens_principais)
{
    personagensPrincipais = personagens_principais;
}

string Serie::getCanal() const
{
    return canal;
}
void Serie::setCanal(const string &canal)
{
    this->canal = canal;
}

int Serie::getNota() const
{
    return nota;
}
void Serie::setNota(int nota)
{
    this->nota = nota;
}
