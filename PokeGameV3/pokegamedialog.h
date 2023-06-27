// pokegamedialog.h
#ifndef POKEGAMEDIALOG_H
#define POKEGAMEDIALOG_H

#include <QDialog>
#include "pokegame.h"

class PokeGameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PokeGameDialog(QWidget *parent = nullptr);

private:
    PokeGame* _pokeGame;
};

#endif // POKEGAMEDIALOG_H
