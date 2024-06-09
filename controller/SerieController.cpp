#include "SerieController.hpp"

SerieController::SerieController(SeriesDAO *seriesDAO, SerieMenu* menu)
{
  this->seriesDAO = seriesDAO;
  this->menu = menu;
}

SerieController::~SerieController()
{
  delete seriesDAO;
  delete menu;
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

void SerieController::listSeriesByTitle() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByTitle();
  this->menu->listSeries(series);
}

void SerieController::listSeriesByYear() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByYear();
  this->menu->listSeries(series);
}

void SerieController::listSeriesByChannel() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByChannel();
  this->menu->listSeries(series);
}

void SerieController::listSeriesByRating() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByRating();
  this->menu->listSeries(series);
}
