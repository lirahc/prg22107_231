#ifndef POKEGAME_H
#define POKEGAME_H

#include <QtWidgets>
#include "pokemon.h"

class PokeGame : public QWidget
{
    Q_OBJECT

public:
    PokeGame(QWidget *parent = nullptr);
    ~PokeGame();

private slots:
    void createInitialScreen();
    void createBattleScreen();
    void startGame();
    void selectPikachu();
    void selectCharmander();
    void selectSquirtle();
    void selectBulbasaur();
    void attack();

private:
    QVBoxLayout* _layout;
    QLabel* _title;
    QPushButton* _pikachuButton;
    QPushButton* _charmanderButton;
    QPushButton* _squirtleButton;
    QPushButton* _bulbasaurButton;

    Pokemon* _player;
    Pokemon* _enemy;

    QHBoxLayout* _battleLayout;
    QPushButton* _attackButton;
    bool _battleScreen;

    QString getRandomEnemyPokemon();
};


#endif // POKEGAME_H
