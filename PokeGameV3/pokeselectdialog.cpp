// pokeselectdialog.cpp
#include "pokeselectdialog.h"
#include <cstdlib> // Incluir a biblioteca cstdlib para usar a função rand()
#include <QVBoxLayout> // Incluir o cabeçalho QVBoxLayout

PokeSelectDialog::PokeSelectDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Selecione um Pokémon");

    _pokemonList = new QListWidget();
    _pokemonList->addItem("Pikachu");
    _pokemonList->addItem("Bulbasaur");
    _pokemonList->addItem("Charmander");
    _pokemonList->addItem("Squirtle");

    _selectButton = new QPushButton("Selecionar");
    _selectButton->setEnabled(false);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(_pokemonList);
    layout->addWidget(_selectButton);
    setLayout(layout);

    connect(_pokemonList, &QListWidget::itemClicked, this, &PokeSelectDialog::handlePokemonClicked);
    connect(_selectButton, &QPushButton::clicked, this, [this]() {
        emit pokemonSelected(_pokemonList->currentItem()->text());
    });
}

void PokeSelectDialog::handlePokemonClicked(QListWidgetItem* item)
{
    _selectButton->setEnabled(true);
}
