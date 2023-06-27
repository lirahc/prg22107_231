// pokeselectdialog.h
#ifndef POKESELECTDIALOG_H
#define POKESELECTDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QPushButton>

class PokeSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PokeSelectDialog(QWidget *parent = nullptr);

signals:
    void pokemonSelected(QString name);

private slots:
    void handlePokemonClicked(QListWidgetItem* item);

private:
    QListWidget* _pokemonList;
    QPushButton* _selectButton;
};

#endif // POKESELECTDIALOG_H
