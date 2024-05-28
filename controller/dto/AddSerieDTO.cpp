#include "./AddSerieDTO.hpp"

AddSerieDTO::AddSerieDTO(
  string nome, 
  int anoDeLancamento, 
  int temporada, 
  int numEpisodios, 
  string principaisAtores, 
  string personagensPrincipais, 
  string canal, 
  double nota
) {
  this->nome = nome;
  this->anoDeLancamento = anoDeLancamento;
  this->temporada = temporada;
  this->numEpisodios = numEpisodios;
  this->principaisAtores = principaisAtores;
  this->personagensPrincipais = personagensPrincipais;
  this->canal = canal;
  this->nota = nota;
}

string AddSerieDTO::getNome() const
{
  return this->nome;
}

int AddSerieDTO::getAnoDeLancamento() const
{
  return this->anoDeLancamento;
}

int AddSerieDTO::getTemporada() const
{
  return this->temporada;
}

int AddSerieDTO::getNumEpisodios() const
{
  return this->numEpisodios;
}

string AddSerieDTO::getPrincipaisAtores() const
{
  return this->principaisAtores;
}

string AddSerieDTO::getPersonagensPrincipais() const
{
  return this->personagensPrincipais;
}

string AddSerieDTO::getCanal() const
{
  return this->canal;
}

int AddSerieDTO::getNota() const
{
  return this->nota;
}