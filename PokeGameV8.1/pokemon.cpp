#include "pokemon.h"

Pokemon::Pokemon(QString name, QWidget *parent)
    : QWidget(parent)
{
    _name = new QLabel(name);
    _life = new QProgressBar();
    _life->setRange(0, 100);
    _life->setValue(100);
    _life->setTextVisible(false);

    _attack = new PokeAttack("Ataque");
    connect(_attack, &PokeAttack::causeDamage, this, &Pokemon::reduceLife);

    _layout = new QVBoxLayout();
    _layout->addWidget(_name);
    _layout->addWidget(_life);
    _layout->addWidget(_attack);

    setLayout(_layout);
}

PokeAttack* Pokemon::getAttack() const
{
    return _attack;
}

QString Pokemon::getName() const
{
    return _pokemonName;
}

int Pokemon::getLife() const
{
    return _life->value();
}

void Pokemon::reduceLife(int intensity)
{
    int currentLife = _life->value();
    int newLife = currentLife - intensity;

    // Garantir que a vida não seja menor que 0
    newLife = std::max(newLife, 0);

    _life->setValue(newLife);
}
