#include <QApplication>
#include "mainmenuwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenuWindow w;
    w.show();
    return a.exec();
}
