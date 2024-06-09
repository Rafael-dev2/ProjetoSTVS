#include <iostream>
#include "./repositories/SeriesDAO.hpp"
#include "./repositories/implementation/ServerDatabase.hpp"
#include "./view/Menu.hpp"
#include "./view/SerieMenu.hpp"
#include "./infrastructure/MariaDBConnection.hpp"

using namespace std;
int main() {
    MariaDBConnection *connection = new MariaDBConnection();

    SeriesDAO *seriesDAO = new ServerDatabase(connection);
    SerieMenu *serieMenu = new SerieMenu();

    Menu *menu = new Menu(new SerieController(seriesDAO, serieMenu));
    
    menu->start();
    
    delete menu;
    return 0;
}

