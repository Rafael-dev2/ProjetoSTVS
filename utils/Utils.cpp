#include "Utils.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void Utils::freezeScreen()
{
  cout << endl;
  cout << "Press ENTER key to continue...";
  cin.ignore();
  cin.get();
}

void Utils::freezeScreen(string message)
{
  cout << endl;
  cout << message;
  cin.ignore();
  cin.get();
}

int Utils::calculateWidth(string title, string message, vector<string>& items)
{
  int width = max(title.length(), message.length());

  for (string itemTitle : items)
  {
    int menuItemTitleLength = itemTitle.length();
    width = width >= menuItemTitleLength ? width : menuItemTitleLength;
  }

  width += 4 + (log10(items.size()));

  return width;
}


#ifdef _WIN32
void Utils::clearScreen()
{
  system("cls");
}
#else
void Utils::clearScreen() 
{
  system("clear");
}
#endif