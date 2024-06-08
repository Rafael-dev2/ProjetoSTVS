#include "./Menu.hpp"
#include <iostream>
#include <math.h>
#include "../controller/dto/AddSerieDTO.hpp"
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
  launchActions("Main Menu", menuItens, functions);
}

void Menu::series() const
{
  vector<string> menuItens{"Adicionar Serie", "Listar Series", "Adicionar Dados - Apenas para fins de teste"};
  vector<void (Menu::*)() const> functions{&Menu::addSerie, &Menu::listSeries, &Menu::AddData};
  launchActions("Series", menuItens, functions);
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

void Menu::listSeries() const
{
  cout << "Listar Series" << endl;

  vector<Serie *> series = this->serieController->listSeries();

  for (auto serie : series)
  {
    cout << "!-----------------------------------------------------------!" << endl;
    cout << "Nome: " << serie->getNome() << endl;
    cout << "Ano de Lancamento: " << serie->getAnoDeLancamento() << endl;
    cout << "Temporada: " << serie->getTemporada() << endl;
    cout << "Numero de Episodios: " << serie->getNumEpisodios() << endl;
    cout << "Principais Atores: " << serie->getPrincipaisAtores() << endl;
    cout << "Personagens Principais: " << serie->getPersonagensPrincipais() << endl;
    cout << "Canal: " << serie->getCanal() << endl;
    cout << "Nota: " << serie->getNota() << endl;
    cout << "!-----------------------------------------------------------!" << endl;
  }
}
void Menu::Help() const{
  Textos::exibirTexto("./help.txt");
}
void Menu::Credits() const{
  Textos::exibirTexto("./credits.txt");
}
void Menu::launchActions(string title, vector<string> menuItems, vector<void (Menu::*)() const> actions) const
{
  int option = 0;
  string leaveText = "0 - Sair";
  const string decorator = this->makeDecorator(menuItems);

string message = "Insira a opção: ";

  int width = max(title.length(), message.length());

  for (string menuItemTitle : menuItems)
  {
    int menuItemTitleLength = menuItemTitle.length();
    width = width >= menuItemTitleLength ? width : menuItemTitleLength;
  }

  width += 4 + (log10(menuItems.size()));

  do
  {
    this->clearScreen();

    cout << decorator << endl;
    this->print(title, width);
    cout << decorator << endl;

    for (int i = 0; i < menuItems.size(); i++)
    {
      string line = to_string(i + 1) + " - " + menuItems[i];
      this->print(line, width);
    }

    this->print(leaveText, width);
    cin >> option;

    if (option == 0) {
      break;
    }

    (this->*actions.at(option - 1))();
  } while (option != 0);
}

void Menu::print(string actionTitle, int w) const 
{
  int titleSize = actionTitle.length();
  int rest = w - titleSize;

  int spaces = round(rest / 2);
  int finalSpaces = (rest % 2) != 0 ? spaces + 1 : spaces;

  cout << '*' << this->replicate(' ', spaces) << actionTitle << this->replicate(' ', finalSpaces) << '*' << endl;
}

const string Menu::makeDecorator(vector<string> menuItems) const
{
  string title = "Program";
  string message = "Insira a opção: ";

  int width = max(title.length(), message.length());

  for (string menuItemTitle : menuItems)
  {
    int menuItemTitleLength = menuItemTitle.length();
    width = width >= menuItemTitleLength ? width : menuItemTitleLength;
  }

  width += 4 + (log10(menuItems.size()));

  return this->replicate('*', width);
}

const string Menu::replicate(char symbol, int length) const {
  string buffer;
	for (int count = 0; count < length; count++)
	{
		buffer += symbol;
	}
	return (buffer);
}

#ifdef _WIN32
void Menu::clearScreen() const 
{
  system("cls");
}
#else
void Menu::clearScreen() const 
{
  system("clear");
}
#endif