#include "./Menu.hpp"
#include <iostream>
#include "../controller/dto/AddSerieDTO.hpp"
#include "../model/DBconnection.hpp"
#include "../repositories/implementation/VirtualDatabase.hpp"

Menu::Menu(SerieController *serieController)
{
  this->hasDatabase = true;
  this->serieController = serieController;
  auto* db = new DBconnection;
  try {
    cout << "Começando leitura do banco de dados" << endl;
    this->conector = db->createconnection(db->url,db->properties);
  }
  catch (sql::SQLException& e) {
    cout << "Erro com banco de dados, apenas banco em memória disponível" << endl;
    this->hasDatabase = false;
  }
  if(hasDatabase == true){this->getDatabase();}
}

Menu::~Menu()
{
  if(hasDatabase == true) {
    cout << "Inserindo no banco de dados" << endl;
    this->insertDatabase();
  }
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
void Menu::insertDatabase() const {
  int i = 0;
  vector<Serie*> listaseries = serieController->listSeries();
  while(i < listaseries.size()) {
    db->insertData(conector,listaseries[i]);
    i++;
  }
  cout << i <<" Series foram colocadas no banco" << endl;
}
void Menu::getDatabase() const {
  int i = 0;
  Serie* serie;
  std::unique_ptr<sql::Statement> stmnt(conector->createStatement());
  stmnt->executeQuery("USE Si300A2024_03;");
  sql::ResultSet *size = stmnt->executeQuery("SELECT * FROM SERIES");
  while(size->next()) {
    serie = db->getData(conector,i);
    cout << i << endl;
    cout << "adicionando serie" << endl;
    cout << serie->getNome() << endl;
    serieController->addSerie(serie);
    cout << "serie adicionada" << endl;
    i++;
  }
  cout << i <<" Series foram extraidas do banco" << endl;
}

void Menu::addSerie() const
{
  cout << "Adicionar Serie" << endl;

  cout << "Nome..........:";
  string nome;
  cin.ignore(); // Clear the newline character left in the buffer
  getline(cin, nome);

  cout << "Ano de Lancamento..........:";
  int anoDeLancamento;
  cin >> anoDeLancamento;

  cout << "Temporada..........:";
  int temporada;
  cin >> temporada;

  cout << "Numero de Episodios..........:";
  int numEpisodios;
  cin >> numEpisodios;

  cin.ignore(); // Clear the newline character left in the buffer

  cout << "Principais Atores..........:";
  string principaisAtores;
  getline(cin, principaisAtores);

  cout << "Personagens Principais..........:";
  string personagensPrincipais;
  getline(cin, personagensPrincipais);

  cout << "Canal..........:";
  string canal;
  getline(cin, canal);

  cout << "Nota..........:";
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
void Menu::AddData() const{
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

  do
  {
    cout << title << endl;

    for (int i = 0; i < menuItems.size(); i++)
    {
      cout << i + 1 << " - " << menuItems[i] << endl;
    }

    cout << "0 - Sair" << endl;
    cin >> option;

    if (option == 0) {
      break;
    }

    (this->*actions.at(option - 1))();
  } while (option != 0);
}
