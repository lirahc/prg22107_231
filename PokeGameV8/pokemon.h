#ifndef POKEMON_H
#define POKEMON_H

#include <QtWidgets>
#include "pokeattack.h"

class Pokemon : public QWidget
{
    Q_OBJECT
public:
    explicit Pokemon(QString name, QWidget *parent = nullptr);
    QString getName() const;

public slots:
    void reduceLife(int intensity);

private:
    QLabel *_name;
    QProgressBar *_life;
    QVBoxLayout *_layout;

    PokeAttack *_attack;
    QString _pokemonName;
};

#endif // POKEMON_H
