#include "pokegame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokeGame w;
    w.show();
    return a.exec();
}
