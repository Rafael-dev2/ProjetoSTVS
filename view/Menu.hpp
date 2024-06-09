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

  template <class T, class U>
  void launchActions(string title, vector<string> menuItems, vector<void (T::*)() const> actions, U* instance) const;

  void print(string, int) const;

public:
  Menu(SerieController *serieController);
  ~Menu();

  void Help() const;
  void Credits() const;
  void AddData() const;

  void series() const;

  void start() const;
  void listSeries() const;
  void addSerie() const;
};

#endif