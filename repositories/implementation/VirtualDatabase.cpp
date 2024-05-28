#include "./VirtualDatabase.hpp"
#include <algorithm>

using namespace std;

void VirtualDatabase::addSerie(Serie *serie)
{
  int id = database.size() + 1;
  pair<int, Serie> tuple(id, *serie);

  database.insert(tuple);
}

void VirtualDatabase::updateSerie(Serie *serie)
{
  Serie *foundSerie = findSerieById(serie->getId());

  if (foundSerie == nullptr)
  {
    throw new invalid_argument("Serie not found");
  }

  foundSerie->setNome(serie->getNome());
  foundSerie->setAnoDeLancamento(serie->getAnoDeLancamento());
  foundSerie->setTemporada(serie->getTemporada());
  foundSerie->setNumEpisodios(serie->getNumEpisodios());
  foundSerie->setPrincipaisAtores(serie->getPrincipaisAtores());
  foundSerie->setPersonagensPrincipais(serie->getPersonagensPrincipais());
  foundSerie->setCanal(serie->getCanal());
  foundSerie->setNota(serie->getNota());
}

void VirtualDatabase::deleteSerie(int id)
{
  database.erase(id);
}

Serie *VirtualDatabase::findSerieById(int id) const
{
  auto it = database.find(id); // Using auto to simplify

  if (it == database.end())
  {
    return nullptr;
  }

  return const_cast<Serie *>(&it->second);
}

vector<Serie *> VirtualDatabase::listSeriesAndOrderByTitle() const
{
  vector<Serie *> result;

  for (const auto &entry : database)
  {
    result.push_back(const_cast<Serie *>(&entry.second));
  }

  sort(result.begin(), result.end(), [](Serie *a, Serie *b)
       { return a->getNome() < b->getNome(); });

  return result;
};

vector<Serie *> VirtualDatabase::listSeriesAndOrderByChannel() const
{
  vector<Serie *> result;

  for (const auto &entry : database)
  {
    result.push_back(const_cast<Serie *>(&entry.second));
  }

  sort(result.begin(), result.end(), [](Serie *a, Serie *b)
       { return a->getNome() < b->getNome(); });

  return result;
};

vector<Serie *> VirtualDatabase::listSeriesAndOrderByYear() const
{
  vector<Serie *> result;

  for (const auto &entry : database)
  {
    result.push_back(const_cast<Serie *>(&entry.second));
  }

  sort(result.begin(), result.end(), [](Serie *a, Serie *b)
       { return a->getNome() < b->getNome(); });

  return result;
};

vector<Serie *> VirtualDatabase::listSeriesAndOrderByRating() const
{
  vector<Serie *> result;

  for (const auto &entry : database)
  {
    result.push_back(const_cast<Serie *>(&entry.second));
  }

  sort(result.begin(), result.end(), [](Serie *a, Serie *b)
       { return a->getNome() < b->getNome(); });

  return result;
};
