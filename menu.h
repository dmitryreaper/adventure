#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

private:
    Ui::menu *ui;
};
#endif // MENU_H
