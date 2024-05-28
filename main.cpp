#include <iostream>
#include "./repositories/SeriesDAO.hpp"
#include "./repositories/implementation/VirtualDatabase.hpp"
#include "./view/Menu.hpp"
#include "./model/DBconnection.hpp"

using namespace std;
int main() {
    SeriesDAO *seriesDAO = new VirtualDatabase();
    Menu *menu = new Menu(new SerieController(seriesDAO));
    menu->start();
    delete menu;
    return 0;
}

