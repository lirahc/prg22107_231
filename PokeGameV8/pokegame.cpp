#include "pokegame.h"
#include <cstdlib>
#include <ctime>

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent), _player(nullptr)
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
    /*_title = new QLabel("PokeGame");
    QFont titleFont("Arial", 20, QFont::Bold);
    _title->setFont(titleFont);
    _title->setAlignment(Qt::AlignCenter);*/

    _title = new QLabel("Escolha seu pokémon:");
    QFont subtitleFont("Arial", 10, QFont::DemiBold);
    _title->setFont(subtitleFont);
    _title->setAlignment(Qt::AlignCenter);
    _title->setStyleSheet("color: darkCyan");

    /*_title = new QLabel("Thiago Lira®");
    QFont cosubtitleFont("Arial", 10, QFont::DemiBold);
    _title->setFont(cosubtitleFont);
    _title->setAlignment(Qt::AlignRight);*/

    _pikachuButton = new QPushButton("Pikachu");
    _pikachuButton->setStyleSheet("color: white");
    _pikachuButton->setStyleSheet("background-color: yellow;");
    _charmanderButton = new QPushButton("Charmander");
    _charmanderButton->setStyleSheet("background-color: red;");
    _squirtleButton = new QPushButton("Squirtle");
    _squirtleButton->setStyleSheet("background-color: blue;");
    _bulbasaurButton = new QPushButton("Bulbasaur");
    _bulbasaurButton->setStyleSheet("background-color: green;");

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

    _resultLabel = new QLabel(this); // Adiciona a criação do rótulo
    //_battleLayout->addWidget(_resultLabel); // Adiciona o rótulo ao layout
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

    _attackButton = new QPushButton("Ataque");
    connect(_attackButton, &QPushButton::clicked, this, &PokeGame::handleAttack);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(_battleLayout);
    mainLayout->addWidget(_attackButton);
    setLayout(mainLayout);

    connect(_player->getAttack(), &PokeAttack::causeDamage, _enemy, &Pokemon::reduceLife);

}


void PokeGame::startGame()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString pokemonName = button->text();
        _player = new Pokemon(pokemonName, this);

        //_attackButton = new QPushButton("Ataque"); //comentar n trava
        //connect(_attackButton, &QPushButton::clicked, this, &PokeGame::handleAttack); //comentar n trava
        //connect(_player->getAttack(), &PokeAttack::causeDamage, _enemy, &Pokemon::reduceLife); //comentar n trava

        // Remover widgets da tela inicial
        _title->deleteLater();
        _pikachuButton->deleteLater();
        _charmanderButton->deleteLater();
        _squirtleButton->deleteLater();
        _bulbasaurButton->deleteLater();

        createBattleScreen();
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
    if (_player && _enemy) {
        int playerDamage = std::rand() % 20 + 10; // Random damage between 10 and 29
        _enemy->reduceLife(playerDamage);
        checkBattleResult();

        // Verificar se o inimigo ainda está vivo antes de atacar
        if (_enemy->getLife() > 0) {
            int enemyDamage = std::rand() % 20 + 10; // Random damage between 10 and 29
            _player->reduceLife(enemyDamage);
            checkBattleResult();
        }
    }
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

    if (_player->getLife() <= 0 || _enemy->getLife() <= 0) {
        QTimer::singleShot(3000, this, &PokeGame::resetGame);
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

/*QString PokeGame::getPokemonImagePath(const QString &pokemonName)
{
    if (pokemonName == "Pikachu")
        return ":/images/pikachu.png";
    else if (pokemonName == "Charmander")
        return ":/images/charmander.png";
    else if (pokemonName == "Squirtle")
        return ":/images/squirtle.png";
    else if (pokemonName == "Bulbasaur")
        return ":/images/bulbasaur.png";
    else
        return "";
}*/
