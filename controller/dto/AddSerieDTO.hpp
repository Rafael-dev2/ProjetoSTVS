#ifndef ADDSERIEDTO_HPP
#define ADDSERIEDTO_HPP

#include <string>

using namespace std;

class AddSerieDTO
{
private:
  string nome = "";
  int anoDeLancamento = 0;
  int temporada = 0;
  int numEpisodios = 0;
  string principaisAtores = "";
  string personagensPrincipais = "";
  string canal = "";
  int nota = 0;

public:
  AddSerieDTO(string, int, int temporada, int numEpisodios, string principaisAtores, string personagensPrincipais, string canal, double nota);
  
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