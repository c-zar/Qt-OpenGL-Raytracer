#include "QtGui.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.addLibraryPath("C:\Qt\5.12.2\msvc2017\bin");
    QtGui w;
    w.show();
    return a.exec();
}
