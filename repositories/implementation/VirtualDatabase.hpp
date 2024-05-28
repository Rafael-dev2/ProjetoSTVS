#ifndef VIRTUALDATABASE_CPP
#define VIRTUALDATABASE_CPP

#include "../SeriesDAO.hpp"
#include "../../model/Serie.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class VirtualDatabase : public SeriesDAO
{
private:
  map<int, Serie> database;

public:
  void addSerie(Serie *serie) override;
  void updateSerie(Serie *serie) override;
  void deleteSerie(int id) override;
  Serie *findSerieById(int id) const override;
  vector<Serie *> listSeriesAndOrderByTitle() const override;
  vector<Serie *> listSeriesAndOrderByChannel() const override;
  vector<Serie *> listSeriesAndOrderByYear() const override;
  vector<Serie *> listSeriesAndOrderByRating() const override;
};

#endif
