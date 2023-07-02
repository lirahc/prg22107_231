#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QtWidgets>

class ResultWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ResultWindow(QString imagePath, QWidget *parent = nullptr);

private:
    QLabel *_titleLabel;
    QLabel *_imageLabel;
    QVBoxLayout *_layout;
};

#endif // RESULTWINDOW_H
