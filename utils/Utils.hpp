#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <string>
#include <vector>

using namespace std;

class Utils final
{
  public:
    static void clearScreen();
    static void freezeScreen();
    static void freezeScreen(string message);
    static int calculateWidth(string title, string message, vector<string>& items);
};

#endif