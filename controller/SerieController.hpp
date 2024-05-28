#ifndef SERIECONTROLLER_HPP
#define SERIECONTROLLER_HPP

#include "../repositories/SeriesDAO.hpp"
#include "./dto/AddSerieDTO.hpp"

class SerieController final
{
  private:
    SeriesDAO *seriesDAO;

  public:
    SerieController(SeriesDAO *seriesDAO);
    ~SerieController();

    void addSerie(AddSerieDTO*);
    void addSerie(Serie*);
    vector<Serie *> listSeries() const;
};

#endif