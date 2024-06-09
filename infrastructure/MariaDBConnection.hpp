//
// Created by rafael on 27/05/24.
//

#ifndef DBCONNECTION_HPP
#define DBCONNECTION_HPP
#include <mariadb/conncpp.hpp>
#include <string>

#include "../repositories/SeriesDAO.hpp"

using namespace std;

class MariaDBConnection
{
private:
    sql::SQLString url;
    sql::Properties properties;
    sql::Driver *driver;
    std::shared_ptr<sql::Connection> conector;

    static const string databaseName;

public:    
    MariaDBConnection();
    MariaDBConnection(const sql::SQLString& url, const sql::Properties properties);
    ~MariaDBConnection();

    std::shared_ptr<sql::Connection> getConnection();

    string getDatabaseName() const;
};

#endif // DBCONNECTION_HPP
