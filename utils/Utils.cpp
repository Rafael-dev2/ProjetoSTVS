#include "Utils.hpp"
#include <iostream>
#include <math.h>

using namespace std;

void Utils::freezeScreen()
{
  cout << endl;
  cout << "Pressione ENTER para continuar...";
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

const string Utils::replicate(char symbol, int length) {
  string buffer;
	for (int count = 0; count < length; count++)
	{
		buffer += symbol;
	}
	return (buffer);
}

const string Utils::makeTableDecorator(vector<pair<string, int>>& fields)
{
  string line = "";

  for (auto field : fields)
  {
    line += '+' + Utils::replicate('-', field.second);
  }

  line += '+';

  return line;
}

const string Utils::makeRow(vector<pair<string, int>>& fields)
{
  string line = "|";

  for (auto field : fields)
  {
    int spacesLength = field.second - field.first.length() - 1;

    spacesLength = spacesLength < 0 ? 0 : spacesLength;

    line += ' ' + field.first + Utils::replicate(' ', spacesLength) + '|';
  }

  return line;
}

void Utils::printTable(shared_ptr<MakeTableDecoratorDTO> dto)
{
  vector<pair<string, int>> orderedSizes;
  map<string, int> indexedSizes;

  auto fields = dto->getFields();
  auto data = dto->getData();

  for (auto field : fields)
  {
    int max = field.length();
    for (auto row : data)
    {
      int length = row[field].length();
      max = length > max ? length : max;
    }

    max += 2;

    pair<string, int> pair = make_pair(field, max);

    orderedSizes.push_back(pair);
    indexedSizes.insert(pair);
  }

  const string decorator = Utils::makeTableDecorator(orderedSizes);

  cout << decorator << endl;
  cout << Utils::makeRow(orderedSizes) << endl;
  cout << decorator << endl;

  for (auto row : data)
  {
    vector<pair<string, int>> fieldsWithSize;

    for (auto field : fields)
    {
      fieldsWithSize.push_back(make_pair(row[field], indexedSizes[field]));
    }

    cout << Utils::makeRow(fieldsWithSize) << endl;
  }
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