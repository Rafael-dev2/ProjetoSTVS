#include <iostream>
#include "./repositories/SeriesDAO.hpp"
#include "./repositories/implementation/ServerDatabase.hpp"
#include "./view/Menu.hpp"
#include "./infrastructure/MariaDBConnection.hpp"

using namespace std;
int main() {
    MariaDBConnection *connection = new MariaDBConnection();

    SeriesDAO *seriesDAO = new ServerDatabase(connection);
    Menu *menu = new Menu(new SerieController(seriesDAO));
    
    menu->start();
    
    delete seriesDAO;
    delete menu;
    return 0;
}

