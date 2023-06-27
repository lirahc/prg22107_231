/********************************************************************************
** Form generated from reading UI file 'pokegame.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POKEGAME_H
#define UI_POKEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PokeGame
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PokeGame)
    {
        if (PokeGame->objectName().isEmpty())
            PokeGame->setObjectName("PokeGame");
        PokeGame->resize(800, 600);
        centralwidget = new QWidget(PokeGame);
        centralwidget->setObjectName("centralwidget");
        PokeGame->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PokeGame);
        menubar->setObjectName("menubar");
        PokeGame->setMenuBar(menubar);
        statusbar = new QStatusBar(PokeGame);
        statusbar->setObjectName("statusbar");
        PokeGame->setStatusBar(statusbar);

        retranslateUi(PokeGame);

        QMetaObject::connectSlotsByName(PokeGame);
    } // setupUi

    void retranslateUi(QMainWindow *PokeGame)
    {
        PokeGame->setWindowTitle(QCoreApplication::translate("PokeGame", "PokeGame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PokeGame: public Ui_PokeGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POKEGAME_H
