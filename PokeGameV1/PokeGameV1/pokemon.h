#ifndef POKEMON_H
#define POKEMON_H

#include <QWidget>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include "pokeattack.h"

class Pokemon : public QWidget
{
    Q_OBJECT
public:
    explicit Pokemon(QString name, QWidget *parent = nullptr);

    void takeDamage(int damage);

private:
    QLabel* _name;
    QProgressBar* _life;
    QVBoxLayout* _layout;
    PokeAttack* _attack;
};

#endif // POKEMON_H
