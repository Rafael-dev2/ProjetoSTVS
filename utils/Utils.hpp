#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "./dto/MakeTableDecoratorDTO.hpp"

using namespace std;

class Utils final
{
  private:
    static const string makeTableDecorator(vector<pair<string, int>>&);
    static const string makeRow(vector<pair<string, int>>&);

  public:
    static void clearScreen();
    static void freezeScreen();
    static void freezeScreen(string message);

    static int calculateWidth(string title, string message, vector<string>& items);
    static const string replicate(char symbol, int length);

    static void printTable(shared_ptr<MakeTableDecoratorDTO>);
};

#endif