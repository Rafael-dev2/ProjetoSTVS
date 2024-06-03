//
// Created by rafael on 27/05/24.
//
#include <iostream>
#include "DBconnection.hpp"

#include "Serie.hpp"
class SerieController;
using namespace std;
DBconnection::DBconnection(){
    // Instantiate Driver
    this->driver = sql::mariadb::get_driver_instance();
    // Configure Connection
    // Configuração propria
    //this->url = "jdbc:mariadb://localhost:3306/";
    //this->properties = {{"user", "Si300A2024_04"},{"password", "102030"}};
    //Configurações da FT
    this->url = "jdbc:mariadb://143.106.243.64/";
    sql::Properties properties({{"user", "Si300A2024_03"},{"password", "4CPg3dKPcr"}});
    this->properties = properties;

};
std::unique_ptr<sql::Connection> DBconnection::createconnection(const sql::SQLString& url,const sql::Properties properties) {
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));
    return conn;
}
Serie* DBconnection::getData(const std::unique_ptr<sql::Connection> &conn,int row){
        std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
        stmnt->executeQuery("USE Si300A2024_03;");
        sql::ResultSet *lis;
        lis = stmnt->executeQuery("SELECT * FROM Si300A2024_03.SERIES ORDER BY series_name LIMIT 1 OFFSET "+to_string(row));
        lis->next();
        int id, year, season, eps, rate;
        string name,act,chr,cnl;
        id = (int)(lis->getInt(1));
        name = (lis->getString(2).c_str());
        year = (int)lis->getInt(3);
        season = (int)lis->getInt(4);
        eps = (int)lis->getInt(5);
        act = lis->getString(6).c_str();
        chr = lis->getString(7).c_str();
        cnl = lis->getString(8).c_str();
        rate = (int)lis->getInt(9);
        Serie* serie = new Serie(id,name,year,season,eps,act,chr,cnl,rate);
        return serie;
}
 void DBconnection::insertData(const std::unique_ptr<sql::Connection> &conn,Serie* serie) {
    cout << "Inserindo a Série " << serie->getNome() << endl;
    std::unique_ptr<sql::Statement> stmnt(conn->createStatement());
    stmnt->executeQuery("USE Si300A2024_03;");
    string query = "INSERT INTO SERIES VALUES('" +
                   to_string(serie->getId()) + "','" +
                   serie->getNome() + "','" +
                   to_string(serie->getAnoDeLancamento()) + "','" +
                   to_string(serie->getTemporada()) + "','" +
                   to_string(serie->getNumEpisodios()) + "','" +
                   serie->getPrincipaisAtores() + "','" +
                   serie->getPersonagensPrincipais() + "','" +
                   serie->getCanal() + "','" +
                   to_string(serie->getNota()) + "')";

    stmnt->executeQuery(query);
    cout << "Serie" << serie->getNome() << " inserida no banco de dados com sucesso" << endl;
}
