#ifndef MAKETABLEDECORATORDTO_HPP
#define MAKETABLEDECORATORDTO_HPP

#include <vector>
#include <map>
#include <string>

using namespace std;

class MakeTableDecoratorDTO final
{
  private:
    vector<string> fields;
    vector<map<string, string>> data;

  public:
    MakeTableDecoratorDTO(
      vector<string>& fields,
      vector<map<string, string>>& data
    );

    vector<string>& getFields();
    vector<map<string, string>>& getData();
};

#endif