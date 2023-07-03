#include "pokemon.h"
#include <QtCore>

Pokemon::Pokemon(QString name, QWidget *parent)
    : QWidget(parent)
{
    _name = new QLabel(name);
    _life = new QProgressBar();
    _life->setRange(0, 100);
    _life->setValue(100);
    _life->setFormat("%p%");
    _life->setTextVisible(true);


    _attack = new PokeAttack("Ataque");
    connect(_attack, &PokeAttack::causeDamage, this, &Pokemon::reduceLife);

    _healButton = new QPushButton("Curar");
    connect(_healButton, &QPushButton::clicked, this, &Pokemon::heal);

    _layout = new QVBoxLayout();
    _layout->addWidget(_name);
    _layout->addWidget(_life);
    //_layout->addWidget(_attack);
    _layout->addWidget(_healButton);

    setLayout(_layout);
}

void Pokemon::heal()
{
    int currentLife = _life->value();
    int newLife = currentLife + 10;

    // Garantir que a vida não exceda o valor máximo (100)
    newLife = std::min(newLife, 100);

    _life->setValue(newLife);
    _life->setFormat("%p%"); // Atualizar o formato
}

QPushButton* Pokemon::getHealButton() const
{
    return _healButton;
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

    _life->setFormat(QString::number(_life->value()) + "%");
}
