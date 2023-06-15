#ifndef POKEGAME_H
#define POKEGAME_H

#include <QtWidgets>
#include <pokemon.h>

class PokeGame : public QWidget
{
    Q_OBJECT

public:
    PokeGame(QWidget *parent = nullptr);
    ~PokeGame();

private:
    Pokemon * _player;
    Pokemon * _enemy;

    QHBoxLayout * _layout;


};
#endif // POKEGAME_H
