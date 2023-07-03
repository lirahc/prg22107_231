#include "pokegame.h"
#include "resultwindow.h"
#include <cstdlib>
#include <ctime>
#include <QPixmap>

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent), _player(nullptr)
{
    _battleScreen = false;
    createInitialScreen();
    std::srand(std::time(nullptr));
    //_attackButton = new QPushButton("Atacar");
    //connect(_attackButton, &QPushButton::clicked, this, &PokeGame::handleAttack);
    //connect(_player->getAttack(), &PokeAttack::causeDamage, _enemy, &Pokemon::reduceLife);
    QPixmap _bulbasaurImage;
    QPixmap _squirtleImage;
    QPixmap _pikachuImage;
    QPixmap _charmanderImage;

    _bulbasaurImage.load("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/bulbasaur.png");
    _squirtleImage.load("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/squirtle.png");
    _pikachuImage.load("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/pikachu.png");
    _charmanderImage.load("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/charmander.png");
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

    _title = new QLabel("Escolha seu pokémon inicial! :");
        QFont subtitleFont("Arial", 15, QFont::DemiBold);
    _title->setFont(subtitleFont);
    _title->setAlignment(Qt::AlignCenter);
    _title->setStyleSheet("color: darkCyan");

    /*_title = new QLabel("Thiago Lira®");
    QFont cosubtitleFont("Arial", 10, QFont::DemiBold);
    _title->setFont(cosubtitleFont);
    _title->setAlignment(Qt::AlignRight);*/


    // Pikachu
    _pikachuButton = new QPushButton("PIKACHU", this);
    _pikachuButton->setStyleSheet("color: black; background-color: yellow;");

    QPixmap pikachuImage("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/pikachu.png");
    QPixmap scaledPikachuImage = pikachuImage.scaled(QSize(100, 100));

    _pikachuButton->setIcon(QIcon(scaledPikachuImage));
    _pikachuButton->setIconSize(scaledPikachuImage.size());
    //_pikachuButton->setStyleSheet("QPushButton { border: none; }");


    // Charmander
    _charmanderButton = new QPushButton("CHARMANDER", this);
    _charmanderButton->setStyleSheet("color: black; background-color: red;");

    QPixmap charmanderImage("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/charmander.png");
    QPixmap scaledCharmanderImage = charmanderImage.scaled(QSize(100, 100));

    _charmanderButton->setIcon(QIcon(scaledCharmanderImage));
    _charmanderButton->setIconSize(scaledCharmanderImage.size());
    //_charmanderButton->setStyleSheet("QPushButton { border: none; }");

    // Squirtle
    _squirtleButton = new QPushButton("SQUIRTLE", this);
    _squirtleButton->setStyleSheet("color: black; background-color: blue;");

    QPixmap squirtleImage("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/squirtle.png");
    QPixmap scaledSquirtleImage = squirtleImage.scaled(QSize(100, 100));

    _squirtleButton->setIcon(QIcon(scaledSquirtleImage));
    _squirtleButton->setIconSize(scaledSquirtleImage.size());
    //_squirtleButton->setStyleSheet("QPushButton { border: none; }");

    // Bulbasaur
    _bulbasaurButton = new QPushButton("BULBASAUR");
    _bulbasaurButton->setStyleSheet("color: black; background-color: darkgreen;");

    QPixmap bulbasaurImage("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV10/bulbasaur.png");
    QPixmap scaledBulbasaurImage = bulbasaurImage.scaled(QSize(100, 100));

    _bulbasaurButton->setIcon(QIcon(scaledBulbasaurImage));
    _bulbasaurButton->setIconSize(scaledBulbasaurImage.size());
    //_bulbasaurButton->setStyleSheet("QPushButton { border: none; }");

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
        showResultWindow("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV8/YOU LOSE.png");
    } else if (_enemy->getLife() <= 0) {
        _resultLabel->setText("Jogador venceu!");
        showResultWindow("C:/Users/Thiago Lira/Desktop/workspace_QT/PokeGameV8/YOU WIN.png");
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

/*QString PokeGame::getPokemonImagePath(const QString &pokemonName) //NAO FUNCIONOU
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
void PokeGame::showResultWindow(QString imagePath)
{
    ResultWindow *resultWindow = new ResultWindow(imagePath);
    resultWindow->show();
}
