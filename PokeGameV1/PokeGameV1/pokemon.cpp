#include "pokemon.h"

Pokemon::Pokemon(QString name, QWidget *parent)
    : QWidget(parent)
{
    _name = new QLabel(name);
    _life = new QProgressBar();
    _life->setRange(0, 100);
    _life->setValue(100);
    _life->setTextVisible(false);

    _attack = new PokeAttack("Soco");

    _layout = new QVBoxLayout();
    _layout->addWidget(_name);
    _layout->addWidget(_life);
    _layout->addWidget(_attack);

    setLayout(_layout);
}

void Pokemon::takeDamage(int damage)
{
    int currentLife = _life->value();
    int newLife = currentLife - damage;
    if (newLife < 0) {
        newLife = 0;
    }
    _life->setValue(newLife);
}
