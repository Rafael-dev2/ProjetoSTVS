//
// Created by rafael on 27/05/24.
//

#ifndef DBCONNECTION_HPP
#define DBCONNECTION_HPP
#include <mariadb/conncpp.hpp>
#include <string>

#include "Serie.hpp"
#include "../controller/SerieController.hpp"
#include "../repositories/SeriesDAO.hpp"
using namespace std;

class DBconnection {
public:
    sql::SQLString url;
    sql::Properties properties;
    sql::Driver* driver;
    std::unique_ptr<sql::Connection>* conector;
    DBconnection();
    std::unique_ptr<sql::Connection> createconnection(const sql::SQLString& url,const sql::Properties properties);
    Serie* getData(const std::unique_ptr<sql::Connection> &conn,int row);
    void insertData(const std::unique_ptr<sql::Connection> &conn,Serie* serie);
};



#endif //DBCONNECTION_HPP
