#ifndef SERIEMENU_HPP
#define SERIEMENU_HPP

#include "../model/Serie.hpp"
#include "../utils/Utils.hpp"
#include <vector>

using namespace std;

class SerieMenu final
{
  public:
    void listSeries(vector<Serie *> series) const;
};

#endif