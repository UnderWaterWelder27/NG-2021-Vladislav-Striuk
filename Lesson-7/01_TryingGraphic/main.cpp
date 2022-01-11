#include "simpleapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpleApplication w;
    w.show();
    return a.exec();
}
