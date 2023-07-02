#include "pokeattack.h"
#include <cstdlib>

PokeAttack::PokeAttack(QString name, QWidget *parent)
    : QWidget{parent}
{
    _button = new QPushButton(name);

    _layout = new QHBoxLayout();
    _layout->addWidget(_button);

    this->setLayout(_layout);

}
void PokeAttack::attackEnemy()
{
    emit causeDamage(rand() % 20 + 10);
}


QPushButton* PokeAttack::getButton() const
{
    return _button;
}
