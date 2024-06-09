//
// Created by rafael on 27/05/24.
//
#include <iostream>
#include "MariaDBConnection.hpp"

using namespace std;

// const string MariaDBConnection::databaseName = "stvs";
 const string MariaDBConnection::databaseName = "Si300A2024_03";

MariaDBConnection::MariaDBConnection()
{
    // Instantiate Driver
    this->driver = sql::mariadb::get_driver_instance();

    // Configure Connection
    // Configuração propria
    // this->url = "jdbc:mariadb://localhost:3306/" + MariaDBConnection::databaseName;
    // sql::Properties properties({{"user", "root"},
    //                             {"password", "docker"}});

    // Configurações da FT
     this->url = "jdbc:mariadb://143.106.243.64/ + MariaDBConnection::databaseName";
     sql::Properties properties({
         {"user", "Si300A2024_03"},
         {"password", "4CPg3dKPcr"}
     });

    this->properties = properties;
};

MariaDBConnection::MariaDBConnection(const sql::SQLString &url, const sql::Properties properties)
{
    this->driver = sql::mariadb::get_driver_instance();
    this->url = url;
    this->properties = properties;
};

MariaDBConnection::~MariaDBConnection()
{
    this->conector->close();
}

std::shared_ptr<sql::Connection> MariaDBConnection::getConnection()
{
    std::shared_ptr<sql::Connection> conn(driver->connect(url, properties));
    this->conector = conn;

    return conn;
}