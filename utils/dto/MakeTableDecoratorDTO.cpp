#include "MakeTableDecoratorDTO.hpp"

MakeTableDecoratorDTO::MakeTableDecoratorDTO(
  vector<string>& fields,
  vector<map<string, string>>& data
)
{
  this->fields = fields;
  this->data = data;
}

vector<string>& MakeTableDecoratorDTO::getFields()
{
  return this->fields;
}

vector<map<string, string>>& MakeTableDecoratorDTO::getData()
{
  return this->data;
}