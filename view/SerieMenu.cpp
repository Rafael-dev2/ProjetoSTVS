#include "SerieMenu.hpp"

void SerieMenu::listSeries(vector<Serie *> series) const
{
  string idTitle = " Id";
  string nameTitle = " Nome";
  string tempTitle = " Temporada";
  string episodesTitle = " Episodios";
  string actorsTitle = " Principais Atores";
  string charactersTitle = " Personagens Principais";
  string channelTitle = " Canal";
  string yearTitle = " Ano";
  string ratingTitle = " Nota";

  vector<string> fields = {
    idTitle,
    nameTitle,
    tempTitle,
    episodesTitle,
    actorsTitle,
    charactersTitle,
    channelTitle,
    yearTitle,
    ratingTitle
  };

  vector<map<string, string>> data;

  for (auto serie : series)
  {
    map<string, string> row;
    row[idTitle] = to_string(serie->getId());
    row[nameTitle] = serie->getNome();
    row[tempTitle] = to_string(serie->getTemporada());
    row[episodesTitle] = to_string(serie->getNumEpisodios());
    row[actorsTitle] = serie->getPrincipaisAtores();
    row[charactersTitle] = serie->getPersonagensPrincipais();
    row[channelTitle] = serie->getCanal();
    row[yearTitle] = to_string(serie->getAnoDeLancamento());
    row[ratingTitle] = to_string(serie->getNota());

    data.push_back(row);
  }

  shared_ptr<MakeTableDecoratorDTO> dto = make_shared<MakeTableDecoratorDTO>(fields, data);
  
  Utils::printTable(dto);
  Utils::freezeScreen();
}