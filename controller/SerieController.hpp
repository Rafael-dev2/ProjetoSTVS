#ifndef SERIECONTROLLER_HPP
#define SERIECONTROLLER_HPP

#include "../repositories/SeriesDAO.hpp"
#include "./dto/AddSerieDTO.hpp"
#include "../view/SerieMenu.hpp"
#include <map>
#include "../utils/dto/MakeTableDecoratorDTO.hpp"
#include "../utils/Utils.hpp"

using namespace std;

class SerieController final
{
  private:
    SeriesDAO *seriesDAO;
    SerieMenu *menu;

    void createTable(vector<Serie *>& series) const;

  public:
    SerieController(SeriesDAO *seriesDAO, SerieMenu*menu);
    ~SerieController();

    void addSerie(AddSerieDTO*);
    void addSerie(Serie*);

    void listSeriesByTitle() const;
    void listSeriesByChannel() const;
    void listSeriesByRating() const;
    void listSeriesByYear() const;
};

#endif