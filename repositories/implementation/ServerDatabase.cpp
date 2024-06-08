#include "./ServerDatabase.hpp"
#include <mariadb/conncpp.hpp>
#include "../../infrastructure/MariaDBConnection.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

ServerDatabase::ServerDatabase(MariaDBConnection *connection)
{
  this->connectionProvider = connection;
  this->connection = connection->getConnection();
}

ServerDatabase::~ServerDatabase()
{
  delete this->connectionProvider;
}

void ServerDatabase::addSerie(Serie *serie)
{
  auto stmnt = this->getStmnt();
  
  string query = "INSERT INTO SERIES VALUES('" +
                  serie->getNome() + "','" +
                  to_string(serie->getAnoDeLancamento()) + "','" +
                  to_string(serie->getTemporada()) + "','" +
                  to_string(serie->getNumEpisodios()) + "','" +
                  serie->getPrincipaisAtores() + "','" +
                  serie->getPersonagensPrincipais() + "','" +
                  serie->getCanal() + "','" +
                  to_string(serie->getNota()) + "')";

  stmnt->executeQuery(query);
}

void ServerDatabase::updateSerie(Serie *serie)
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "UPDATE " + dbName + " SET ";

  query += "series_name = " + serie->getNome() + " ";
  query += "release_year = " + to_string(serie->getAnoDeLancamento()) + " ";
  query += "season = " + to_string(serie->getTemporada()) + " ";
  query += "episode_count = " + to_string(serie->getNumEpisodios()) + " ";
  query += "main_actors = " + serie->getPrincipaisAtores() + " ";
  query += "main_characters = " + serie->getPersonagensPrincipais() + " ";
  query += "network = " + serie->getCanal() + " ";
  query += "rating = " +  to_string(serie->getNota()) + " ";
  query += "WHERE internal_id = " + to_string(serie->getId()) + ";";

  stmnt->executeQuery(query);
}

void ServerDatabase::deleteSerie(int id)
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "DELETE FROM " + dbName;
  query += " WHERE internal_id = " + to_string(id) + ";";

  stmnt->executeQuery(query);
}

Serie *ServerDatabase::findSerieById(int id) const
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "SELECT * FROM " + dbName;
  query += " WHERE internal_id = " + to_string(id) + ";";

  sql::ResultSet *lis = stmnt->executeQuery(query);
  lis->next();

  int serieId, year, season, eps, rate;
  string name,act,chr,cnl;

  serieId = (int)(lis->getInt(1));
  name = (lis->getString(2).c_str());
  year = (int)lis->getInt(3);
  season = (int)lis->getInt(4);
  eps = (int)lis->getInt(5);
  act = lis->getString(6).c_str();
  chr = lis->getString(7).c_str();
  cnl = lis->getString(8).c_str();
  rate = (int)lis->getInt(9);

  Serie* serie = new Serie(serieId,name,year,season,eps,act,chr,cnl,rate);
  
  return serie;
}

vector<Serie *> ServerDatabase::listSeriesAndOrderByTitle() const
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "SELECT * FROM " + dbName;
  query += " ORDER BY title;";

  sql::ResultSet *lis = stmnt->executeQuery(query);

  vector<Serie *> series;

  while(const auto &result = lis->next())
  {
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

    series.push_back(serie);
  }

  return series;
};

vector<Serie *> ServerDatabase::listSeriesAndOrderByChannel() const
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "SELECT * FROM " + dbName;
  query += " ORDER BY network;";

  sql::ResultSet *lis = stmnt->executeQuery(query);

  vector<Serie *> series;

  while(const auto &result = lis->next())
  {
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

    series.push_back(serie);
  }

  return series;
};

vector<Serie *> ServerDatabase::listSeriesAndOrderByYear() const
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "SELECT * FROM " + dbName;
  query += " ORDER BY release_year;";

  sql::ResultSet *lis = stmnt->executeQuery(query);

  vector<Serie *> series;

  while(const auto &result = lis->next())
  {
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

    series.push_back(serie);
  }

  return series;
};

vector<Serie *> ServerDatabase::listSeriesAndOrderByRating() const
{
  auto stmnt = this->getStmnt();

  string dbName = this->connectionProvider->getDatabaseName();

  string query = "SELECT * FROM " + dbName;
  query += " ORDER BY rating;";

  sql::ResultSet *lis = stmnt->executeQuery(query);

  vector<Serie *> series;

  while(const auto &result = lis->next())
  {
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

    series.push_back(serie);
  }

  return series;
};

shared_ptr<sql::Statement> ServerDatabase::getStmnt() const
{
  shared_ptr<sql::Statement> stmnt(this->connection->createStatement());

  string useDatabaseStmnt = "USE " + this->connectionProvider->getDatabaseName() + ";"; 

  stmnt->executeQuery(useDatabaseStmnt);

  return stmnt;
}