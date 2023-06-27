#include <QApplication>
#include "pokegame.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PokeGame pokeGame;
    pokeGame.show();

    return a.exec();
}
