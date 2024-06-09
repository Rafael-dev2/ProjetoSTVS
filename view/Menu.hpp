#ifndef MENU_HPP
#define MENU_HPP

#include "Textos.hpp"
#include "../utils/Utils.hpp"
#include "../controller/dto/AddSerieDTO.hpp"
#include "../model/Serie.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Menu
{
public:
  ~Menu();
 
  static const char filler;

  void print(string, int) const;
  void print(string) const;
  void showMessage(string) const;

  void Help() const;
  void Credits() const;
  void listSeries(vector<Serie *> series) const;
  shared_ptr<AddSerieDTO> addSerie() const;
  shared_ptr<AddSerieDTO> updateSerie(Serie *& serie) const;
  int getId() const;
};

#endif