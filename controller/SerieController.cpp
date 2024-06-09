#include "SerieController.hpp"

SerieController::SerieController(SeriesDAO *seriesDAO)
{
  this->seriesDAO = seriesDAO;
}

SerieController::~SerieController()
{
  delete seriesDAO;
}

void SerieController::addSerie(AddSerieDTO *addSerieDTO)
{
  Serie *serie = new Serie(
    addSerieDTO->getNome(),
    addSerieDTO->getAnoDeLancamento(),
    addSerieDTO->getTemporada(),
    addSerieDTO->getNumEpisodios(),
    addSerieDTO->getPrincipaisAtores(),
    addSerieDTO->getPersonagensPrincipais(),
    addSerieDTO->getCanal(),
    addSerieDTO->getNota()
  );

  seriesDAO->addSerie(serie);
}

void SerieController::addSerie(Serie* serie)
{
  seriesDAO->addSerie(serie);
}

vector<Serie *> SerieController::listSeriesByTitle() const
{
  return seriesDAO->listSeriesAndOrderByTitle();
}
vector<Serie *> SerieController::listSeriesByYear() const
{
  return seriesDAO->listSeriesAndOrderByYear();
}
vector<Serie *> SerieController::listSeriesByChannel() const
{
  return seriesDAO->listSeriesAndOrderByChannel();
}
vector<Serie *> SerieController::listSeriesByRating() const
{
  return seriesDAO->listSeriesAndOrderByRating();
}