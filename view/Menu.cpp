#include "./Menu.hpp"
#include "../utils/Utils.hpp"
#include <iostream>
#include <math.h>
#include "../controller/dto/AddSerieDTO.hpp"
#include "../controller/SerieController.hpp"
#include "../infrastructure/MariaDBConnection.hpp"
#include "../repositories/implementation/VirtualDatabase.hpp"

Menu::Menu(SerieController *serieController)
{
  this->serieController = serieController;
}

Menu::~Menu()
{
  cout << "Desligando" << endl;
  delete serieController;
}

void Menu::start() const
{
  vector<string> menuItens{"Series","Ajuda","Creditos"};
  vector<void (Menu::*)() const> functions{&Menu::series, &Menu::Help, &Menu::Credits};
  launchActions("Main Menu", menuItens, functions, this);
}

void Menu::series() const
{
  vector<string> menuItens{"Adicionar Serie", "Relatorios", "Adicionar Dados - Apenas para fins de teste"};
  vector<void (Menu::*)() const> functions{&Menu::addSerie, &Menu::listSeries, &Menu::AddData};
  launchActions("Series", menuItens, functions, this);
}

void Menu::listSeries() const
{
  vector<string> menuItens{"Ordenar por titulo", "Ordenar por canal", "Ordenar por ano", "Ordenar por avaliação"};
  vector<void (SerieController::*)() const> functions{
    &SerieController::listSeriesByTitle, 
    &SerieController::listSeriesByChannel, 
    &SerieController::listSeriesByYear, 
    &SerieController::listSeriesByRating
  };
  launchActions("Relatorios", menuItens, functions, this->serieController);
}

void Menu::addSerie() const
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

  AddSerieDTO *addSerieDTO = new AddSerieDTO(
      nome,
      anoDeLancamento,
      temporada,
      numEpisodios,
      principaisAtores,
      personagensPrincipais,
      canal,
      nota);
  this->serieController->addSerie(addSerieDTO);
}

void Menu::AddData() const
{
  AddSerieDTO* a = new AddSerieDTO("Breaking Bad",2008,1,7,"Bryn Cranston","Walter White","AMC",9);
  AddSerieDTO* b = new AddSerieDTO("Arrow",2012,1,23,"Stephen Amell","Oliver Queen","DW",7);
  AddSerieDTO* c = new AddSerieDTO("CSI: Investigação Criminal",2000,1,23,"William Petersen","Gil Brossom","CBS",5);
  this->serieController->addSerie(a);
  this->serieController->addSerie(b);
  this->serieController->addSerie(c);
  cout << "Dados Adicionados" << endl;
}

void Menu::Help() const{
  Textos::exibirTexto("./help.txt");
  Utils::freezeScreen();
}

void Menu::Credits() const{
  Textos::exibirTexto("./credits.txt");
  Utils::freezeScreen();
}

template<class T, class U>
void Menu::launchActions(string title, vector<string> menuItems, vector<void (T::*)() const> actions, U* instance) const
{
  int option = 0;

  string leaveText = to_string(option) + " - Sair";
  string message = "Insira a opção: ";

  int width = Utils::calculateWidth(title, message, menuItems);
  const string decorator = Utils::replicate('*', width);

  do
  {
    Utils::clearScreen();

    cout << decorator << endl;
    this->print(title, width);
    cout << decorator << endl;

    for (int i = 0; i < menuItems.size(); i++)
    {
      string line = to_string(i + 1) + " - " + menuItems[i];
      this->print(line, width);
    }

    this->print(leaveText, width);
    cout << decorator << endl;
    cout << message;
    cin >> option;

    if (option == 0) {
      break;
    }

    Utils::clearScreen();
    (instance->*actions.at(option - 1))();
  } while (option != 0);
}

void Menu::print(string actionTitle, int w) const 
{
  int titleSize = actionTitle.length();
  int rest = w - titleSize;

  int spaces = round(rest / 2);

  cout << '*' << Utils::replicate(' ', spaces) << actionTitle << endl;
}
