#include "badlanguagefilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BadLanguageFilter w;
    w.show();
    return a.exec();
}
