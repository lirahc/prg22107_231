// pokegame.cpp
#include "pokegame.h"
#include <cstdlib> // Incluir a biblioteca cstdlib para usar a função rand()
#include <QVBoxLayout> // Incluir o cabeçalho QVBoxLayout

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent)
{
    _player = new Pokemon("Pikachu");
    _enemy = new Pokemon("Blastoise");

    _attackButton = new QPushButton("Atacar");
    connect(_attackButton, &QPushButton::clicked, this, &PokeGame::handleAttack);

    _resultLabel = new QLabel();

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(_player);
    layout->addWidget(_enemy);
    layout->addWidget(_attackButton);
    layout->addWidget(_resultLabel);

    setLayout(layout);
}

void PokeGame::handleAttack()
{
    // Simulate player's attack
    int playerDamage = rand() % 20 + 10; // Random damage between 10 and 29
    _enemy->takeDamage(playerDamage);
    checkBattleResult();

    // Simulate enemy's attack
    int enemyDamage = rand() % 20 + 10; // Random damage between 10 and 29
    _player->takeDamage(enemyDamage);
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
