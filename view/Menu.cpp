#include "./Menu.hpp"
#include "../utils/Utils.hpp"
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
  vector<Serie *> series = this->serieController->listSeriesByTitle();

  string idTitle = " Id";
  string nameTitle = " Nome";
  string tempTitle = " Temporada";
  string episodesTitle = " Episodios";
  string actorsTitle = " Principais Atores";
  string charactersTitle = " Personagens Principais";
  string channelTitle = " Canal";
  string yearTitle = " Ano";
  string ratingTitle = " Nota";
  
  int maxId = idTitle.length(), 
    maxName = nameTitle.length(), 
    maxTemp = tempTitle.length(), 
    maxEp = episodesTitle.length(), 
    maxActors = actorsTitle.length(), 
    maxMain = charactersTitle.length(),
    maxChannel = channelTitle.length(),
    maxYear = yearTitle.length(),
    maxRating = ratingTitle.length();

  for (auto serie : series)
  {
    int idLength = to_string(serie->getId()).length();
    int nameLength = serie->getNome().length();
    int tempLength = to_string(serie->getTemporada()).length();
    int epLength = to_string(serie->getNumEpisodios()).length();
    int actorsLength = serie->getPrincipaisAtores().length();
    int mainLength = serie->getPersonagensPrincipais().length();
    int channelLength = serie->getCanal().length();

    maxId = idLength > maxId ? idLength : maxId;
    maxName = nameLength > maxName ? nameLength : maxName;
    maxTemp = tempLength > maxTemp ? tempLength : maxTemp;
    maxEp = epLength > maxEp ? epLength : maxEp;
    maxActors = actorsLength > maxActors ? actorsLength : maxActors;
    maxMain = mainLength > maxMain ? mainLength : maxMain;
    maxChannel = channelLength > maxChannel ? channelLength : maxChannel;
  }

  maxId += 2, 
  maxName += 2, 
  maxTemp += 2, 
  maxEp += 2, 
  maxActors += 2, 
  maxMain += 2,
  maxChannel += 2,
  maxYear += 2,
  maxRating += 2;

  cout << '+' << this->replicate('-', maxId);
  cout << '+' << this->replicate('-', maxName);
  cout << '+' << this->replicate('-', maxTemp);
  cout << '+' << this->replicate('-', maxEp);
  cout << '+' << this->replicate('-', maxActors);
  cout << '+' << this->replicate('-', maxMain);
  cout << '+' << this->replicate('-', maxChannel);
  cout << '+' << this->replicate('-', maxYear);
  cout << '+' << this->replicate('-', maxRating) << '+' << endl;

  cout << '|' << idTitle << this->replicate(' ', maxId - idTitle.length()) << '|'; 
  cout << nameTitle << this->replicate(' ', maxName - nameTitle.length()) << '|'; 
  cout << tempTitle << this->replicate(' ', maxTemp - tempTitle.length()) << '|'; 
  cout << episodesTitle << this->replicate(' ', maxEp - episodesTitle.length()) << '|'; 
  cout << actorsTitle << this->replicate(' ', maxActors - actorsTitle.length()) << '|'; 
  cout << charactersTitle << this->replicate(' ', maxMain - charactersTitle.length()) << '|';
  cout << channelTitle << this->replicate(' ', maxChannel - channelTitle.length()) << '|'; 
  cout << yearTitle << this->replicate(' ', maxYear - yearTitle.length()) << '|'; 
  cout << ratingTitle << this->replicate(' ', maxRating - ratingTitle.length()) << '|' << endl;

  cout << '+' << this->replicate('-', maxId);
  cout << '+' << this->replicate('-', maxName);
  cout << '+' << this->replicate('-', maxTemp);
  cout << '+' << this->replicate('-', maxEp);
  cout << '+' << this->replicate('-', maxActors);
  cout << '+' << this->replicate('-', maxMain);
  cout << '+' << this->replicate('-', maxChannel);
  cout << '+' << this->replicate('-', maxYear);
  cout << '+' << this->replicate('-', maxRating) << '+' << endl;

  string defaultSpacing = this->replicate(' ', 5);

  for (auto serie : series)
  {
    cout << '|' << ' ' << serie->getId() << this->replicate(' ', maxId - to_string(serie->getId()).length() - 1) << '|'; 
    cout << ' ' << serie->getNome() << this->replicate(' ', maxName - serie->getNome().length() - 1) << '|'; 
    cout << ' ' << serie->getTemporada() << this->replicate(' ', maxTemp - to_string(serie->getTemporada()).length() - 1) << '|'; 
    cout << ' ' << serie->getNumEpisodios() << this->replicate(' ', maxEp - to_string(serie->getNumEpisodios()).length() - 1) << '|'; 
    cout << ' ' << serie->getPrincipaisAtores() << this->replicate(' ', maxActors - serie->getPrincipaisAtores().length() - 1) << '|'; 
    cout << ' ' << serie->getPersonagensPrincipais() << this->replicate(' ', maxMain - serie->getPersonagensPrincipais().length() - 1) << '|';
    cout << ' ' << serie->getCanal() << this->replicate(' ', maxChannel - serie->getCanal().length() - 1) << '|'; 
    cout << ' ' << serie->getAnoDeLancamento() << this->replicate(' ', maxYear - to_string(serie->getAnoDeLancamento()).length() - 1) << '|'; 
    cout << ' ' << serie->getNota() << this->replicate(' ', maxRating - to_string(serie->getNota()).length() - 1) << '|' << endl;
  }

  cout << '+' << this->replicate('-', maxId);
  cout << '+' << this->replicate('-', maxName);
  cout << '+' << this->replicate('-', maxTemp);
  cout << '+' << this->replicate('-', maxEp);
  cout << '+' << this->replicate('-', maxActors);
  cout << '+' << this->replicate('-', maxMain);
  cout << '+' << this->replicate('-', maxChannel);
  cout << '+' << this->replicate('-', maxYear);
  cout << '+' << this->replicate('-', maxRating) << '+' << endl;

  Utils::freezeScreen();
}
void Menu::Help() const{
  Textos::exibirTexto("./help.txt");
  Utils::freezeScreen();
}

void Menu::Credits() const{
  Textos::exibirTexto("./credits.txt");
  Utils::freezeScreen();
}

void Menu::launchActions(string title, vector<string> menuItems, vector<void (Menu::*)() const> actions) const
{
  int option = 0;

  string leaveText = to_string(option) + " - Sair";
  string message = "Insira a opção: ";

  int width = Utils::calculateWidth(title, message, menuItems);
  const string decorator = this->replicate('*', width);

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
    (this->*actions.at(option - 1))();
  } while (option != 0);
}

void Menu::print(string actionTitle, int w) const 
{
  int titleSize = actionTitle.length();
  int rest = w - titleSize;

  int spaces = round(rest / 2);

  cout << '*' << this->replicate(' ', spaces) << actionTitle << endl;
}

const string Menu::replicate(char symbol, int length) const {
  string buffer;
	for (int count = 0; count < length; count++)
	{
		buffer += symbol;
	}
	return (buffer);
}
