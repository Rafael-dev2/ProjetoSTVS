#include <iostream>
#include "./repositories/SeriesDAO.hpp"
#include "./repositories/implementation/ServerDatabase.hpp"
#include "./view/Menu.hpp"
#include "./infrastructure/MariaDBConnection.hpp"
#include "./controller/SerieController.hpp"

using namespace std;
int main() {
    MariaDBConnection *connection = new MariaDBConnection();

    SeriesDAO *seriesDAO = new ServerDatabase(connection);
    Menu *serieMenu = new Menu();

    SerieController *controller = new SerieController(seriesDAO, serieMenu);
    
    controller->start();
    
    delete controller;
    return 0;
}

