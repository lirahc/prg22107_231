// pokeattack.h
#ifndef POKEATTACK_H
#define POKEATTACK_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>

class PokeAttack : public QWidget
{
    Q_OBJECT
public:
    explicit PokeAttack(QString name, QWidget *parent = nullptr);

signals:
    void causeDamage(int intensity);

private:
    QPushButton* _button;
    QHBoxLayout* _layout;
    int _max_value;
    int _min_value;
};

#endif // POKEATTACK_H
