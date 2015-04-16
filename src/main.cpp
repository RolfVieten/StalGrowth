#include "stalbias.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StalBIAS w;
    w.show();

    return a.exec();
}
