#include "./MemoryDBConnection.hpp"

using namespace std;

template <class T>
MemoryDBConnection<T>::MemoryDBConnection()
{
}

template <class T>
MemoryDBConnection<T>::~MemoryDBConnection()
{
}

template <class T>
map<int, T>& MemoryDBConnection<T>::getConnection()
{
  return this->database;
}
