#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>
#include "Textos.hpp"
#include "../controller/SerieController.hpp"
#include "../infrastructure/MariaDBConnection.hpp"

using namespace std;

class Menu
{
  private:
    SerieController *serieController;
    void launchActions(string title, vector<string> menuItems, vector<void (Menu::*)() const> actions) const;

  public:
    Menu(SerieController *serieController);
    ~Menu();
    void Help() const;
    void Credits() const;
    void AddData() const;
    void start() const;
    void series() const;
    void addSerie() const;
    void listSeries() const;

};

#endif