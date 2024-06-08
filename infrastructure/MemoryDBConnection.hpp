#ifndef MEMORYDBCONNECTION_H_
#define MEMORYDBCONNECTION_H_

#include <map>

using namespace std;

template <class T>
class MemoryDBConnection
{
  private:
    map<int, T> database;

  public:
    MemoryDBConnection();
    virtual ~MemoryDBConnection();

    virtual map<int, T>& getConnection();
};

#include "./MemoryDBConnection.cpp"

#endif