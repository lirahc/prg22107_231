#include "resultwindow.h"

ResultWindow::ResultWindow(QString imagePath, QWidget *parent)
    : QWidget(parent)
{
    _titleLabel = new QLabel("Resultado da Batalha");
    QFont titleFont("Arial", 20, QFont::Bold);
    _titleLabel->setFont(titleFont);
    _titleLabel->setAlignment(Qt::AlignCenter);

    _imageLabel = new QLabel();
    _imageLabel->setPixmap(QPixmap(imagePath));
    _imageLabel->setAlignment(Qt::AlignCenter);

    _layout = new QVBoxLayout();
    _layout->addWidget(_titleLabel);
    _layout->addWidget(_imageLabel);

    setLayout(_layout);
}
