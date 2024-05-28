
#ifndef SERIESDAO_HPP
#define SERIESDAO_HPP

#include "../model/Serie.hpp"
#include <vector>

class SeriesDAO
{
public:
  virtual void addSerie(Serie *) = 0;
  virtual void updateSerie(Serie *) = 0;
  virtual void deleteSerie(int) = 0;
  virtual Serie *findSerieById(int) const = 0;
  virtual vector<Serie *> listSeriesAndOrderByTitle() const = 0;
  virtual vector<Serie *> listSeriesAndOrderByChannel() const = 0;
  virtual vector<Serie *> listSeriesAndOrderByYear() const = 0;
  virtual vector<Serie *> listSeriesAndOrderByRating() const = 0;
};

#endif // SERIESDAO_HPP
