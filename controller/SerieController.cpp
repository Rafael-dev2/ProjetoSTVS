#include "SerieController.hpp"

SerieController::SerieController(SeriesDAO *seriesDAO, Menu* menu)
{
  this->seriesDAO = seriesDAO;
  this->menu = menu;
}

SerieController::~SerieController()
{
  delete seriesDAO;
  delete menu;
}

void SerieController::start() const
{
  vector<string> menuItens{"Series","Ajuda","Creditos"};
  vector<void (SerieController::*)() const> functions{&SerieController::series, &SerieController::help, &SerieController::credits};
  this->launchActions("Menu Principal", menuItens, functions);
}

void SerieController::series() const
{
  vector<string> menuItens{"Adicionar Serie", "Relatorios", "Atualizar Serie", "Deletar Serie"};
  vector<void (SerieController::*)() const> functions{
    &SerieController::addSerieAction,
    &SerieController::listSeries,
    &SerieController::updateSerie,
    &SerieController::deleteSerie
  };
  this->launchActions("Series", menuItens, functions);
}

void SerieController::listSeries() const
{
  vector<string> menuItens{"Ordenar por titulo", "Ordenar por canal", "Ordenar por ano", "Ordenar por avaliação"};
  vector<void (SerieController::*)() const> functions{
    &SerieController::listSeriesByTitle, 
    &SerieController::listSeriesByChannel, 
    &SerieController::listSeriesByYear, 
    &SerieController::listSeriesByRating
  };
  this->launchActions("Relatorios", menuItens, functions);
}

void SerieController::addSerieAction() const
{
  vector<string> menuItens{"Adicionar Serie", "Adicionar Dados - Apenas para fins de teste"};
  vector<void (SerieController::*)() const> functions{&SerieController::addSerie, &SerieController::addMockSerie};
  this->launchActions("Series", menuItens, functions);
}

void SerieController::help() const
{
  this->menu->Help();
}

void SerieController::credits() const
{
  this->menu->Credits();
}

void SerieController::addSerie() const
{
  this->menu->print("Adicionar Serie");
  auto addSerieDTO = this->menu->addSerie(); 

  Serie *serie = new Serie(
    addSerieDTO->getNome(),
    addSerieDTO->getAnoDeLancamento(),
    addSerieDTO->getTemporada(),
    addSerieDTO->getNumEpisodios(),
    addSerieDTO->getPrincipaisAtores(),
    addSerieDTO->getPersonagensPrincipais(),
    addSerieDTO->getCanal(),
    addSerieDTO->getNota()
  );

  seriesDAO->addSerie(serie);
}

void SerieController::addMockSerie() const
{
  Serie *a = new Serie("Breaking Bad", 2008, 1, 7, "Bryn Cranston", "Walter White", "AMC", 9);
  Serie *b = new Serie("Arrow", 2012, 1, 23, "Stephen Amell", "Oliver Queen", "DW", 7);
  Serie *c = new Serie("CSI: Investigação Criminal", 2000, 1, 23, "William Petersen", "Gil Brossom", "CBS", 5);

  seriesDAO->addSerie(a);
  seriesDAO->addSerie(b);
  seriesDAO->addSerie(c);

  this->menu->showMessage("Series inseridas com sucesso!");
}

void SerieController::listSeriesByTitle() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByTitle();
  this->menu->listSeries(series);
}

void SerieController::listSeriesByYear() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByYear();
  this->menu->listSeries(series);
}

void SerieController::listSeriesByChannel() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByChannel();
  this->menu->listSeries(series);
}

void SerieController::listSeriesByRating() const
{
  vector<Serie *> series = this->seriesDAO->listSeriesAndOrderByRating();
  this->menu->listSeries(series);
}

void SerieController::updateSerie() const
{
  int id = 0;
  Serie *serie = NULL;

  do {
    this->menu->print("Atualizar Serie");
    this->menu->print("Insira [0] para sair.");

    id = this->menu->getId();

    if (id == 0) {
      return;
    }

    if (id < 0) {
      this->menu->showMessage("ID inválido!");
      continue;
    }

    serie = this->seriesDAO->findSerieById(id);

    if (serie == NULL) 
    {
      this->menu->showMessage("Serie não encontrada!");
      id = -1;
    }
  } while(id < 0);

  this->menu->print("");
  this->menu->print("Pressione ENTER para manter o valor atual.");
  auto addSerieDTO = this->menu->updateSerie(serie);

  if (addSerieDTO->getNome() != "") {
    serie->setNome(addSerieDTO->getNome());
  }

  if (addSerieDTO->getAnoDeLancamento() != 0) {
    serie->setAnoDeLancamento(addSerieDTO->getAnoDeLancamento());
  }

  if (addSerieDTO->getTemporada() != 0) {
    serie->setTemporada(addSerieDTO->getTemporada());
  }

  if (addSerieDTO->getNumEpisodios() != 0) {
    serie->setNumEpisodios(addSerieDTO->getNumEpisodios());
  }

  if (addSerieDTO->getPrincipaisAtores() != "") {
    serie->setPrincipaisAtores(addSerieDTO->getPrincipaisAtores());
  }

  if (addSerieDTO->getPersonagensPrincipais() != "") {
    serie->setPersonagensPrincipais(addSerieDTO->getPersonagensPrincipais());
  }

  if (addSerieDTO->getCanal() != "") {
    serie->setCanal(addSerieDTO->getCanal());
  }

  if (addSerieDTO->getNota() != 0) {
    serie->setNota(addSerieDTO->getNota());
  }

  this->seriesDAO->updateSerie(serie);
}

void SerieController::deleteSerie() const
{  
  int id = 0;
  
  do {
    this->menu->print("Deletar Serie");
    this->menu->print("Insira [0] para sair.");
    id = this->menu->getId();

    if (id == 0) {
      break;
    }

    if (id < 0) {
      this->menu->showMessage("ID inválido!");
      continue;
    }

    Serie *serie = this->seriesDAO->findSerieById(id);

    if (serie == NULL) 
    {
      this->menu->showMessage("Serie não encontrada!");
      continue;
    }

    this->seriesDAO->deleteSerie(id);

    this->menu->showMessage("Serie deletada com sucesso!");
  } while(id < 0);
}

void SerieController::launchActions(string title, vector<string> menuItems, vector<void (SerieController::*)() const> actions) const
{
  int option = 0;

  string leaveText = to_string(option) + " - Sair";
  string message = "Insira a opção: ";

  int width = Utils::calculateWidth(title, message, menuItems);
  const string decorator = Utils::replicate(Menu::filler, width);

  do
  {
    Utils::clearScreen();

    cout << decorator << endl;
    this->menu->print(title, width);
    cout << decorator << endl;

    for (int i = 0; i < menuItems.size(); i++)
    {
      string line = to_string(i + 1) + " - " + menuItems[i];
      this->menu->print(line, width);
    }

    this->menu->print(leaveText, width);
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