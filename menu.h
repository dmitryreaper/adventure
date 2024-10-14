#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QMovie>

#include <QPixmap>
#include <QLabel>
#include <QPalette>
#include <QBrush>
#include <QResizeEvent>
#include <QPushButton>
#include "view.h"

class Menu : public QMainWindow {
    Q_OBJECT

public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Menu *window;
    viewExample *newgame;


private slots:
    void showNewGameWindow();
    void closeWindow();
};

#endif
