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
    const string replicate(char symbol, int length) const;
    void print(string, int) const;

  public:
    Menu(SerieController *serieController);
    ~Menu();
    void Help() const;
    void Credits() const;
    void AddData() const;
    void start() const;
    void series() const;
    void addSerie() const;
	void listSeriesMenu() const;
    void listSeries(vector<Serie *> series) const;
	void listSeriesbyTitle() const;
	void listSeriesbyYear() const;
	void listSeriesbyChannel() const;
	void listSeriesbyRating() const;
};

#endif