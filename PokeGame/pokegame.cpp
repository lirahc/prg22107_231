#include "pokegame.h"

PokeGame::PokeGame(QWidget *parent)
    : QWidget(parent)
{
    _player = new Pokemon("Pikachu");
    _enemy = new Pokemon("Blastoise");

    _layout = new QHBoxLayout();
    _layout->addWidget(_player);
    _layout->addWidget(_enemy);

    this->setLayout(_layout);
}

PokeGame::~PokeGame()
{
}

