#include "pokegame.h"

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent)
{
    _player = new Pokemon("Pikachu");
    _enemy = new Pokemon("Blastoise");

    _attackButton = new QPushButton("Atacar");
    connect(_attackButton, &QPushButton::clicked, this, &PokeGame::handleAttack);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(_player);
    layout->addWidget(_enemy);
    layout->addWidget(_attackButton);

    setLayout(layout);
}

void PokeGame::handleAttack()
{
    // Simule o ataque do jogador
    int playerDamage = rand() % 20 + 10; // Dano aleatório entre 10 e 29
    _enemy->takeDamage(playerDamage);

    // Simule o ataque do inimigo
    int enemyDamage = rand() % 20 + 10; // Dano aleatório entre 10 e 29
    _player->takeDamage(enemyDamage);
}
