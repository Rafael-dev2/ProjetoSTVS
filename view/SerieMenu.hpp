#ifndef SERIEMENU_HPP
#define SERIEMENU_HPP

#include "../model/Serie.hpp"
#include "../utils/Utils.hpp"
#include "../controller/dto/AddSerieDTO.hpp"
#include "Menu.hpp"

#include <vector>

using namespace std;

class SerieMenu final : public Menu
{
  public:
    void listSeries(vector<Serie *> series) const;
    shared_ptr<AddSerieDTO> addSerie() const;
};

#endif