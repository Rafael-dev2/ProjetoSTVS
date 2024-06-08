#ifndef SERVERDATABASE_HPP
#define SERVERDATABASE_HPP

#include <mariadb/conncpp.hpp>
#include "../../infrastructure/MariaDBConnection.hpp"
#include "../SeriesDAO.hpp"

using namespace std;

class ServerDatabase : public SeriesDAO
{
  private:
    MariaDBConnection *connectionProvider;
    shared_ptr<sql::Connection> connection;
    shared_ptr<sql::Statement> getStmnt() const;

  public:
    ServerDatabase(MariaDBConnection *connection);
    virtual ~ServerDatabase();

    void addSerie(Serie *serie) override;
    void updateSerie(Serie *serie) override;
    void deleteSerie(int id) override;
    Serie *findSerieById(int id) const override;
    vector<Serie *> listSeriesAndOrderByTitle() const override;
    vector<Serie *> listSeriesAndOrderByChannel() const override;
    vector<Serie *> listSeriesAndOrderByYear() const override;
    vector<Serie *> listSeriesAndOrderByRating() const override;
};

#endif