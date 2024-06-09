#include "Menu.hpp"

const char Menu::filler = '*';

Menu::~Menu()
{
  cout << "Desligando" << endl;
}

void Menu::Help() const{
  Textos::exibirTexto("./help.txt");
  Utils::freezeScreen();
}

void Menu::Credits() const{
  Textos::exibirTexto("./credits.txt");
  Utils::freezeScreen();
}

void Menu::print(string actionTitle, int w) const 
{
  int titleSize = actionTitle.length();
  int rest = w - titleSize;

  int spaces = round(rest / 2);

  cout << Menu::filler << Utils::replicate(' ', spaces) << actionTitle << endl;
}

void Menu::print(string message) const 
{
  Utils::clearScreen();
  cout << Menu::filler << ' ' << message << endl;
  Utils::freezeScreen();
  Utils::clearScreen();
}


void Menu::listSeries(vector<Serie *> series) const
{
  string idTitle = " Id";
  string nameTitle = " Nome";
  string tempTitle = " Temporada";
  string episodesTitle = " Episodios";
  string actorsTitle = " Principais Atores";
  string charactersTitle = " Personagens Principais";
  string channelTitle = " Canal";
  string yearTitle = " Ano";
  string ratingTitle = " Nota";

  vector<string> fields = {
    idTitle,
    nameTitle,
    tempTitle,
    episodesTitle,
    actorsTitle,
    charactersTitle,
    channelTitle,
    yearTitle,
    ratingTitle
  };

  vector<map<string, string>> data;

  for (auto serie : series)
  {
    map<string, string> row;
    row[idTitle] = to_string(serie->getId());
    row[nameTitle] = serie->getNome();
    row[tempTitle] = to_string(serie->getTemporada());
    row[episodesTitle] = to_string(serie->getNumEpisodios());
    row[actorsTitle] = serie->getPrincipaisAtores();
    row[charactersTitle] = serie->getPersonagensPrincipais();
    row[channelTitle] = serie->getCanal();
    row[yearTitle] = to_string(serie->getAnoDeLancamento());
    row[ratingTitle] = to_string(serie->getNota());

    data.push_back(row);
  }

  shared_ptr<MakeTableDecoratorDTO> dto = make_shared<MakeTableDecoratorDTO>(fields, data);
  
  Utils::printTable(dto);
  Utils::freezeScreen();
}

shared_ptr<AddSerieDTO> Menu::addSerie() const
{
  cout << "Adicionar Serie" << endl;

  cout << "Nome..........: ";
  string nome;
  cin.ignore(); // Clear the newline character left in the buffer
  getline(cin, nome);

  cout << "Ano de Lancamento..........: ";
  int anoDeLancamento;
  cin >> anoDeLancamento;

  cout << "Temporada..........: ";
  int temporada;
  cin >> temporada;

  cout << "Numero de Episodios..........: ";
  int numEpisodios;
  cin >> numEpisodios;

  cin.ignore(); // Clear the newline character left in the buffer

  cout << "Principais Atores..........: ";
  string principaisAtores;
  getline(cin, principaisAtores);

  cout << "Personagens Principais..........: ";
  string personagensPrincipais;
  getline(cin, personagensPrincipais);

  cout << "Canal..........: ";
  string canal;
  getline(cin, canal);

  cout << "Nota..........: ";
  int nota;
  cin >> nota;

  shared_ptr<AddSerieDTO> dto = make_shared<AddSerieDTO>(
    nome,
    anoDeLancamento,
    temporada,
    numEpisodios,
    principaisAtores,
    personagensPrincipais,
    canal,
    nota
  );

  return dto;
}

int Menu::deleteSerie() const
{
  cout << "Deletar Serie. Insira [0] para sair." << endl;
  cout << "Id da Serie..........: ";

  int id;
  cin >> id;

  return id;
}