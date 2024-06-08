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

   vector<int> lengths;
   lengths.push_back(idTitle.length());
   lengths.push_back(nameTitle.length());
   lengths.push_back(tempTitle.length());
   lengths.push_back(episodesTitle.length());
   lengths.push_back(actorsTitle.length());
   lengths.push_back(charactersTitle.length());
   lengths.push_back(channelTitle.length());
   lengths.push_back(yearTitle.length());
   lengths.push_back(ratingTitle.length());

  int maxId = idTitle.length(), 
    maxName = nameTitle.length(), 
    maxTemp = tempTitle.length(),
    maxEp = episodesTitle.length(), 
    maxActors = actorsTitle.length(), 
    maxMain = charactersTitle.length(),
    maxChannel = channelTitle.length(),
    maxYear = yearTitle.length(),
    maxRating = ratingTitle.length();

  for (int i = 0; i < series.size();i++)
  {
    int idLength = to_string(series[i]->getId()).length();
    cout << idLength << endl;;
    int nameLength = series[i]->getNome().length();
    int tempLength = to_string(series[i]->getTemporada()).length();
    int epLength = to_string(series[i]->getNumEpisodios()).length();
    int actorsLength = series[i]->getPrincipaisAtores().length();
    int mainLength = series[i]->getPersonagensPrincipais().length();
    int channelLength = series[i]->getCanal().length();

    lengths[0] = idLength > lengths[0] ? idLength : lengths[0];
    lengths[1] = nameLength > lengths[1] ? nameLength : lengths[1];
    lengths[2] = tempLength > lengths[2] ? tempLength : lengths[2];
    lengths[3] = epLength > lengths[3] ? epLength : lengths[3];
    lengths[4] = actorsLength > lengths[4] ? actorsLength : lengths[4];
    lengths[5] = mainLength > lengths[5] ? mainLength : lengths[5];
    lengths[6] = channelLength > lengths[6] ? channelLength : lengths[6];
  }

  for(int i = 0;i < lengths.size(); i++){
  lengths[i] += 2;
}

  for (auto length : lengths){
  cout << '+' << this->replicate('-', length);
  }
  cout << '+' << endl;

  cout << '|' << idTitle << this->replicate(' ', lengths[0] - idTitle.length()) << '|';
  cout << nameTitle << this->replicate(' ', lengths[1] - nameTitle.length()) << '|';
  cout << tempTitle << this->replicate(' ', lengths[2] - tempTitle.length()) << '|';
  cout << episodesTitle << this->replicate(' ', lengths[3] - episodesTitle.length()) << '|';
  cout << actorsTitle << this->replicate(' ', lengths[4] - actorsTitle.length()) << '|';
  cout << charactersTitle << this->replicate(' ', lengths[5] - charactersTitle.length()) << '|';
  cout << channelTitle << this->replicate(' ', lengths[6] - channelTitle.length()) << '|';
  cout << yearTitle << this->replicate(' ', lengths[7] - yearTitle.length()) << '|';
  cout << ratingTitle << this->replicate(' ', lengths[8] - ratingTitle.length()) << '|' << endl;

  for (auto length : lengths){
  cout << '+' << this->replicate('-', length);
  }
  cout << '+' << endl;

  string defaultSpacing = this->replicate(' ', 5);
  string a = "";
  for (auto serie : series)
  {
    int nm = (lengths[1] == (serie->getNome().length() + 2)) ? -1 : 1;
    int ac = (lengths[4] == serie->getPrincipaisAtores().length() + 2) ? - 1 : 1;
    int cr = (lengths[5] == serie->getPersonagensPrincipais().length() + 2) ? -1 : 1;
    int ch = (lengths[6] == serie->getCanal().length() + 2) ? -1 : 1;
    cout << '|' << ' ' << serie->getId() << this->replicate(' ', lengths[0] - to_string(serie->getId()).length() - 1) << '|';
    cout << ' ' << serie->getNome() << this->replicate(' ', lengths[1] - serie->getNome().length() - nm ) << '|';
    cout << ' ' << serie->getTemporada() << this->replicate(' ', lengths[2] - to_string(serie->getTemporada()).length() - 1) << '|';
    cout << ' ' << serie->getNumEpisodios() << this->replicate(' ', lengths[3] - to_string(serie->getNumEpisodios()).length() - 1) << '|';
    cout << ' ' << serie->getPrincipaisAtores() << this->replicate(' ', lengths[4] - serie->getPrincipaisAtores().length() - ac) << '|';
    cout << ' ' << serie->getPersonagensPrincipais() << this->replicate(' ', lengths[5] - serie->getPersonagensPrincipais().length() - cr) << '|';
    cout << ' ' << serie->getCanal() << this->replicate(' ', lengths[6] - serie->getCanal().length() - ch) << '|';
    cout << ' ' << serie->getAnoDeLancamento() << this->replicate(' ', lengths[7] - to_string(serie->getAnoDeLancamento()).length() - 1) << '|';
    cout << ' ' << serie->getNota() << this->replicate(' ', lengths[8] - to_string(serie->getNota()).length() - 1) << '|' << endl;
  }

  for (auto length : lengths){
  cout << '+' << this->replicate('-', length);
  }
  cout << '+' << endl;

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
