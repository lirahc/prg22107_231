#include "pokegame.h"
#include <cstdlib>
#include <ctime>

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent)
{
    _battleScreen = false;
    createInitialScreen();
    std::srand(std::time(nullptr));
    //connect(_player->getAttack(), &PokeAttack::causeDamage, _enemy, &Pokemon::reduceLife);

}

PokeGame::~PokeGame()
{
}

void PokeGame::createInitialScreen()
{
    _title = new QLabel("Choose your Pokemon:");
    _title->setAlignment(Qt::AlignCenter);

    _pikachuButton = new QPushButton("Pikachu");
    _charmanderButton = new QPushButton("Charmander");
    _squirtleButton = new QPushButton("Squirtle");
    _bulbasaurButton = new QPushButton("Bulbasaur");

    _layout = new QVBoxLayout();
    _layout->addWidget(_title);
    _layout->addWidget(_pikachuButton);
    _layout->addWidget(_charmanderButton);
    _layout->addWidget(_squirtleButton);
    _layout->addWidget(_bulbasaurButton);

    setLayout(_layout);

    connect(_pikachuButton, &QPushButton::clicked, this, &PokeGame::selectPikachu);
    connect(_charmanderButton, &QPushButton::clicked, this, &PokeGame::selectCharmander);
    connect(_squirtleButton, &QPushButton::clicked, this, &PokeGame::selectSquirtle);
    connect(_bulbasaurButton, &QPushButton::clicked, this, &PokeGame::selectBulbasaur);
}

void PokeGame::createBattleScreen()
{
    QStringList availablePokemons = { "Pikachu", "Charmander", "Squirtle", "Bulbasaur" };
    availablePokemons.removeAll(_player->getName());

    int randomIndex = std::rand() % availablePokemons.size();
    QString enemyName = availablePokemons[randomIndex] + " (Enemy)";

    _enemy = new Pokemon("Enemy Pokemon", this);

    _battleLayout = new QHBoxLayout();
    _battleLayout->addWidget(_player);
    _battleLayout->addWidget(_enemy);

    delete _layout;
    _layout = nullptr;

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(_battleLayout);
    setLayout(mainLayout);
}

void PokeGame::startGame()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString pokemonName = button->text();
        _player = new Pokemon(pokemonName, this);
        createBattleScreen();


        // Remover widgets da tela inicial
        _title->deleteLater();
        _pikachuButton->deleteLater();
        _charmanderButton->deleteLater();
        _squirtleButton->deleteLater();
        _bulbasaurButton->deleteLater();

    }
}

void PokeGame::selectPikachu()
{
    startGame();
}

void PokeGame::selectCharmander()
{
    startGame();
}

void PokeGame::selectSquirtle()
{
    startGame();
}

void PokeGame::selectBulbasaur()
{
    startGame();
}



void PokeGame::attack()
{
    // Implement the attack logic here
    // You can update the health of the enemy Pokemon, etc.
}

QString PokeGame::getRandomEnemyPokemon()
{
    QStringList availablePokemons = { "Pikachu", "Charmander", "Squirtle", "Bulbasaur" };
    availablePokemons.removeAll(_player->getName());

    int randomIndex = std::rand() % availablePokemons.size();
    return availablePokemons[randomIndex] + " (Enemy)";
}


