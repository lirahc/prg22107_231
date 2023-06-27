// pokegamedialog.cpp
#include "pokegamedialog.h"

PokeGameDialog::PokeGameDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Batalha Pokémon");

        _pokeGame = new PokeGame();
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(_pokeGame);
    setLayout(layout);
}
