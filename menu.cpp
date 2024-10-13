#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    start->show();
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}


