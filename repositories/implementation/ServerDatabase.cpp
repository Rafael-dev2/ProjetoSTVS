#include "./ServerDatabase.hpp"
#include <mariadb/conncpp.hpp>
#include "../../infrastructure/MariaDBConnection.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

const string ServerDatabase::ServerDatabase::tableName = "SERIES";

const string ServerDatabase::SQL_InsertSerie = "INSERT INTO " + ServerDatabase::tableName + " (series_name, release_year, season, episode_count, main_actors, main_characters, network, rating) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
const string ServerDatabase::SQL_UpdateSerie = "UPDATE " + ServerDatabase::tableName + " SET series_name = ?, release_year = ?, season = ?, episode_count = ?, main_actors = ?, main_characters = ?, network = ?, rating = ? WHERE internal_id = ?";
const string ServerDatabase::SQL_GetSerie = "SELECT * FROM " + ServerDatabase::tableName + " WHERE internal_id = ?";

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
  auto stmnt = this->getStmnt(ServerDatabase::SQL_InsertSerie);
  stmnt->setString(1, serie->getNome());
  stmnt->setInt(2, serie->getAnoDeLancamento());
  stmnt->setInt(3, serie->getTemporada());
  stmnt->setInt(4, serie->getNumEpisodios());
  stmnt->setString(5, serie->getPrincipaisAtores());
  stmnt->setString(6, serie->getPersonagensPrincipais());
  stmnt->setString(7, serie->getCanal());
  stmnt->setInt(8, serie->getNota());
  stmnt->executeQuery();
}

void ServerDatabase::updateSerie(Serie *serie)
{


  auto stmnt = this->getStmnt(ServerDatabase::SQL_UpdateSerie);

  stmnt->setString(1, serie->getNome());
  stmnt->setInt(2, serie->getAnoDeLancamento());
  stmnt->setInt(3, serie->getTemporada());
  stmnt->setInt(4, serie->getNumEpisodios());
  stmnt->setString(5, serie->getPrincipaisAtores());
  stmnt->setString(6, serie->getPersonagensPrincipais());
  stmnt->setString(7, serie->getCanal());
  stmnt->setInt(8, serie->getNota());
  stmnt->setInt(9, serie->getId());

  stmnt->executeQuery();
}

void ServerDatabase::deleteSerie(int id)
{
  auto stmnt = this->getStmnt();

  string query = "DELETE FROM " + ServerDatabase::tableName;
  query += " WHERE internal_id = " + to_string(id) + ";";

  stmnt->executeQuery(query);
}

Serie *ServerDatabase::findSerieById(int id) const
{
  auto stmnt = this->getStmnt(ServerDatabase::SQL_GetSerie);

  stmnt->setInt(1, id);

  sql::ResultSet *lis = stmnt->executeQuery();
  if(!lis->next())
  {
    return nullptr;
  }

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

  string query = "SELECT * FROM " + ServerDatabase::tableName;
  query += " ORDER BY series_name;";

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

  string query = "SELECT * FROM " + ServerDatabase::tableName;
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

  string query = "SELECT * FROM " + ServerDatabase::tableName;
  query += " ORDER BY release_year DESC;";

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

  string query = "SELECT * FROM " + ServerDatabase::tableName;
  query += " ORDER BY rating DESC;";

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
  return stmnt;
}

shared_ptr<sql::PreparedStatement> ServerDatabase::getStmnt(const string query) const
{
  shared_ptr<sql::PreparedStatement> stmnt(this->connection->prepareStatement(query));
  return stmnt;
}