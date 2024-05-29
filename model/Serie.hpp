#ifndef SERIE_HPP
#define SERIE_HPP

#include <iostream>
#include <string>

using namespace std;

class Serie
{
private:
    int id;
    string nome;
    int anoDeLancamento;
    int temporada;
    int numEpisodios;
    string principaisAtores;
    string personagensPrincipais;
    string canal;
    int nota;

public:
    Serie(int, string, int, int, int, string, string, string, int);
    Serie(string, int, int, int, string, string, string, int);
    ~Serie() {};
    int getId() const;
    void setId(int id);

    string getNome() const;
    void setNome(const string &nome);

    int getAnoDeLancamento() const;
    void setAnoDeLancamento(int ano_de_lancamento);

    int getTemporada() const;
    void setTemporada(int temporada);

    int getNumEpisodios() const;
    void setNumEpisodios(int num_episodios);

    string getPrincipaisAtores() const;
    void setPrincipaisAtores(const string &principais_atores);

    string getPersonagensPrincipais() const;
    void setPersonagensPrincipais(const string &personagens_principais);

    string getCanal() const;
    void setCanal(const string &canal);

    int getNota() const;
    void setNota(int nota);
};

#endif // SERIE_HPP
