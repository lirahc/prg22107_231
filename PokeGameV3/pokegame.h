// pokegame.h
#ifndef POKEGAME_H
#define POKEGAME_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
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
    QLabel* _resultLabel;

private slots:
    void handleAttack();
    void checkBattleResult();
};

#endif // POKEGAME_H
