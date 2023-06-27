#ifndef POKEGAME_H
#define POKEGAME_H

#include <QWidget>
#include <QPushButton>
#include "pokemon.h"

class PokeGame : public QWidget
{
    Q_OBJECT

public:
    PokeGame(QWidget *parent = nullptr);

private:
    Pokemon* _player;
    Pokemon* _enemy;
    QPushButton* _attackButton;

private slots:
    void handleAttack();
};

#endif // POKEGAME_H
