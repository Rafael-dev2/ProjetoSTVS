#ifndef UPDATESERIEDTO_HPP
#define UPDATESERIEDTO_HPP

#include <string>

using namespace std;

class UpdateSerieDTO
{
private:
  string nome;
  int anoDeLancamento;
  int temporada;
  int numEpisodios;
  string principaisAtores;
  string personagensPrincipais;
  string canal;
  int nota;

public:
  UpdateSerieDTO(
    string nome, 
    int anoDeLancamento, 
    int temporada, 
    int numEpisodios, 
    string principaisAtores, 
    string personagensPrincipais, 
    string canal, 
    double nota
  );
  
  string getNome() const;
  int getAnoDeLancamento() const;
  int getTemporada() const;
  int getNumEpisodios() const;
  string getPrincipaisAtores() const;
  string getPersonagensPrincipais() const;
  string getCanal() const;
  int getNota() const;
};

#endif