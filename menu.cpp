#include "menu.h"
#include <QIcon>

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800,460);

    QPushButton *startnewgame = new QPushButton("Новая игра", this);
    startnewgame->resize(120,40);
    startnewgame->move(340,200);
    newgame = new viewExample();
    connect(startnewgame, &QPushButton::clicked, this, &Menu::showNewGameWindow);

    QPushButton *sin = new QPushButton("Выйти", this);
    sin->resize(120,40);
    sin->move(340, 250);
    connect(sin, &QPushButton::clicked, this, &Menu::closeWindow);

}

Menu::~Menu()
{
    delete parent();
}

void Menu::showNewGameWindow()
{
    newgame->show();
}

void Menu::closeWindow()
{
    this->close();
}
