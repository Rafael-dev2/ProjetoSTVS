#ifndef SERIECONTROLLER_HPP
#define SERIECONTROLLER_HPP

#include "../repositories/SeriesDAO.hpp"
#include "./dto/AddSerieDTO.hpp"
#include "../view/Menu.hpp"
#include "../utils/dto/MakeTableDecoratorDTO.hpp"
#include "../utils/Utils.hpp"
#include <map>

using namespace std;

class SerieController final
{
  private:
    SeriesDAO *seriesDAO;
    Menu *menu;

    void createTable(vector<Serie *>& series) const;

  public:
    SerieController(SeriesDAO *seriesDAO, Menu*menu);
    ~SerieController();

    void launchActions(string title, vector<string> menuItems, vector<void (SerieController::*)() const> actions) const;

    void start() const;
    void series() const;
    void addSerieAction() const;
    void listSeries() const;
    void help() const;
    void credits() const;

    void addSerie() const;
    void addMockSerie() const;

    void listSeriesByTitle() const;
    void listSeriesByChannel() const;
    void listSeriesByRating() const;
    void listSeriesByYear() const;

    void deleteSerie() const;
};

#endif