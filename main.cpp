#include "menu.h"
#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //menu w;
    viewExample w;

    w.show();
    return a.exec();
}
