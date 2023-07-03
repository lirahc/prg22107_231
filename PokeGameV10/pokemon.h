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
    int getLife() const;
    PokeAttack* getAttack() const;
    QPushButton* getHealButton() const;

signals:
    void playerAttack(int intensity);

public slots:
    void reduceLife(int intensity);
    void heal();

private:
    QLabel *_name;
    QProgressBar *_life;
    QVBoxLayout *_layout;

    PokeAttack *_attack;
    QString _pokemonName;

    QPushButton* _healButton;
};

#endif // POKEMON_H
