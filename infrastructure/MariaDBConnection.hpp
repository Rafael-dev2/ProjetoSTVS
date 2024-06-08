//
// Created by rafael on 27/05/24.
//

#ifndef DBCONNECTION_HPP
#define DBCONNECTION_HPP
#include <mariadb/conncpp.hpp>
#include <string>

#include "../controller/SerieController.hpp"
#include "../repositories/SeriesDAO.hpp"

using namespace std;

class MariaDBConnection
{
private:
    sql::SQLString url;
    sql::Properties properties;
    sql::Driver *driver;
    std::shared_ptr<sql::Connection> conector;
    string databaseName; 

public:    
    MariaDBConnection();
    MariaDBConnection(const sql::SQLString& url, const sql::Properties properties);
    ~MariaDBConnection();

    std::shared_ptr<sql::Connection> getConnection();

    string getDatabaseName() const;
    
    // Serie *getData(const std::unique_ptr<sql::Connection> &conn, int row);
    // void insertData(const std::unique_ptr<sql::Connection> &conn, Serie *serie);
};

#endif // DBCONNECTION_HPP