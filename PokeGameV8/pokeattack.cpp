#include "pokeattack.h"

PokeAttack::PokeAttack(QString name, QWidget *parent)
    : QWidget{parent}
{
    _button = new QPushButton(name);

    _layout = new QHBoxLayout();
    _layout->addWidget(_button);

    this->setLayout(_layout);

}
