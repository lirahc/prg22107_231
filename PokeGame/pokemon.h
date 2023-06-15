#ifndef POKEMON_H
#define POKEMON_H

#include <QtWidgets>
#include "pokeattack.h"

class Pokemon : public QWidget
{
    Q_OBJECT
public:
    explicit Pokemon(QString name, QWidget *parent = nullptr);

signals:

private:
    QLabel *_name;
    QProgressBar *_life;
    QVBoxLayout *_layout;

    PokeAttack *_attack;

};

#endif // POKEMON_H
