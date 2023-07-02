#include "pokegame.h"
#include <cstdlib>
#include <ctime>

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent)
{
    _battleScreen = false;
    createInitialScreen();
    std::srand(std::time(nullptr));
    //_attackButton = new QPushButton("Atacar");
    //connect(_attackButton, &QPushButton::clicked, this, &PokeGame::handleAttack);
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

    _enemy = new Pokemon(enemyName, this);

    _battleLayout = new QHBoxLayout();
    _battleLayout->addWidget(_player);
    _battleLayout->addWidget(_enemy);

    delete _layout;
    _layout = nullptr;

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(_battleLayout);
    setLayout(mainLayout);

    //connect(_player->getAttack(), &PokeAttack::causeDamage, _enemy, &Pokemon::reduceLife);
}


void PokeGame::startGame()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString pokemonName = button->text();
        _player = new Pokemon(pokemonName, this);
        createBattleScreen();

        connect(_player->getAttack(), &PokeAttack::causeDamage, _enemy, &Pokemon::reduceLife);

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



void PokeGame::handleAttack()
{
    // Simulate player's attack
    int playerDamage = rand() % 20 + 10; // Random damage between 10 and 29
    _enemy->reduceLife(playerDamage);
    checkBattleResult();

    // Simulate enemy's attack
    int enemyDamage = rand() % 20 + 10; // Random damage between 10 and 29
    _player->reduceLife(enemyDamage);
    checkBattleResult();
}

void PokeGame::checkBattleResult()
{
    if (_player->getLife() <= 0 && _enemy->getLife() <= 0) {
        _resultLabel->setText("Empate!");
    } else if (_player->getLife() <= 0) {
        _resultLabel->setText("Inimigo venceu!");
    } else if (_enemy->getLife() <= 0) {
        _resultLabel->setText("Jogador venceu!");
    }
}




void PokeGame::resetGame()
{
    // Limpa a tela e reinicia o jogo para uma nova batalha
    delete _player;
    delete _enemy;
    delete _battleLayout;

    createInitialScreen();
    _battleScreen = false;
}



QString PokeGame::getRandomEnemyPokemon()
{
    QStringList availablePokemons = { "Pikachu", "Charmander", "Squirtle", "Bulbasaur" };
    availablePokemons.removeAll(_player->getName());

    int randomIndex = std::rand() % availablePokemons.size();
    return availablePokemons[randomIndex] + " (Enemy)";
}


