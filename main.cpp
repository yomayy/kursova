#include "mainwindow.h"
#include <QApplication>
#include "mainwindowtree.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowTree w;
    w.show();

    return a.exec();
}
